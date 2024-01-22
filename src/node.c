#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"

node_t *create_node(void *item){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if(node == NULL){
        fprintf(stderr, "Error while dynamically allocating space\n");
        exit(EXIT_FAILURE);
    }
    node->item = item;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

node_t *free_node(node_t *node, void * (*free_item_fn)(void * item)){
    free_item_fn(node->item);
    node->item = NULL;
    free(node);
    node = NULL;
    return node;
}

void print_node(node_t *node, void (*print_item_fn)(void * item)){
    print_item_fn(node->item);
    return;
}

