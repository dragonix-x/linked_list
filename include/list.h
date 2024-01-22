#ifndef __LIST__
#define __LIST__
#include "node.h"

typedef struct list_t{
    int count;
    node_t *start;
    node_t *end;
}list_t;

list_t *create_list(void);
node_t *getListNode(list_t *list, int index);

void free_list(list_t **list, void * (*free_item_fn)(void * item));
void print_list(list_t *list, void (*print_item_fn)(void * item));

void push_list(list_t **list, node_t *node);
void pop_list(list_t **list, void * (*free_item_fn)(void * item));

void unshift_list(list_t **list, node_t *node);
void shift_list(list_t **list, void * (*free_item_fn)(void * item));

void remove_list_node(list_t **list, int index, int count, void * (*free_item_fn)(void * item));
void extend_list(list_t **destination, list_t *source);

#endif
