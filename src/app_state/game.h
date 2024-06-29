#ifndef GAME_H
#define GAME_H
#include "appstate.h"
#include "../objects/object.h"
#include "../objects/player.h"
#include "../objects/enemy.h"
#include "../objects/bullet.h"
#include "../objects/brick.h"
#include "../objects/eagle.h"
#include "../objects/bonus.h"
#include <vector>
#include <string>

/**
 * @brief The class is responsible for the movement of all tanks and interactions between tanks and between tanks and other objects on the map.
 */
class Game : public AppState
{
public:
    /**
     * Default constructor - allows for single player game
     */
    Game();
    /**
     * Constructor that allows specifying the initial number of players. The number of players can be 1 or 2, any other value will start the game for one player.
     * This constructor is called in @a Menu::nextState.
     * @param players_count - number of players 1 or 2
     */
    Game(int players_count);
    /**
     * Constructor that takes already existing players.
     * Called in @a Score::nextState
     * @param players - container with players
     * @param previous_level - variable storing the number of the previous level
     */
    Game(std::vector<Player*> players, int previous_level);

    ~Game();
    /**
     * The function returns @a true if the player has destroyed all enemies or when the eagle was hit or the player lost all lives, which means a loss.
     * @return @a true or @a false
     */
    bool finished() const;
    /**
     * At the beginning of the round, the function displays its number. During the game, the function is responsible for drawing the level (walls, stones, water, ice, bushes),
     * players, enemies, bonuses, the eagle, game status on the right panel (remaining enemies, remaining lives of players, round number).
     * After a loss or during a pause, it displays the corresponding information in the middle of the screen.
     */
    void draw();
    /**
     * The function updates the state of all objects on the board (tanks, bonuses, obstacles). It also checks collisions between tanks, between tanks and level elements, and between bullets and tanks and map elements.
     * Here, destroyed objects are removed, new enemy tanks are added, and the conditions for ending the round are checked.
     * @param dt - time since the last function call in milliseconds
     */
    void update(Uint32 dt);
    /**
     * Here, the reaction to keys occurs:
     * @li Enter - pause game
     * @li Esc - return to menu
     * @li N - move to the next round, if the game is not lost
     * @li B - move to the previous round, if the game is not lost
     * @li T - show paths to targets of enemy tanks
     * @param ev - pointer to the SDL_Event union storing the type and parameters of various events, including keyboard events
     */
    void eventProcess(SDL_Event* ev);
    /**
     * Transition to the next state.
     * @return pointer to @a Scores class objects if the player passed the round or lost. If the player pressed Esc, the function returns a pointer to @a Menu object.
     */
    AppState* nextState();

private:
    /**
     * Load the level map from a file
     * @param path - path to the map file
     */
    void loadLevel(std::string path);
    /**
     * Removing remaining enemies, players, map objects, and bonuses
     */
    void clearLevel();
    /**
     * Load a new level and create new players if they do not already exist.
     * @see Game::loadLevel(std::string path)
     */
    void nextLevel();
    /**
     * Create a new enemy if the number of enemies on the board is less than 4, assuming that not all 20 enemies on the map have been created yet.
     * The function generates different levels of enemy armor depending on the level; the higher the round number, the greater the chance that the enemy will have fourth level armor.
     * The armor level number indicates how many times an enemy must be hit with a bullet to be destroyed. This number ranges from 1 to 4 and corresponds to different tank colors.
     * The generated enemy has an additional chance of creating a bonus on the board when hit.
     */
    void generateEnemy();
    /**
     * The function generates a random bonus on the map and places it in a position that does not collide with the eagle.
     */
    void generateBonus();

