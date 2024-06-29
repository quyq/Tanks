#ifndef APPSTATE_H
#define APPSTATE_H

#include <SDL2/SDL_events.h>
#include <string>

/**
 * @brief
 * The class is an interface that is inherited by the @a Game, @a Menu, @a Scores classes
 */
class AppState
{
public:
    virtual ~AppState() {}

    /**
     * Function checks if the current game state has finished.
     * @return @a true if the current game state has finished, otherwise @a false.
     */
    virtual bool finished() const = 0;
    /**
     * Function drawing game elements belonging to a given state
     */
    virtual void draw() = 0;
    /**
     * Function updating the state of objects and counters in the game
     * @param dt - time since the last function call in milliseconds
     */
    virtual void update(Uint32 dt) = 0;
    /**
     * Function allowing handling of events detected by the SDL2 library.
     * @param ev - pointer to the SDL_Event union storing the type and parameters of different events
     */
    virtual void eventProcess(SDL_Event* ev) = 0;
    /**
     * Function returning the next state after the current one ends. The function should be called only when the @a finished function returns @a true.
     * @return next game state
     */
    virtual AppState* nextState() = 0;
};
#endif // APPSTATE_H
