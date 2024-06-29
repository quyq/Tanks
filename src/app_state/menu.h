#ifndef MENU_H
#define MENU_H

#include "appstate.h"
#include "../objects/player.h"

#include <vector>
#include <string>
/**
 * @brief
 * The class for selecting the game mode: 1 player or 2 players, or exiting. The class is the first state of the application, appears right after the program is launched, and allows transitioning to the game state (Game class).
 */
class Menu : public AppState
{
public:
    Menu();
    ~Menu();
    /**
     * Function checking whether to end the menu state and proceed to the next game state.
     * @return @a true if one of the menu options has been selected or the Esc key has been pressed, @a false otherwise
     */
    bool finished() const;
    /**
     * Function draws the game logo, menu entries, and the selected position indicator in the shape of a tank.
     */
    void draw();
    /**
     * Function responsible for the animation of the indicator in the form of a tank.
     * @param dt - time since the last animation
     * @see Tank::update(Uint32 dt)
     */
    void update(Uint32 dt);
    /**
     * Function responds to key presses:
     * @li Up and down arrow - changing the selected menu position
     * @li Enter and Space - confirming the current menu position
     * @li Esc - exiting the program
     * @param ev - pointer to the SDL_Event union storing the type and parameters of different events
     */
    void eventProcess(SDL_Event* ev);
    /**
     * Transition to the game in the selected mode or exit the application.
     * @return @a nullptr if "Exit" was selected or Esc was pressed, otherwise the function returns a pointer to Game
     */
    AppState* nextState();

private:
    /**
     * Container storing all the texts that appear in the menu.
     */
    std::vector<std::string> m_menu_texts;
    /**
     * Index of the selected menu position.
     */
    int m_menu_index;
    /**
     * Variable responsible for the indicator in the form of a tank.
     */
    Player* m_tank_pointer;
    /**
     * Variable stores information on whether to end the current game state and proceed to the game or shut down the application.
     */
    bool m_finished;
};

#endif // MENU_H
