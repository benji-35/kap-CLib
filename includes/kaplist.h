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

            list_t *list_create(void);
            void list_destroy(list_t *list);
            void list_push(list_t *list, void *data);
            void list_push_front(list_t *list, void *data);
            void list_pop(list_t *list);
            void list_pop_front(list_t *list);
            void list_insert(list_t *list, void *data, int index);
            void list_remove(list_t *list, int index);
            void list_remove_data(list_t *list, void *data);
            void list_clear(list_t *list);
            void list_print(list_t *list);

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
        #endif

    #endif

#endif /* !KAPLIST_H_ */
