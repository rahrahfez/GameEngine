#include "Graphics.h"

bool Graphics::init(int a_width, int a_height, bool a_fullscreen) {
	int width = a_width;
	int height = a_height;

	if (a_fullscreen) {
		m_backbuffer = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
	}
	else {
		m_backbuffer = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
	}
	if (m_backbuffer == NULL) {
		printf("Failed to initialize graphics!\n");
		return false;
	}
	return true;
}

void Graphics::clear(int r, int g, int b) {
	if (m_backbuffer == NULL) {
		return;
	}
	Uint32 color;
	color = SDL_MapRGB(m_backbuffer->format, r, g, b);
	SDL_FillRect(m_backbuffer, NULL, color);
}

void Graphics::flip() {
	SDL_Flip(m_backbuffer);
}

void Graphics::drawPixel(int x, int y, int r, int g, int b) {
	if (m_backbuffer == NULL) {
		return;
	}
	if (SDL_MUSTLOCK(m_backbuffer)) {
		if (SDL_LockSurface(m_backbuffer) < 0) {
			return;
		}
	}
	if (x >= m_backbuffer->w || x < 0 || y >= m_backbuffer->h || y < 0) {
		return;
	}

	Uint32* buffer;
	Uint32 color;

	color = SDL_MapRGB(m_backbuffer->format, r, g, b);
	buffer = (Uint32*)m_backbuffer->pixels + y * m_backbuffer->pitch / 4 + x;
	*buffer = color;
	if (SDL_MUSTLOCK(m_backbuffer)) {
		SDL_UnlockSurface(m_backbuffer);
	}
}

void Graphics::drawRect(int x, int y, int width, int height, int r, int g, int b) {
	fillRect(x, y, width, 1, r, g, b);
	fillRect(x, y + height - 1, width, 1, r, g, b);
	fillRect(x, y, 1, height, r, g, b);
	fillRect(x + width - 1, y, 1, height, r, g, b);
}

void Graphics::fillRect(int x, int y, int width, int height, int r, int g, int b) {
	if (m_backbuffer == NULL) {
		return;
	}
	Uint32 color;
	color = SDL_MapRGB(m_backbuffer->format, r, g, b);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_FillRect(m_backbuffer, &rect, color);
}
