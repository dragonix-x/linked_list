#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"
#include "../include/list.h"
#include "player.h"


int main(void){
    list_t *list = createList();
    node_t *element = NULL;
    player_t *player = createPlayer("dragonix");

    char *formatedPlayerData = NULL;
    formatedPlayerData = formatPlayer(player, formatedPlayerData);
    printf("%s\n", formatedPlayerData);
    free(formatedPlayerData);

    formatedPlayerData = NULL;
    pushList(&list, createNode(player));

    freeList(&list, freePlayer);
    return 0;
}

