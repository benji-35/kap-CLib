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
        } yaml_file_t;

        #define yaml_f yaml_file_t

        extern yaml_f *yaml_open(cstring path);
        extern void yaml_close(yaml_f *yaml_file);
        extern void yaml_set(yaml_f *yaml_file, cstring key, cstring value);
        extern void yaml_save(yaml_f *yaml_file);

        extern string yaml_get(yaml_f *yaml_file, cstring key);
        extern list_t *yaml_get_list(yaml_f *file, cstring key);

        extern void yaml_set(yaml_f *file, cstring key, cstring value);
        extern void yaml_set_list(yaml_f *file, cstring key, list_t *value);

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

        typedef struct xml_balise_s {
            string name;
            map_t *attributes;
        } xml_balise_t;

        typedef struct xml_node_s {
            string name;
            map_t *attributes;
            list_t *children;
            string content;
        } xml_node_t;

        typedef struct xml_file_s {
            string path;
            list_t *xml;
            text_t file_content;
            string version;
            string encoding;
        } xml_file_t;
        #define xml_f xml_file_t

        extern xml_f *xml_open(cstring path);
        extern void xml_close(xml_f *xml_file);
        extern void xml_save(xml_f *xml_file);

        extern void xml_add_string(xml_f *xml_file, cstring path, cstring value);
        extern void xml_add_list(xml_f *xml_file, cstring path, list_t *value);
        extern void xml_add_attribute(xml_f *xml_file, cstring path, cstring attribute, cstring value);

        extern string xml_get_string(xml_f *xml_file, cstring path);
        extern list_t *xml_get_list(xml_f *xml_file, cstring path);
        extern map_t *xml_get_attributes(xml_f *xml_file, cstring path);
        extern string xml_get_attribute(xml_f *xml_file, cstring path, cstring attribute);
        extern string xml_get_string_from_lang(xml_f *xml_file, cstring path, cstring lang);

        //tools
        extern list_t *xml_parse(xml_f *xml);
        extern void destroy_xml_node(void *data);
        extern void xml_print_node(void *data);

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
        #define XML_FAILED(xml_f) ({ bool failed = false; if (xml_f == NULL || xml_f->file_content == NULL) { failed = true; } failed; })

    #endif

#endif /* !KAPPARSER_H_ */
