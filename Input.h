#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>

class Input {
private:
	bool* m_keys;
	bool* m_prevKeys;

	bool m_mouseKeys[3];
	bool m_prevMouseKeys[3];

	int m_numKeys;
	int m_mouseX;
	int m_mouseY;
public:
	static const int MOUSE_LEFT = 1;
	static const int MOUSE_MIDDLE = 2;
	static const int MOUSE_RIGHT = 3;

	void init();
	void kill();

	void update();

	bool keyDown(int key);
	bool keyHit(int key);
	bool keyUp(int key);

	bool mouseDown(int key);
	bool mouseHit(int key);
	bool mouseUp(int key);

	int getMouseX();
	int getMouseY();

	void setMousePos(int x, int y);
	void hideCursor(bool hide = true);
};

#endif