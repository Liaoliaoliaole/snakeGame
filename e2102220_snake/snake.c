#include<stdio.h>
#include<conio.h>
#include"snake.h"
#include"screen.h"


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

void draw(struct snake s) {
	clearScreen();
	setBackground(GREEN);
	gotoXY(s.head.x, s.head.y);
	printf(" ");
	setBackground(CYAN);
	for (int i = 0; i < s.length; i++) {
		gotoXY(s.body[i].x, s.body[i].y);
		printf(" ");
	}
	resetColors();
}

//this funvtion returns one of the four arrow key values
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
}