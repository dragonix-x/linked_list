#ifndef __NODE__
#define __NODE__

typedef struct Node{
    void *item;
    struct Node *next;
    struct Node *prev;
}node_t;

node_t *create_node(void *item);
node_t *free_node(node_t *node, void * (*free_item_fn)(void * item));
void print_node(node_t *node, void (*print_item_fn)(void * item));

#endif
