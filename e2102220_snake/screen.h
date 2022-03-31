#pragma once
enum COLORS { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

void resetColors(void);
void setBackground(int);
void clearScreen();
//void setForeground(int color);
void gotoXY(int row, int col);