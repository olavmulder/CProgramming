#ifndef UPDATEBLOCK_H
#define UPDATEBLOCK_H

#include "../update.h"

extern  int BLOCK_HEIGHT; 
extern  int BLOCK_WIDTH ;
extern  int ROW ;
extern  int COL ;
void draw_field(Block *blocks);
void blit(SDL_Texture *txtr, int x, int y, int center, int width, int height);

#endif