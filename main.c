#include "main.h"


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init(&ball, &mouse, &vaus, &block);
	SDL_Delay(5000);
	while (1)
	{
	
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		process_input(&ball, &mouse, &vaus);
		
		update(&ball, &block, &vaus);
		
		SDL_RenderPresent(renderer);

		SDL_Delay(16);
    }

    return 0;
}
