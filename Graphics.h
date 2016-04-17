#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>

class Graphics {
private:
	SDL_Surface* m_backbuffer;
	int m_width;
	int m_height;
public:
	bool init(int a_width, int a_height, bool a_fullscreen);
	void drawPixel(int x, int y, int r, int g, int b);
	void drawRect(int x, int y, int width, int height, int r, int g, int b);
	void fillRect(int x, int y, int width, int height, int r, int g, int b);
	void clear(int r, int g, int b);
	void flip();
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	SDL_Surface* getBackbuffer() { return m_backbuffer; }
};

#endif