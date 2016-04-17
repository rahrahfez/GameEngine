#include "Image.h"

Image::Image() {
	surface = NULL;
	m_width = 0;
	m_height = 0;
	m_frameWidth = 0;
	m_frameHeight = 0;
}

Image::~Image() {

}

bool Image::load(char fileName[]) {
	SDL_Surface* imageLoaded = NULL;
	imageLoaded = IMG_Load(fileName);
	if (imageLoaded != NULL) {
		surface = SDL_DisplayFormat(imageLoaded);
		SDL_FreeSurface(imageLoaded);
		if (surface != NULL) {
			Uint32 colorKey = SDL_MapRGB(surface->format, 0xFF, 0, 0xFF);
			SDL_SetColorKey(surface, SDL_SRCCOLORKEY, colorKey);
			m_width = surface->w;
			m_height = surface->h;
		}
		else {
			printf("Failed to load image: ");
			printf(fileName);
			printf("\n");
			return false;
		}
	}
	else {
		printf("Failed to load image: ");
		printf(fileName);
		printf("\n");
		return false;
	}
	return true;
}

bool Image::load(char fileName[], int a_frameWidth, int a_frameHeight) {
	if (load(fileName)) {
		m_frameWidth = a_frameWidth;
		m_frameHeight = a_frameHeight;
		return true;
	}
	return false;
}

void Image::free() {
	if (surface != NULL) {
		SDL_FreeSurface(surface);
		surface = NULL;
	}
}

void Image::draw(int x, int y, Graphics* g) {
	if (surface == NULL) {
		return;
	}
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	SDL_BlitSurface(surface, NULL, g->getBackbuffer(), &destRect);
}

void Image::draw(int x, int y, int frame, Graphics* g) {
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	int columns = m_width / m_frameWidth;
	SDL_Rect sourceRect;
	sourceRect.y = (frame / columns) * m_frameHeight;
	sourceRect.x = (frame % columns) * m_frameWidth;
	sourceRect.w = m_frameWidth;
	sourceRect.h = m_frameHeight;

	SDL_BlitSurface(surface, &sourceRect, g->getBackbuffer(), &destRect);
}

void Image::setFrameSize(int w, int h) {
	m_frameWidth = w;
	m_frameHeight = h;
}

bool Image::isLoaded() {
	return (surface != NULL);
}