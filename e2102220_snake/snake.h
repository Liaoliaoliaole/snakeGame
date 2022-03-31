#pragma once
#include<stdio.h>
//constant definition
#define MAXLEN 50
#define INITLEN 5
enum COORD { INITROW = 13,INITCOL=40};
enum ARROWS{UP=72,DOWN=80,LEFT=75,RIGHT=77};
 

//structure definition
struct coord {
	int x, y;
};

struct snake {
	struct coord head;
	struct coord body[MAXLEN];
	int length;
};

//function declarations
struct snake init_snake(int len);//initial the snake in the center, body left,return snake
void draw(struct snake s);
int get_key();
struct snake move(struct snake, int);