#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include<array>
#include<vector>
#include<random>
#include<memory>
#include<DxLib.h>

constexpr int window_w = 1280;
constexpr int window_h = 720;
constexpr int square_size = 16;
constexpr int window_square_w = window_w / square_size;
constexpr int window_square_h = window_h / square_size;

class LifeGame
{
	private:
		std::array < std::array< std::shared_ptr<int>, window_square_w>, window_square_h> field;
		LifeGame() {
			using namespace std;
			random_device rd;
			mt19937 eng(rd());
			bernoulli_distribution uid(0.3 );
			for (int y = 0; y < window_square_h; y++)
				for (int x = 0; x < window_square_w; x++) {
					field[y][x].reset(new int);
					*field[y][x] = uid(eng) ? 1 : 0;
				}
		}
	public:
		int check(const int y,const int x);
		void evolution();
};


#endif // !LIFE_GAME_H



