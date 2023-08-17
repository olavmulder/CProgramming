#include "block.h"

void generate_field(Block *block, int level){
	int amount_powerups;
	int max_level = 10;
	if(max_level * 5 > COL*ROW){
		amount_powerups = COL*ROW;
	}else{
		amount_powerups = level *5;
	}
	srand((unsigned int)time(NULL));  
	int color_int;
	int pow_indicate[amount_powerups];
	for(int i=0;i<amount_powerups;i++){
		pow_indicate[i] = rand()%ROW*COL;
	}
    

	for(int i=0; i< ROW;i++){
        for(int j=0; j< COL;j++){
            
			for(int k=0;k<amount_powerups; k++){
				if(pow_indicate[k] == ROW*i + j){
					int nr = rand()%total_powerups;
					init_power_up(block, i,j,nr);
				}
			}
			
            block->blocks[i][j].posX = j*BLOCK_WIDTH;
            block->blocks[i][j].posY = i*BLOCK_HEIGHT;
            block->blocks[i][j].state = true;
            color_int = rand()%4;
				switch(color_int){
					case 0:
						block->blocks[i][j].block_texture = load_texture("init/images/blue.png");
						break;
					case 1:
						block->blocks[i][j].block_texture = load_texture("init/images/green.png");
						break;
					case 2:
						block->blocks[i][j].block_texture = load_texture("init/images/red.png");
						break;
					case 3:
						block->blocks[i][j].block_texture = load_texture("init/images/yellow.png");
						break;
					default:
						break;
					
				}
		
			blit(block->blocks[i][j].block_texture, block->blocks[i][j].posX, block->blocks[i][j].posY, 0, BLOCK_WIDTH, BLOCK_HEIGHT);
			
		}
    }
	
}

void init_power_up(Block *block, int i, int j, int pownr){
	block->blocks[i][j].powerup[pownr] = true;
}