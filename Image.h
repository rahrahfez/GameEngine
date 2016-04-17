#ifndef IMAGE_H
#define IMAGE_H
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"

class Image {
private:
	SDL_Surface* surface;
	int m_width;
	int m_height;
	int m_frameWidth;
	int m_frameHeight;
public:
	Image();
	~Image();
	bool load(char fileName[]);
	bool load(char fileName[], int a_frameWidth, int a_frameHeight);
	void draw(int x, int y, Graphics* g);
	void draw(int x, int y, int frame, Graphics* g);
	void free();

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getFrameWidth() { return m_frameWidth; }
	int getFrameHeight() { return m_frameHeight; }
	void setFrameSize(int w, int h);
	bool isLoaded();
};
#endif