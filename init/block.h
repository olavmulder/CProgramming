#ifndef INITBLOCK_H
#define INITBLOCK_H

#include "../init.h"
#include <time.h>
int total_powerups =  5;
const int BLOCK_HEIGHT   =  36;
const int BLOCK_WIDTH    =  128;

const int ROW = 8;
const int COL = 8;
int total_blocks = ROW * COL;



void generate_field(Block *block, int level);
static void init_power_up(Block *block, int i, int j, int pwrnr);
void blit(SDL_Texture *txtr, int x, int y, int center, int width, int height);


#endif