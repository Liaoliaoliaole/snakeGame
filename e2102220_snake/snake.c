#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"snake.h"
#include"screen.h"

bool is_dead;

//initial the snake in the center, body left,return snake
struct snake init_snake(int len) {
	struct snake local_s;
	local_s.head.y = INITROW;
	local_s.head.x = INITCOL;
	local_s.length = len;
	for (int i = 0; i < len; i++) {
		local_s.body[i].y = INITROW;
		local_s.body[i].x = INITCOL - 1 - i;
	}
	return local_s;
}

bool is_empty_coord(struct snake s, struct coord loc) {
	if (s.head.x == loc.x && s.head.y == loc.y)  return false;
	for (int i = 0; i < s.length - 1; i++) {
		if (s.body[i].x == loc.x && s.body[i].y == loc.y) return false;
	}
	return true;
}

struct coord get_empty_coord(struct snake s,struct coord loc) {
	struct coord emptyLoc;
	int scanX_start = loc.x;
	int scanX_end = loc.x;
	int scanY_start = loc.y;
	int scanY_end = loc.y;
	if (s.length == MAX_X * MAX_Y) is_dead = true;
	while (1) {
		scanX_start--;
		scanX_end++;
		scanY_start--;
		scanY_end++;
		if (scanX_start < 0) scanX_start = 0;
		if (scanY_start < 0) scanY_start = 0;
		if (scanX_end > MAX_X) scanX_end = MAX_X;
		if (scanY_end > MAX_Y) scanY_end = MAX_Y;
		for (int x = scanX_start; x <= scanX_end; x++) {
			for (int y = scanY_start; y <= scanY_end; y++) {
				emptyLoc.x = x; emptyLoc.y = y;
				if (is_empty_coord(s,emptyLoc) == true) {
					return emptyLoc;
				}
			}
		}
	}
}

struct coord creat_food(struct snake s) {
	struct coord food;
	food.x = rand() % MAX_X;
	food.y = rand() % MAX_Y;
	bool isEmpty = false;
	if (is_empty_coord(s,food) == false) {
		food = get_empty_coord(s,food);
	}
	return food;
}

void horizon_wall() {
	printf("|");
	for (int i = 1; i < MAX_X - 1; i++) {
		printf("-");
	}
	printf("|");
}

//show playground+snake+food dynamicly
void draw(struct snake s, struct coord food) {
	int ground[MAX_Y][MAX_X];
	clearScreen();
	setForeground(RED);
	gotoXY(1, 1);
	horizon_wall();
	printf("\n");
	////draw snake
	//setBackground(GREEN);
	//gotoXY(s.head.x, s.head.y);
	//printf("  ");
	//setBackground(CYAN);
	//for (int i = 0; i < s.length; i++) {
	//	gotoXY(s.body[i].x, s.body[i].y);
	//	printf("  ");
	//}
	//resetColors();
	for (int i = 1; i <= MAX_Y; i++) {
		for (int j = 1; j <= MAX_X; j++) {
			if (j == 1) {
				printf("|");
				continue;
			}
			if (i == s.head.y && j == s.head.x) {
				setBackground(GREEN);
				gotoXY(s.head.x, s.head.y);
				printf(" ");
				resetColors();
				continue;
			}
			bool isEmpty = true;
			if (i== food.y  && j== food.x) {
				printf("F"); 
				isEmpty = false; 
				continue;
			}
			if (j == MAX_X) {
				setForeground(RED);
				printf("|");
				continue;
			}
			for (int l = 0; l < s.length; l++) {
				if (i == s.body[l].y && (j == s.body[l].x)) {
					setBackground(CYAN);
					gotoXY(s.body[l].x, s.body[l].y);
					printf(" ");
					isEmpty = false;
				}
				resetColors();
			}
			if (isEmpty == true) {
				printf(" ");
			}
		}
		printf("\n");
	}
	setForeground(RED);
	gotoXY(1, MAX_Y);
	horizon_wall();
	resetColors();	
}

//this function returns one of the four arrow key values
int get_key() {
	//while (1) {
	//	int kv = _getch();//non echo
	//	printf("%d", kv);
	//}//use this function in debug mode to find arrow key value
	//up72,down75,left77,right80,note that 224 meANS erro key, continue to read
	while (1) {
		int kv = _getch();
		if (kv == 224) {
			kv = _getch();
			if (kv == UP || kv == DOWN || kv == LEFT || kv == RIGHT) {
				return kv;
			}
		}
	}
}

struct snake move(struct snake s, int k) {
	struct snake ns;
	ns.head = s.head;
	ns.length = s.length;
	if (k == UP) {
		ns.head.y--;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
	if (k == DOWN) {
		ns.head.y++;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
	if (k == LEFT) {
		ns.head.x--;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
	if (k == RIGHT) {
		ns.head.x++;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
}

bool is_hit_wall(struct snake s) {	
	if (s.head.x >= MAX_X || s.head.x <= 1 || s.head.y >= MAX_Y || s.head.y <= 1) {
		is_dead = true;
	}
	if (is_dead == true) {
		return true;
	}
	else {
		return false;
	}
}

bool is_hit_self(struct snake s) {
	for (int i = 0; i < s.length - 1; i++) {
		if ((s.head.x == s.body[i].x) && (s.head.y == s.body[i].y)) {
			is_dead = true; 
		}
	}
	if (is_dead == true) {
		return true;
	}
	else {
		return false;
	}
}