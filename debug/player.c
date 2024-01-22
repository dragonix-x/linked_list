#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

player_t *createPlayer(const char *pseudo){
    player_t *player = (player_t *) malloc(sizeof(player_t));
    player->level = 80;
    player->pseudo = calloc(strlen(pseudo), sizeof(char) + 1);
    strcpy(player->pseudo, pseudo);
    return player;
}
/* 
* function that free the custom element created
* params: ptr-> a void pointer to the custom item created(need to be casted later in the function)
*/
void *freePlayer(void *ptr){
    player_t *player = (player_t *)ptr;
    free(player->pseudo);
    player->pseudo = NULL;
    free(player);
    player = NULL;
    return player;
}

void printPlayer(void *ptr){
    player_t *player = (player_t *)ptr;
    printf("Pseudo: %s\nLevel: %d\n", player->pseudo, player->level);
}

char *formatPlayer(void *ptr, char *formatedData){
    player_t *player = (player_t *)ptr;
    char buffer[255];
    int res = 0;
    res = sprintf(buffer, "pseudo:%s,level:%d", player->pseudo, player->level);
    if(res < 0){
        fprintf(stderr, "Error while writting data representation into the buffer");
        exit(EXIT_FAILURE);
    }
    res++;
    formatedData = malloc(res * sizeof(char));
    if(formatedData == NULL){
        fprintf(stderr, "Memory allocation error");
        exit(EXIT_FAILURE);
    }
    strcpy(formatedData, buffer);
    *(formatedData + res-1) = '\0';
    return formatedData;

}
