#ifndef INPUT_H
#define INPUT_H

#include "main.h"

void process_input(Ball *ball, Mouse *mouse, Vaus *vaus);
void proper_shutdown(void);
extern void init_ball(Ball *ball, Mouse *mouse, Vaus *vaus);
extern Ball ball;
extern Vaus vaus;
extern Mouse mouse;

#endif