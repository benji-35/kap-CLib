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

    #ifndef KAPCHAINEDLIST_H_
        #define KAPCHAINEDLIST_H_

        typedef struct list_s {
            ksize_t size;
            list_node_t *head;
            list_node_t *tail;
        } list_t;

        
        #define foreach_l(list, node) for (list_node_t *node = list->head; node; node = node->next)

        #ifndef KAPCHAINEDLIST_FUNC_H
            #define KAPCHAINEDLIST_FUNC_H

            /**
             * @brief Create a list
            */
            extern list_t *list_create(void);
            /**
             * @brief Destroy a list
             * @param list The list to destroy
             * @param destroy The function to destroy the data in the list only if the data has a destroy function
            */
            extern void list_destroy(list_t *list);

            /**
             * @brief Push an element in the list
             * @param list The list to push in
             * @param data The data to push
            */
            extern list_node_t *list_push(list_t *list, void *data);
            /**
             * @brief Push an element in the front of the list
             * @param list The list to push in
            */
            extern list_node_t *list_push_front(list_t *list, void *data);
            /**
             * @brief Insert an element in the list
             * @param list The list to insert in
             * @param data The data to insert
             * @param index The index to insert the data
            */
            extern list_node_t *list_insert(list_t *list, void *data, ksize_t index);

            /**
             * @brief Pop an element in the list
             * @param list The list to pop in
             * @note The data will be destroyed if the data has a destroy function
            */
            extern void list_pop(list_t *list);
            /**
             * @brief Pop an element in the front of the list
             * @param list The list to pop in
             * @note The data will be destroyed if the data has a destroy function
            */
            extern void list_pop_front(list_t *list);
            /**
             * @brief Remove an element in the list
             * @param list The list to remove in
             * @param index The index to remove
             * @note The data will be destroyed if the data has a destroy function
            */
            extern void list_remove(list_t *list, ksize_t index);
            /**
             * @brief Remove an element in the list from the data equality
             * @param list The list to remove in
             * @param data The data to remove
            */
            extern void list_remove_data(list_t *list, void *data);
            /**
             * @brief Clear the list
             * @param list The list to clear
            */
            extern void list_clear(list_t *list);

            /**
             * @brief Get the data of the element at the index
            */
            extern void *list_get(const list_t *list, ksize_t index);
            /**
             * @brief Get the first element of the list
            */
            extern void *list_get_first(const list_t *list);
            /**
             * @brief Get the last element of the list
            */
            extern void *list_get_last(const list_t *list);

            /**
             * @brief Get the size of the list
             * @param list The list to get the size
            */
            extern ksize_t list_size(const list_t *list);
            /**
             * @brief Check if the list is empty
             * @param list The list to check
            */
            extern bool list_is_empty(const list_t *list);
            /**
             * @brief reverse the list
             * @param list The list to reverse
            */
            extern void list_reverse(list_t *list);
            /**
             * @brief Sort the list
             * @param list The list to sort
             * @param compare The compare function
            */
            extern void list_sort(list_t *list, int (*cmp)(const void *, const void *));

            /**
             * @brief Concatenate two lists
             * @param list1 The first list
             * @param list2 The second list
             * @return list_t* The new list with the two lists concatenated
             * @note a new list is created
            */
           extern list_t *list_concat(const list_t *list1, const list_t *list2);
            /**
             * @brief Add a list to another list
             * @param list1 The first list
             * @param list2 The second list
             * @note the second list is added to the first list
            */
           extern void list_add_list(list_t *list1, const list_t *list2);

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

        #define foreach_m(map, node) for (map_node_t *node = map->head; node; node = node->next)

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
             * @note data is not destroyed unless you define a function to destroy the data
            */
            extern void map_destroy(map_t *map);
            /**
             * @brief Insert a new element in the map
             * @param map map to insert in
             * @param key key of the element
             * @param data data of the element
             * @param can_overwrite if the key already exists, can we overwrite it ?
             * @note if the key already exists and can_overwrite is false, the element is not inserted
             * @note if data is overwritten, the old data is destroyed only if you define a function to destroy the data
            */
            extern map_node_t *map_insert(map_t *map, const char *key, void *data, bool can_overwrite);
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
             * @note the data is destroyed only if you define a function to destroy the data
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
            /**
             * @brief create a map from two lists
             * @param keys list of keys (only strings keys are supported)
             * @param values list of values
             * @return map_t* the new map
            */
           extern map_t *map_create_from_lists(list_t *keys, list_t *values);

            #define map_add(map, key, data, can_overwrite) map_insert(map, key, data, can_overwrite)
        #endif

    #endif

#endif /* !KAPLIST_H_ */
