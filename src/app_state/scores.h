#ifndef SCORES_H
#define SCORES_H
#include "appstate.h"
#include "../objects/player.h"

#include <vector>
#include <string>

/**
 * @brief
 * The class is responsible for displaying the scores of players from the previous round.
 */
class Scores : public AppState
{
public:
    Scores();
    /**
     * Constructor called by Game after the game ends.
     * @param players - container with all players who participated in the game
     * @param level - number of the last level
     * @param game_over - variable indicating whether the last level was lost
     */
    Scores(std::vector<Player*> players, int level, bool game_over);
    /**
     * The function returns @a true after a specified time of displaying the score screen.
     * @return @a true or @a false
     */
    bool finished() const;
    /**
     * The function is responsible for drawing the appropriate texts and players' tanks on the screen.
     */
    void draw();
    /**
     * The function is responsible for changing the score counter.
     * @param dt - time since the last call of the function allows to determine the display time of the score window
     */
    void update(Uint32 dt);
    /**
     * The function responds to pressing the Enter key, which ends the score counting and accelerates the transition to the next state.
     * @param ev - pointer to the SDL_Event union storing the type and parameters of different events
     */
    void eventProcess(SDL_Event* ev);
    /**
     * The function returns a pointer to the object being the next state of the application. If the player lost, the next state is @a Menu; if the round was passed, the next state is @a Game.
     * @return pointer to the next state
     */
    AppState* nextState();

private:
    /**
     * Container with all players (killed and not killed).
     */
    std::vector<Player*> m_players;
    /**
     * Number of the last level.
     */
    int m_level;
    /**
     * Variable stores whether the last level was lost.
     */
    bool m_game_over;
    /**
     * Current value of the score counter.
     */
    unsigned m_score_counter;
    /**
     * Variable indicating whether the score counter is enabled.
     */
    bool m_score_counter_run;
    /**
     * The score towards which the score counter is aiming.
     */
    unsigned m_max_score;
    /**
     * Time since the end of score counting in milliseconds.
     */
    Uint32 m_show_time;
};

#endif // SCORES_H
