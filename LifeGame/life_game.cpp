#include "life_game.h"

int LifeGame::check(const int y, const int x) {
	int cnt = 0;
	for(int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++) {
			if (xx < 0 || xx >= window_square_w || yy < 0 || yy >= window_square_h) continue;
			cnt += *field[yy][xx];
		}
	return cnt;
}
void LifeGame::evolution() {

}