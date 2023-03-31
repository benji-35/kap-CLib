/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kapparser
*/

#ifndef KAPPARSER_H_
    #define KAPPARSER_H_

    #include "kapstring.h"
    #include "kaplist.h"

    typedef enum config_type_e {
        YAML,
        JSON,
        XML,
        INI,
        TOML,
        CONFIG_TYPE_MAX
    } config_type_t;

    typedef struct config_s {
        config_type_t type;
        void *file;
    } config_file_t;

    typedef config_file_t config_f;

    /**
     * @brief Open config file
     * @param path path to config file
     * @return config file
     * @note This function will open the config file
    */
    extern config_f *config_open(cstring path);
    /**
     * @brief Close config file
     * @param config config file
     * @note This function will save the config file
    */
    extern void config_save(config_f *config);
    /**
     * @brief Close config file
     * @param config config file
     * @note This function will close the config file
    */
    extern void config_close(config_f *config);

    #ifndef KAP_YAML
        #define KAP_YAML

        typedef enum yml_content_data {
            YML_STRING,
            YML_LIST,
            YML_OBJECT,
            YML_CONTENT_DATA_MAX
        } yml_content_data_t;

        typedef struct yaml_node_s {
            string key;
            void *value;
            list_t *children;
            struct yaml_node_s *parent;
            ksize_t line;
            yml_content_data_t type;
            bool modified;
            bool destroyed;
        } yaml_node_t;

        typedef struct yaml_file_s {
            string path;
            list_t *yaml;
            text_t file_content;
            ksize_t line_read;
            yaml_node_t *last_added;
        } yaml_file_t;

        typedef yaml_file_t yaml_f;

        /**
         * @brief Open yaml file
         * @param path path to yaml file
         * @return yaml file
         * @note This function will open the yaml file
         * @note Do not forget to close the file with yaml_close
        */
        extern yaml_f *yaml_open(cstring path);
        /**
         * @brief Close yaml file
         * @param yaml_file yaml file
         * @note This function will not save the yaml file before closing it
        */
        extern void yaml_close(yaml_f *yaml_file);
        /**
         * @brief Save yaml file
         * @param yaml_file yaml file
         * @note This function will save the yaml file
        */
        extern void yaml_save(yaml_f *yaml_file);

        /**
         * @brief Set value to yaml file
         * @param yaml_file yaml file
         * @param key key to set
         * @param value value to set
         * @note This function will set the value to the key
        */
        extern void yaml_set(yaml_f *file, cstring key, cstring value);
        /**
         * @brief Set list to yaml file
         * @param yaml_file yaml file
         * @param key key to set
         * @param value list to set
         * @note This function will set the list to the key
        */
        extern void yaml_set_list(yaml_f *file, cstring key, list_t *value);
    
        /**
         * @brief Get an object from yaml file
         * @param yaml_file yaml file
         * @param key key to get
         * @return object
         * @note This function will get the object from the key
        */
        extern void *yaml_get_object(yaml_f *yaml_file, cstring key);
        /**
         * @brief Get a string from yaml file
         * @param yaml_file yaml file
         * @param key key to get
        */
        extern string yaml_get(yaml_f *yaml_file, cstring key);
        /**
         * @brief Get a list from yaml file
         * @param yaml_file yaml file
         * @param key key to get
         * @return list
        */
        extern list_t *yaml_get_list(yaml_f *file, cstring key);


        //yaml tools
        extern yaml_node_t *yaml_parser(yaml_f *, cstring key);
        extern yaml_node_t *yaml_key_exists(yaml_node_t *node, cstring key, string before);
        extern yaml_node_t *yaml_key_exists_file(yaml_f *file, cstring key);
        extern yaml_node_t *yaml_find_first_node(yaml_f *file, cstring key);
        extern void yaml_destroy_node(void *data);
        extern void destroy_yml_data_node(yaml_node_t *yml_node);

        /**
         * @brief Convert config file to yaml file
         * @param config config file
         * @return yaml file
        */
        #define YALM_FROM_CONFIG(config) ({ yaml_f *yaml = NULL; if (config->type == YAML) {yaml = config->file; } yaml; })
        /**
         * @brief Convert config file to yaml file
         * @param config config file
         * @return yaml file
        */
        #define YML_FROM_CONFIG(config) YALM_FROM_CONFIG(config)
        /**
         * @brief Convert config file to yaml file
         * @param config config file
         * @return yaml file
        */
        #define CONFIG_TO_YAML(config) YALM_FROM_CONFIG(config)
        /**
         * @brief Convert config file to yaml file
         * @param config config file
         * @return yaml file
        */
        #define CONFIG_TO_YML(config) YALM_FROM_CONFIG(config)

        /**
         * @brief Check if yaml file failed to load
         * @param yaml_f yaml file
         * @return true if yaml file failed to load
        */
        #define YAML_FAILED(yaml_f) ({ bool failed = false; if (yaml_f == NULL || yaml_f->file_content == NULL) { failed = true; } failed; })

    #endif

    #ifndef KAP_XML
        #define KAP_XML

        typedef struct xml_file_s xml_file_t;
        typedef struct xml_node_s xml_node_t;

        struct xml_node_s {
            string tag_name;
            string content;
            list_t *children;
            map_t *attributes;
            xml_node_t *parent;
            xml_file_t *file;
            bool destroyed;
        };

        struct xml_file_s {
            string path;
            list_t *xml;
            text_t file_content;
            string version;
            string encoding;
        };

        typedef xml_file_t xml_f;
        typedef list_t xml_node_list;
        typedef xml_node_list node_list;

        /**
         * @brief Open xml file
         * @param path path to xml file
         * @return xml file
         * @note This function will open the xml file
         * @note Do not forget to close the xml file
        */
        extern xml_f *xml_open(cstring path);
        /**
         * @brief Close xml file
         * @param xml xml file
         * @note This function will close the xml file
        */
        extern void xml_close(xml_f *xml_file);
        /**
         * @brief Save xml file
         * @param xml xml file
         * @note This function will save the xml file
        */
        extern void xml_save(xml_f *xml);

        /**
         * @brief Get xml element by tag (name of the element)
         * @param xml_file xml file
         * @param tag tag of the element
         * @return list of xml nodes
         * @note This function will return a list of xml nodes
         * @note Do not forget to destroy the list
        */
        extern list_t *xml_get_element_tag(xml_f *xml_file, cstring tag);
        /**
         * @brief Get xml element by attribute
         * @param xml_file xml file
         * @param attribute attribute of the element
         * @param value value of the attribute (can be NULL to get all elements with the attribute)
         * @return list of xml nodes
         * @note This function will return a list of xml nodes
         * @note Do not forget to destroy the list
        */
        extern list_t *xml_get_element_attribute(xml_f *xml_file, cstring attribute, cstring value);
        /**
         * @brief Get xml element by tag from xml node
         * @param xml_node xml node
         * @param tag tag of the element
         * @return list of xml nodes
         * @note This function will return a list of xml nodes
        */
        extern list_t *xml_get_element_tag_from_node(xml_node_t *xml_node, cstring tag);
        /**
         * @brief Get xml element by attributes from xml node
         * @param xml_node xml node
         * @param attribute attribute of the element
         * @param value value of the attribute (can be NULL to get all elements with the attribute)
         * @return list of xml nodes
        */
        extern list_t *xml_get_element_attribute_from_node(xml_node_t *xml_node, cstring attribute, cstring value);

        /**
         * @brief add element to xml file
         * @param xml_file xml file
         * @param tag tag of the element
         * @param content content of the element
         * @param attributes attributes of the element
         * @note This function will add an element to the xml file
        */
        extern void xml_add_element(xml_f *xml_file, cstring tag, cstring content, map_t *attributes);
        /**
         * @brief add element to xml node
         * @param xml_node xml node
         * @param tag tag of the element
         * @param content content of the element
         * @param attributes attributes of the element
         * @note This function will add an element to the xml node
        */
        extern void xml_add_element_to_node(xml_node_t *xml_node, cstring tag, cstring content, map_t *attributes);
        /**
         * @brief delete element from xml file
         * @param xml_file xml file
         * @param tag tag of the element
         * @param content content of the element
         * @param attributes attributes of the element
         * @note This function will delete an element from the xml file
        */
        extern void xml_delete_element(xml_f *xml_file, cstring tag, cstring content, map_t *attributes);
        /**
         * @brief delete element from xml node
         * @param xml_node xml node
         * @param tag tag of the element
         * @param content content of the element
         * @param attributes attributes of the element
         * @note This function will delete an element from the xml node
        */
        extern void xml_delete_element_node(xml_node_t *nd, cstring tag, cstring content, map_t *attributes);

        //tools
        extern void xml_node_destroy(void *data);
        extern void xml_parse(xml_f *xml_file);

        /**
         * @brief Convert config file to xml file
         * @param config config file
         * @return xml file
        */
        #define XML_FROM_CONFIG(config) ({ xml_f *xml = NULL; if (config->type == XML) {xml = config->file; } xml; })
        /**
         * @brief Convert config file to xml file
         * @param config config file
         * @return xml file
        */
        #define CONFIG_TO_XML(config) XML_FROM_CONFIG(config)

        /**
         * @brief Check if xml file failed to load
         * @param xml_f xml file
         * @return true if xml file failed to load
        */
        #define XML_FAILED(xml_f) ({ bool failed = false; if (xml_f == NULL || xml_f->file_content == NULL || xml_f->encoding == NULL || xml_f->version == NULL) { failed = true; } failed; })

    #endif

#endif /* !KAPPARSER_H_ */
