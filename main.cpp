/*
	Fullscreen mode : (0,0) - (84,24)
*/
#include <iostream>
#include "CPirate.hpp"
#include "CScene.hpp"
using namespace eestl;

int main(int argc, char** args) {
	CScene* game = new CScene{ GetStdHandle(STD_OUTPUT_HANDLE),
		0x01, NULL, new CPirate{{5,7}}
	};
	game->GameLoop();

	delete game;

	return 0;
}