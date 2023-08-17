#ifndef INIT_H
#define INIT_H
#include "main.h"


void init(Ball *ball, Mouse *mouse, Vaus *vaus, Block *block);
void blit(SDL_Texture *txtr, int x, int y, int center, int w, int h);
SDL_Texture *load_texture(char *filename);

void init_vaus(Vaus *vaus);
void init_ball(Ball *ball, Mouse *mouse, Vaus *vaus);

void generate_field(Block *block, int level);
Ball ball;
Vaus vaus;
Mouse mouse;
Block block;
#endif