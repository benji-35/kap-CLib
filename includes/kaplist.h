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
        void *key;
        void *data;
        struct map_node_s *next;
        struct map_node_s *prev;
        struct map_node_s *head;

        void (*print)(void *data);
        bool (*equal)(void *data1, void *data2);
        void (*destroy)(void *data);
    } map_node_t;

    typedef struct map_s {
        int size;
        map_node_t *head;
        map_node_t *tail;
    } map_t;

    #endif

#endif /* !KAPLIST_H_ */
