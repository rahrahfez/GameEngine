#include "GameState.h"

GameState::GameState() {
	m_manager = NULL;
}

void GameState::update() {}

void GameState::draw(Graphics* g) {}

GameState::~GameState() {

}

StateManager* GameState::getManager() {
	return m_manager;
}

void GameState::setManager(StateManager* m) {
	m_manager = m;
}

