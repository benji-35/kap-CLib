/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kaplist
*/

#ifndef KAPLIST_H_
    #define KAPLIST_H_

    #include "kaptools.h"
    #include "kapmemory.h"

    typedef struct list_node_s {
        void *data;
        struct list_node_s *next;
        struct list_node_s *prev;
        struct list_node_s *head;

        void (*print)(void *data);
        bool (*equal)(void *data1, void *data2);
        void (*destroy)(void *data);
    } list_node_t;

    #define foreach(list, node) for (list_node_t *node = list->head; node; node = node->next)

    #ifndef KAPCHAINEDLIST_H_
        #define KAPCHAINEDLIST_H_

        typedef struct list_s {
            int size;
            list_node_t *head;
            list_node_t *tail;
        } list_t;

        #ifndef KAPCHAINEDLIST_FUNC_H
            #define KAPCHAINEDLIST_FUNC_H

            /**
             * @brief Create a list
            */
            list_t *list_create(void);
            /**
             * @brief Destroy a list
             * @param list The list to destroy
            */
            void list_destroy(list_t *list);

            /**
             * @brief Push an element in the list
             * @param list The list to push in
             * @param data The data to push
            */
            list_node_t *list_push(list_t *list, void *data);
            /**
             * @brief Push an element in the front of the list
             * @param list The list to push in
            */
            list_node_t *list_push_front(list_t *list, void *data);
            /**
             * @brief Insert an element in the list
             * @param list The list to insert in
             * @param data The data to insert
             * @param index The index to insert the data
            */
            list_node_t *list_insert(list_t *list, void *data, int index);

            /**
             * @brief Pop an element in the list
             * @param list The list to pop in
            */
            void list_pop(list_t *list);
            /**
             * @brief Pop an element in the front of the list
             * @param list The list to pop in
            */
            void list_pop_front(list_t *list);
            /**
             * @brief Remove an element in the list
             * @param list The list to remove in
            */
            void list_remove(list_t *list, int index);
            /**
             * @brief Remove an element in the list from the data equality
             * @param list The list to remove in
             * @param data The data to remove
            */
            void list_remove_data(list_t *list, void *data);
            /**
             * @brief Clear the list
             * @param list The list to clear
            */
            void list_clear(list_t *list);

            /**
             * @brief Print the list
            */
            void list_print(const list_t *list);
            /**
             * @brief Get the data of the element at the index
            */
            void *list_get(const list_t *list, int index);
            /**
             * @brief Get the first element of the list
            */
            void *list_get_first(const list_t *list);
            /**
             * @brief Get the last element of the list
            */
            void *list_get_last(const list_t *list);

        #endif /* !KAPCHAINEDLIST_FUNC_H */

    #endif

    #ifndef KAPMAPLIST_H_
        #define KAPMAPLIST_H_

        typedef struct map_node_s {
            char *key;
            void *data;
            struct map_node_s *next;
            struct map_node_s *prev;
            struct map_node_s *head;

            void (*print)(void *data);
            bool (*equal)(void *data1, void *data2);
            void (*destroy)(void *data);
        } map_node_t;

        typedef struct map_s {
            map_node_t *head;
            map_node_t *tail;
        } map_t;

        #ifndef KAPMAPLIST_FUNC_H
            #define KAPMAPLIST_FUNC_H

            /**
             * @brief Create a map object
             * @return map_t*
            */
            extern map_t *map_create(void);
            /**
             * @brief Destroy the map object
             * @param map map to destroy
            */
            extern void map_destroy(map_t *map);
            /**
             * @brief Insert a new element in the map
             * @param map map to insert in
             * @param key key of the element
             * @param data data of the element
             * @param can_overwrite if the key already exists, can we overwrite it ?
            */
            extern void map_insert(map_t *map, const char *key, void *data, bool can_overwrite);
            /**
             * @brief Get the data of the element with the key
             * @param map map to get from
             * @param key key of the element
             * @return void* data of the element
            */
            extern void *map_get(map_t *map, const char *key);
            /**
             * @brief Check if the key exists in the map
             * @param map map to check in
             * @param key key to check
             * @return true if the key exists
            */
            extern bool map_key_exists(map_t *map, const char *key);
            /**
             * @brief Remove the element with the key
             * @param map map to remove from
             * @param key key of the element
            */
            extern void map_remove(map_t *map, const char *key);
            /**
             * @brief Clear the map
             * @param map map to clear
            */
            extern void map_clear(map_t *map);
            /**
             * @brief Print the map
             * @param map map to print
            */
            extern void map_print(map_t *map);
            /**
             * @brief Get map size
            */
            extern ksize_t map_size(map_t *map);
            /**
             * @brief Get the key of the element at the index
            */
            extern char *map_get_key(map_t *map, ksize_t index);

            #define map_add(map, key, data, can_overwrite) map_insert(map, key, data, can_overwrite)
        #endif

    #endif

#endif /* !KAPLIST_H_ */
