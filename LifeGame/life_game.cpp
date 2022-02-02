#include "life_game.h"

int LifeGame::check(const int y, const int x) {
	int cnt = 0;
	for(int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++) {
			if (xx < 0 || xx >= window_square_w || yy < 0 || yy >= window_square_h) continue;
			cnt += field[yy][xx];
		}
	return cnt;
}
void LifeGame::evolution() {
	std::array < std::array<int, window_square_w>, window_square_h> next_field;
	for (int y = 0; y < window_square_h; y++)
		for (int x = 0; x < window_square_w; x++) {
			int n = check(y, x);
			int s = field[y][x];
			if (s == 0) {
				if (n == 3) next_field[y][x] = 1;
				else next_field[y][x] = 0;
			}
			else {
				if(n<=1||n>=4)next_field[y][x] = 0;
				else next_field[y][x] = 1;
			}
		}
	field = next_field;
}