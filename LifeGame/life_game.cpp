#include "life_game.h"

int LifeGame::check(const int y, const int x) {
	int cnt = 0;
	for(int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++) {
			if (xx == x && yy == y) continue;
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
void LifeGame::draw() {
	for (int y = 0; y < window_square_h; y++)
		for (int x = 0; x < window_square_w; x++) {
			unsigned int cr = GetColor(0, 0, 0);
			switch (field[y][x])
			{
			case 1:
				cr = GetColor(255, 255, 255);
				break;
			case 0:
				cr = GetColor(0, 0, 0);
				break;
			default:
				break;
			}
			DrawBox(x * square_size, y * square_size, (x + 1) * square_size, (y + 1) * square_size, cr, TRUE);

		}
}