/*
** KAP PROJECT, 2023
** C Lib
** File description:
** kaplist
*/

#ifndef KAPLIST_H_
    #define KAPLIST_H_

    #include "kaptools.h"

    typedef struct node_s {
        void *data;
        struct node_s *next;
        struct node_s *prev;
        struct node_s *head;

        void (*print)(void *data);
        bool (*equal)(void *data1, void *data2);
    } node_t;

    #define foreach(list, node) for (node_t *node = list->head; node; node = node->next)

    #ifndef KAPCHAINEDLIST_H_
        #define KAPCHAINEDLIST_H_

        typedef struct list_s {
            int size;
            node_t *head;
            node_t *tail;
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


#endif /* !KAPLIST_H_ */
