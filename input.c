#include "input.h"
void process_input(Ball *ball, Mouse *mouse, Vaus *vaus)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				proper_shutdown();
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						exit(0);
						break;	
					case SDL_SCANCODE_R:
						init_ball(ball, mouse, vaus);
						
						break;	
					default:
						break;
				}
				break;
			default:
				break;
		}
		SDL_GetMouseState(&mouse->x, &mouse->y);
		vaus->posX = mouse->x;
	}

}
void proper_shutdown(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}