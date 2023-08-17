#include "collision.h"
const char *title[]={"Arkanoid 		remaining lifes: 0", "Arkanoid 		remaining lifes: 1", "Arkanoid 		remaining lifes: 2", "Arkanoid 		remaining lifes: 3"} ;
void detection(Ball *ball, Block *block, Vaus *vaus){	
	SDL_SetWindowTitle(window, title[score]);  
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(block->blocks[i][j].state){
				
				if(ball->posX+(float)ball->width/2 >= block->blocks[i][j].posX && ball->posX-(float)ball->width/2 <= block->blocks[i][j].posX+BLOCK_WIDTH){
					if(ball->posY+(float)ball->height/2 >= block->blocks[i][j].posY && ball->posY-(float)ball->height/2 <= block->blocks[i][j].posY+BLOCK_HEIGHT){
                        block->blocks[i][j].state = false;
						
						float ball_max_x = ball->posX + (float)ball->width/2;
						float ball_max_y = ball->posY + (float)ball->height/2;
						float ball_min_x = ball->posX - (float)ball->width/2;
						float ball_min_y = ball->posY - (float)ball->height/2;
						//right
						if((ball_max_x > block->blocks[i][j].posX+BLOCK_WIDTH && ball_min_x < block->blocks[i][j].posX+BLOCK_WIDTH) &&
							(ball_min_y > block->blocks[i][j].posY || ball_max_y > block->blocks[i][j].posY+BLOCK_HEIGHT)){
							ball->posX = (float)block->blocks[i][j].posX + (float)BLOCK_WIDTH + (float)ball->width/2;
							ResponseBall(ball,2);
                           
							
						}
						//left 
						if((ball_max_x > block->blocks[i][j].posX && ball_min_x < block->blocks[i][j].posX) &&
							(ball_min_y < block->blocks[i][j].posY || ball_max_y > block->blocks[i][j].posY+BLOCK_HEIGHT)){
							ball->posX = (float)block->blocks[i][j].posX - (float)ball->width/2;
                            ResponseBall(ball,0);
							
                           
                          
						}
						//bottom
						if((ball_min_y < block->blocks[i][j].posY+BLOCK_HEIGHT && ball_max_y > block->blocks[i][j].posY+BLOCK_HEIGHT) 
							&& (ball_min_x > block->blocks[i][j].posX && ball_max_x < block->blocks[i][j].posX+BLOCK_WIDTH)){
								ball->posY = (float)block->blocks[i][j].posY+ (float)BLOCK_HEIGHT + (float)ball->height/2;
								ResponseBall(ball,3);
                               
						}
						//top
						if((ball_min_y < block->blocks[i][j].posY && ball_max_y > block->blocks[i][j].posY) 
							&& (ball_min_x > block->blocks[i][j].posX && ball_max_x < block->blocks[i][j].posX+BLOCK_WIDTH)){
								ball->posY = (float)block->blocks[i][j].posY - (float)ball->height/2;
                                ResponseBall(ball, 1);
                             
                                
						}


						for(int k=0; k<total_powerups;k++){
							if(block->blocks[i][j].powerup[k] == true){
								powerup(vaus, ball, k);
								printf("powerup nr %d\n", k);
								printf("ball speed %f\nvaus width = %d\n", ball->speed, vaus->width);
							}
						}
						check_next_level(ball, vaus, block);
						
					}
				}
			}
		}
	}
	
	if(ball->posX > SCREEN_WIDTH-ball->width/2){
	
		ResponseBall(ball, 0);
	}

	if(ball->posX < ball->width/2){
	
		ResponseBall(ball, 2);
							
	}
	if(ball->posY < ball->height/2){
		
		ResponseBall(ball, 3);
	}
	if(ball->posY-(float)ball->height > vaus->posY + vaus->height){
		//game over
		score --;
		printf("%d lifes left...\n", score);
		ball->posY = (float)vaus->posY - (float)ball->height/2;
		ball->posX = (float)vaus->posX;
		blit(ball->ball_texture, (int)ball->posX, (int)ball->posY, 1, ball->width, ball->height);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000);
		ball->dirX = -1;
		ball->dirY = -1;
		CalculateDirection(ball, ball->dirX, ball->dirY);
		if(score == 0){
			printf("Game over\n");
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(0);
		}
	}
    VausCollision(ball, vaus);
    


}

void ResponseBall(Ball *ball, int side){
	
	float x = 1;
    float y = 1;
    if (ball->dirX > 0) { 			//ball naar rechts
        if (ball->dirY > 0) {		//ball rechts omlaag = boven of links rakken
            if (side == 0) {		//links dus naar links = -1
                x = -1;
            } else {				//boven dus omhoog = -1
                y = -1;
            }
        } else if (ball->dirY < 0) {//ball rechts omhoog
           
            if (side == 0) {		//links
                x = -1;
            } else {				//onder 
                y = -1;
            }
        }
    } else if (ball->dirX < 0) {	//ball naar links
       
        if (ball->dirY > 0) {		//ball naar links onder = boven en rechts 
            
            if (side == 2) {		//boven, dus x -1 = omhoog
                x = -1;
            } else {
                y = -1;				//rechts dus y de andere kant op = -1
            }
        } else if (ball->dirY < 0) {//ball naar links boven = rechts onder
            if (side == 1) {		//rechts dus x de andere kant op = -1
                x = -1;
            } else {				// onder dus y de andere kant op = -1
                y = -1;
            }
        }
    }
	
	CalculateDirection(ball, x *ball->dirX, y*ball->dirY);
}
void VausCollision(Ball *ball, Vaus *vaus){

    if(vaus->posX <= ball->posX+(float)ball->width/2 && vaus->posX+vaus->width >= ball->posX-(float)ball->width/2){
       
       if (vaus->posY <= ball->posY+ (float)ball->height/2 && 
            ball->posY < vaus->height + vaus->posY)
       {
                float vaus_hit_x = ball->posX - (float)vaus->posX ;
                vaus_hit_x -= (float)vaus->width/2;
                vaus_hit_x = 2.0f *(vaus_hit_x/((float)vaus->width/2.0f));
                CalculateDirection(ball,vaus_hit_x, -1);
                ball->posY = (float)vaus->posY - (float)ball->height/2;
        }
    }
}


