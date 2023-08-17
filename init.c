#include  "init.h"
void init(Ball *ball, Mouse *mouse, Vaus *vaus, Block *block){
	unsigned int window_flags = 0;
	unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;
	IMG_Init(IMG_INIT_PNG);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
		window_flags);
	if (window == NULL)
	{
		printf("Failed to create window -- Error: %s\n",
			SDL_GetError());
		exit(1);
	}
	
	renderer = SDL_CreateRenderer(window, -1, renderer_flags );//| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) // error handling:
	{
		printf("Failed to create renderer -- Error: %s\n",
		SDL_GetError());
		exit(1);
	}
	SDL_ShowCursor(SDL_DISABLE);
    init_vaus(vaus);
	init_ball(ball, mouse, vaus);
	generate_field(block, 1);
}

SDL_Texture *load_texture(char *filename)
{
	SDL_Texture *txtr;
	txtr = IMG_LoadTexture(renderer, filename);
	return txtr;
}
