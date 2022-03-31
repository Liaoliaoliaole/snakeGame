#include "screen.h"
#include<stdio.h>

void resetColors(void) {
	printf("\033[0m");
	fflush(stdout);
}

void setForeground(int color) {
	printf("\033[%dm", color);
	fflush(stdout);
}

void setBackground(int color) {
	printf("\033[1;%dm", color + 10);
	fflush(stdout);
}

void clearScreen(void) {
	printf("\033[2J");
	fflush(stdout);
}

void gotoXY(int x, int y) {
	printf("\033[%d;%dH", y, x);
	fflush(stdout);
}

//void boarder()
//{
//	clearScreen();
//	gotoXY(1, 1);
//	horizon_wall();
//	for (int y = 0; y < MAX_Y; y++) {
//		printf("|");
//		/*for (int i = 1; i < MAX_X+1; i++) {
//			printf(" ");
//		}*/
//		gotoXY(MAX_X+2,y);
//		printf("|\n");
//	}
//	horizon_wall();
//}

