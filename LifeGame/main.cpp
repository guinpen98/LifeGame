#include "main.h"

bool Update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

void Main() {
	LifeGame life_game;
	while (Update()) {
		for (int i = 0; i < 5000; i++) {
			life_game.draw();
		}
		life_game.evolution();
	}
}