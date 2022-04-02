#pragma once
#include<stdio.h>
//constant definition
#define MAXLEN 50
#define INITLEN 6
#define MAX_X 79
#define MAX_Y 19
enum COORD { INITROW = 10,INITCOL=40};
enum ARROWS{UP=72,DOWN=80,LEFT=75,RIGHT=77};
enum boolEnum { false, true };
 

//structure definition
typedef enum boolEnum bool;

struct coord {
	int x, y;
};

struct snake {
	struct coord head;
	struct coord body[MAXLEN];
	int length;
};

//function declarations
void horizon_wall();
struct snake init_snake(int len);
void draw(struct snake , struct coord);
int get_key();
struct snake move(struct snake, int,struct coord);
bool is_empty_coord(struct snake s, struct coord loc);
struct coord get_empty_coord(struct snake s, struct coord loc);
struct coord creat_food(struct snake s);
bool is_hit_wall(struct snake s);
bool is_hit_self(struct snake s);
struct snake snake_grow(struct snake s);