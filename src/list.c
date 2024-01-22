#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/node.h"
#include "../include/utils.h"

list_t *create_list(void){
    list_t *list = (list_t *)malloc(sizeof(list_t));
    if(list == NULL)
        memory_allocation_error_exit();
    list->count = 0;
    list->start = NULL;
    list->end = NULL;
    return list;
}


void push_list(list_t **list, node_t *node){
    if((*list)->count == 0)
        (*list)->start = node;
    else{
        node->prev = (*list)->end;
        (*list)->end->next = node;
    }
    (*list)->end = node;
    (*list)->count ++;
}

void pop_list(list_t **list, void * (*free_item_fn)(void * item)){
    remove_list_node(list, ((*list)->count - 1), 1, free_item_fn);
}

void unshift_list(list_t **list, node_t *node){
    if((*list)->count == 0)
        (*list)->end = node;
    else{
        node->next = (*list)->start;
        (*list)->start->prev = node;
    }
    (*list)->start = node;

    (*list)->count ++;
}

void shift_list(list_t **list, void * (*freeItemFn)(void * item)){
    remove_list_node(list, 0, 1, freeItemFn);
}

/*-------------------------------------------------------------------------------------*/
node_t *get_list_node(list_t *list, int index){
    node_t *node = NULL;
    if(index > list->count - 1)
        return node;
    //printf("index: %d | count: %d | division: %d\n", index, list->count, list->count/2);
    if(index < list->count/2){
        node = list->start;
        for(int i = 0; i < index; i++)
            node = node->next;
    }
    else{
        node = list->end;
        for(int i = 0; i < list->count - (index + 1); i++)
            node = node->prev;
    }
    return node;
}

/* list_t *insert(list_t *list, int index, element_t *element){
    element_t *currentElement = getElement(list, index);

    return list;
} */

void remove_list_node(list_t **list, int index, int count, void * (*freeItemFn)(void * item)){
    if(count == 0 || count > (*list)->count)
        return;
    else{
        node_t *node = get_list_node(*list, index);

        //Check if the element is the start or the end of the list
        if(node->prev == NULL || node->next == NULL){
            if(node->prev == NULL){
                (*list)->start = node->next;
                (*list)->start->prev = NULL;
            }
            //if(element->next == NULL){
            else{
                (*list)->end = node->prev;
                (*list)->end->next = NULL;
            }
        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        free_node(node, freeItemFn);
        (*list)->count--;
        count--;
        index--;
        //recursivite
        //removeElement(list, index, count, freeItemFn);
    }
}

/* list_t *concat(list_t *source1, list_t *source2 ){
    source1->end->next = source2->start;
} */

void extend_list(list_t **destination, list_t *source ){
    (*destination)->end->next = source->start;
    return;
}

void free_list(list_t **list, void * (*free_item_fn)(void * item) ){
    node_t *current_node = (*list)->start;
    node_t *next_node = NULL;

    while(current_node != NULL){
        next_node = current_node->next;
        free_node(current_node, free_item_fn);
        current_node = next_node;
        (*list)->count--;
    }
    free(*list);
    (*list) = NULL;
    return;
}

void print_list(list_t *list, void(*print_item_fn)(void * item) ){
    node_t *current_node = list->start;
    node_t *next_node = NULL;

    while(current_node != NULL){
        next_node = current_node->next;
        print_node(current_node, print_item_fn);
        current_node = next_node;
    }
    return;
}

