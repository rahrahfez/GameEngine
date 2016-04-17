#include "Input.h"

void Input::init() {
	Uint8* keyboard = SDL_GetKeyState(&m_numKeys);
	m_keys = new bool[m_numKeys];
	m_prevKeys = new bool[m_numKeys];

	for (int i = 0; i < m_numKeys; i++) {
		m_keys[i] = keyboard[i];
		m_prevKeys[i] = false;
	}
	SDL_GetMouseState(&m_mouseX, &m_mouseY);

	for (int i = 1; i <= 3; i++) {
		m_mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
		m_prevMouseKeys[i] = false;
	}
}

void Input::update() {
	Uint8* keyboard = SDL_GetKeyState(&m_numKeys);
	for (int i = 0; i < m_numKeys; i++) {
		m_prevKeys[i] = m_keys[i];
		m_keys[i] = keyboard[i];
	}
	SDL_GetMouseState(&m_mouseX, &m_mouseY);
	for (int i = 1; i <= 3; i++) {
		m_prevMouseKeys[i] = m_mouseKeys[i];
		m_mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
	}
}

void Input::kill() {
	delete[]m_keys;
	delete[]m_prevKeys;
}

bool Input::mouseDown(int key) {
	if (key < 0 || key > 3) {
		return false;
	}
	return m_mouseKeys[key];
}

bool Input::mouseHit(int key) {
	if (key < 0 || key > 3) {
		return false;
	}
	return (m_mouseKeys[key] && !m_prevMouseKeys[key]);
}

bool Input::mouseUp(int key) {
	if (key < 0 || key > 3) {
		return false;
	}
	return (m_prevMouseKeys[key] && !m_mouseKeys[key]);
}

int Input::getMouseX() {
	return m_mouseX;
}

int Input::getMouseY() {
	return m_mouseY;
}

void Input::setMousePos(int x, int y) {
	SDL_WarpMouse(x, y);
}

void Input::hideCursor(bool hide) {
	if (hide) {
		SDL_ShowCursor(SDL_DISABLE);
	}
	else {
		SDL_ShowCursor(SDL_ENABLE);
	}
}

bool Input::keyDown(int key) {
	if (key < 0 || key > m_numKeys) {
		return false;
	}
	return m_keys[key];
}

bool Input::keyHit(int key) {
	if (key < 0 || key > m_numKeys) {
		return false;
	}
	return (m_keys[key] && !m_prevKeys[key]);
}

bool Input::keyUp(int key) {
	if (key < 0 || key > m_numKeys) {
		return false;
	}
	return (m_prevKeys[key] && !m_keys[key]);
}