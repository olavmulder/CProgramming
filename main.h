#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#define SCREEN_WIDTH   1024
#define SCREEN_HEIGHT  576 


SDL_Window *window;
SDL_Renderer *renderer;
typedef struct _ball_{
	float posX, posY;
	float speed;
	int height, width;
	SDL_Texture *ball_texture;
	float dirX, dirY, time;
}Ball;
typedef struct _mouse_ {
	int x;
	int y;
} Mouse;
typedef struct _Vaus_{
    int height, width;
	int posY, posX;
}Vaus;
typedef struct _Block_{
    int posX,posY;
    bool state;
	bool powerup[5];
    SDL_Texture *block_texture;

}B;
typedef struct __{
	B blocks[8][8];
}Block;

extern Block block;
extern Ball  ball;
extern Vaus  vaus;
extern Mouse mouse;

void process_input(Ball *ball, Mouse *mouse, Vaus *vaus);
void update(Ball *ball, Block *block, Vaus *vaus);
void init(Ball *ball, Mouse *mouse, Vaus *vaus, Block *block);

#endif