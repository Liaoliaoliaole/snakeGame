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

void horizon_wall() {
	printf("|");
	for (int i = 1; i < MAX_X - 1; i++) {
		printf("-");
	}
	printf("|");
}

void draw(struct snake s) {
	int ground[MAX_Y][MAX_X];
	clearScreen();
	setForeground(RED);
	gotoXY(0, 0);
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
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			if (j == 0) {
				printf("|");
				continue;
			}
			if (i == s.head.y && j == s.head.x) {
				setBackground(GREEN);
				gotoXY(s.head.x, s.head.y);
				printf("  ");
				resetColors();
				continue;
			}
			if (j == MAX_X - 1) {
				setForeground(RED);
				printf("|");
				continue;
			}
			bool isEmpty = true;
			for (int l = 0; l < s.length; l++) {
				if (i == s.body[l].y && (j == s.body[l].x)) {
					setBackground(CYAN);
					gotoXY(s.body[l].x, s.body[l].y);
					printf("  ");
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
	gotoXY(0, MAX_Y);
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
		ns.head.x-=2;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
	if (k == RIGHT) {
		ns.head.x+=2;
		ns.body[0] = s.head;
		for (int i = 1; i < s.length; i++) {
			ns.body[i] = s.body[i - 1];
		}
		return ns;
	}
	
}