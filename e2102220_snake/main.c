#include"screen.h"
#include"snake.h"

struct snake s;



int main() {
	s = init_snake(INITLEN);
    struct coord randomFood;
	randomFood = creat_food(s);
	
	while (1) {
		
		draw(s, randomFood);
		int k=get_key();
		s = move(s, k);
		is_hit_wall(s);
		is_hit_self(s);
	
		
	}

	return 0;
}