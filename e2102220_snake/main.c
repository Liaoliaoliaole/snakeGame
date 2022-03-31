
#include"snake.h"

int main() {
	struct snake s = init_snake(INITLEN);
	while (1) {
		draw(s);
		int k=get_key();
		s = move(s, k);
		//break;
		//key function will be done later;
		//move function will be done later;
	}

	return 0;
}