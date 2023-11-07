#include "GameState.h"

GameState::GameState() : currentState(State::Player1Turn) {}

void GameState::SetState(State newState) {
    currentState = newState;
}

GameState::State GameState::GetCurrentState() const {
    return currentState;
}

