#include "life_game.h"

int LifeGame::check(const int y, const int x) {
	int cnt = 0;
	std::vector < std::vector<int>> tbl = { {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0} };
	for (auto& t : tbl) {
		int xx = x + t[0];
		int yy = y + t[1];
		if (xx < 0) xx = window_square_w - 1;
		if (xx >= window_square_w) xx = 0;
		if (yy < 0) yy = window_square_h - 1;
		if (yy >= window_square_h) yy = 0;
		if (*field[yy][xx] == 1) cnt++;
	}
	return cnt;
}
void LifeGame::evolution() {

}