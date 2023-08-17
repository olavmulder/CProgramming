CC=gcc -std=c99   # CC is originele UNIX C compiler
LD=gcc -std=c99   # LD is originele UNIX C linker
CFLAGS= -Wall -Wextra -Wconversion -Wpedantic  # Compiler flags
EFLAGS = `sdl2-config --cflags --libs` -lSDL2_image -lm

OBJS1 = init/ball.o init/vaus.o init/block.o 
OBJS2 = update/ball.o update/block.o update/vaus.o update/collision.o update/powerup.o
OBJS = main.o init.o  input.o update.o 
program :  $(OBJS) $(OBJS1) $(OBJS2)
	$(LD) -o program  $(OBJS) $(OBJS1) $(OBJS2) $(EFLAGS)
main.o : main.c main.h
	$(CC) $(CFLAGS) -c main.c $(EFLAGS)
init.o : init.c init.h
	$(CC) $(CFLAGS) -c init.c $(EFLAGS)
input.o : input.c input.h
	$(CC) $(CFLAGS) -c input.c $(EFLAGS)
update.o : update.c update.h
	$(CC) $(CFLAGS) -c update.c $(EFLAGS)

/init/ball.o : init/ball.c init/ball.h
	$(CC) $(CFLAGS) -c init/ball.c $(EFLAGS)
/init/vaus.o : init/vaus.c init/vaus.h
	$(CC) $(CFLAGS) -c init/vaus.c $(EFLAGS)
/init/block.o : init/block.c init/vaus.h
	$(CC) $(CFLAGS) -c init/block.c $(EFLAGS)
	
/update/ball.o : update/ball.c update/ball.h
	$(CC) $(CFLAGS) -c update/ball.c $(EFLAGS)
/update/block.o : update/block.c update/block.h
	$(CC) $(CFLAGS) -c update/block.c $(EFLAGS)
/update/vaus.o : update/vaus.c update/vaus.h
	$(CC) $(CFLAGS) -c update/vaus.c $(EFLAGS)
/update/collision.o :	update/collision.c update/collision.h
	$(CC) $(CFLAGS) -c update/collision.c $(EFLAGS)
/update/powerup.o :	update/powerup.c update/powerup.h
	$(CC) $(CFLAGS) -c update/powerup.c $(EFLAGS)
clean: 
	$(RM) program *.o init/*.o update/*.o *~