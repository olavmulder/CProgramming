#ifndef UPDATE_H
#define UPDATE_H

#include "main.h"
#include <math.h>
extern Ball ball;
extern Vaus vaus;
extern Mouse mouse;
extern Block block;

void update(Ball *ball, Block *block, Vaus *vaus);
void blit(SDL_Texture *txtr, int x, int y, int center, int width, int height);

void draw_ball(Ball *ball);
void CalculateDirection(Ball *ball, float newdirx, float newdiry);

void draw_vaus(Vaus *vaus);
void draw_field(Block *block);

void detection(Ball *ball, Block *block, Vaus *vaus);


void generate_field(Block *block, int level);

void check_next_level(Ball *ball, Vaus *vaus, Block *block);

extern const int total_blocks;

#endif