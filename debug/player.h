#ifndef __PLAYER__
#define __PLAYER__

typedef struct player_t{
    char *pseudo;
    int level;
}player_t;

void *freePlayer(void *player);
player_t *createPlayer(const char *pseudo);
void printPlayer(void *ptr);
char *formatPlayer(void *ptr, char *formatedData);

#endif
