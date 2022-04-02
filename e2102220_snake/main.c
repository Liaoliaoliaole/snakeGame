#define _CRT_SECURE_NO_WARNINGS
#include"screen.h"
#include"snake.h"
#ifdef WINDOWS
#include<windows.h>
#endif

struct snake s;

int main() {
#ifdef WINDOWS
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(h, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(h, mode);
#endif
	struct coord randomFood;
	s = init_snake(INITLEN);
	randomFood = creat_food(s);
	
	while(1) {
		draw(s, randomFood);
		int k = get_key();
		if ((s.head.x == randomFood.x) && (s.head.y == randomFood.y)) {
			s =  snake_grow(s);
			randomFood = creat_food(s);
		}
		if (is_hit_wall(s) == true || is_hit_self(s) == true) {
			return;
		}
		s = move(s, k,randomFood);
	}
	return 0;
}