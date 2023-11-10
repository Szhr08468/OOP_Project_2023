#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
    enum class State {
        GameStart,
        Player1Turn,
        Player2Turn,
        Player3Turn,
        Player4Turn,
        GameOver,
    };

    GameState();

    // Methods to set and get the current state
    void SetState(State newState);
    State GetCurrentState() const;

    // Additional state-specific methods and properties as needed
private:
    State currentState;
};

#endif // GAMESTATE_H
