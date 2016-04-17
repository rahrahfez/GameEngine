#include "SceneDemo.h"

int main(int argc, char* argv[]) {
	SceneDemo game;

	if (!game.init()) {
		game.free();
		return 1;
	}
	while (game.init()) {
		game.run();
	}
	game.free();
	return 0;
}