    /**
     * Check if the tank can freely move forward, if not, it stops. The function prevents leaving the play area.
     * If the tank enters ice, it causes it to slide. If the tank has the "Boat" bonus, it can cross water. Tanks cannot cross the eagle.
     * @param tank - the tank for which collisions are checked
     * @param dt - the last time change, assuming small changes in subsequent time steps, we can predict the next position of the tank and react accordingly.
     */
    void checkCollisionTankWithLevel(Tank* tank, Uint32 dt);
    /**
     * Check for collisions between the tanks being examined, if so, both are stopped.
     * @param tank1
     * @param tank2
     * @param dt
     */
    void checkCollisionTwoTanks(Tank* tank1, Tank* tank2, Uint32 dt);
    /**
     * Check if the selected bullet collides with any map element (water and ice are ignored). If so, both the bullet and the object are destroyed.
     * If the eagle is hit, the game is lost.
     * @param bullet - bullet
     */
    void checkCollisionBulletWithLevel(Bullet* bullet);
    /**
     * Check for bullet collisions with bushes on the map. Bushes and the bullet are destroyed when it has increased damage.
     * @param bullet - bullet
     * @see Bullet::increased_damage
     */
    void checkCollisionBulletWithBush(Bullet* bullet);
    /**
     * Check if a player has hit a selected enemy. If so, the player scores points and the enemy loses one armor level.
     * @param player - player
     * @param enemy - enemy
     */
    void checkCollisionPlayerBulletsWithEnemy(Player* player, Enemy* enemy);
    /**
     * Check if an enemy bullet has hit a player. If so, the player loses one life unless they had a shield.
     * @param enemy - enemy
     * @param player - player
     */
    void checkCollisionEnemyBulletsWithPlayer(Enemy* enemy, Player* player);
    /**
     * If two bullets collide, both are destroyed.
     * @param bullet1
     * @param bullet2
     */
    void checkCollisionTwoBullets(Bullet* bullet1, Bullet* bullet2);
    /**
     * Check if a player has taken a bonus. If so, the appropriate reaction occurs:
     * @li Grenade - visible enemies are destroyed
     * @li Helmet - the player gets a temporary shield from all bullets
     * @li Clock - stops visible enemies
     * @li Shovel - Temporarily creates a stone wall around the eagle
     * @li Tank - increases the player's lives by 1
     * @li Star - upgrades the player's tank (increases speed, number of bullets)
     * @li Gun - maximizes player upgrades
     * @li Boat - allows crossing water
     * The player receives additional points for collecting a bonus.
     * @param player
     * @param bonus
     */
    void checkCollisionPlayerWithBonus(Player* player, Bonus* bonus);

    /**
     * Number of columns in the map grid.
     */
    int m_level_columns_count;
    /**
     * Number of rows in the map grid.
     */
    int m_level_rows_count;
    /**
     * Obstacles on the map.
     */
    std::vector< std::vector <Object*> > m_level;
    /**
     * Bushes on the map.
     */
    std::vector<Object*> m_bushes;

    /**
     * Set of enemies.
     */
    std::vector<Enemy*> m_enemies;
    /**
     * Set of remaining players.
     */
    std::vector<Player*> m_players;
    /**
     * Set of killed players.
     */
    std::vector<Player*> m_killed_players;
    /**
     * Set of bonuses on the map.
     */
    std::vector<Bonus*> m_bonuses;
    /**
     * The eagle object.
     */
    Eagle* m_eagle;

    /**
     * Current level number.
     */
    int m_current_level;
    /**
     * Number of players in the selected game mode 1 or 2.
     */
    int m_player_count;
    /**
     * Number of remaining enemies to kill on the current level
     */
    int m_enemy_to_kill;

    /**
     * Variable stores whether the level start screen is currently being displayed.
     */
    bool m_level_start_screen;
    /**
     * Variable stores whether the eagle is protected by a stone wall.
     */
    bool m_protect_eagle;
    /**
     * Time how long the level start screen has been displayed.
     */
    Uint32 m_level_start_time;
    /**
     * Time since the last enemy was created.
     */
    Uint32 m_enemy_redy_time;
    /**
     * Time elapsed since winning the map.
     */
    Uint32 m_level_end_time;
    /**
     * Time how long the eagle has been protected by a stone wall.
     */
    Uint32 m_protect_eagle_time;

    /**
     * Game over state.
     */
    bool m_game_over;
    /**
     * Position of the "GAME OVER" text if @a m_game_over is equal to @a true.
     */
    double m_game_over_position;
    /**
     * Variable stores information whether to end the current game state and move to displaying scores or game menu.
     */
    bool m_finished;
    /**
     * Variable indicates whether pause has been activated.
     */
    bool m_pause;
    /**
     * Position number for newly created enemy. Changed with each enemy creation.
     */
    int m_enemy_respown_position;
};

#endif // GAME_H
