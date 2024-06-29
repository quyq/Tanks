#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"

/**
 * @brief Class corresponding to player tanks.
 */
class Player : public Tank
{
public:

    /**
     * @brief Structure storing keys corresponding to controlling the player's tank.
     */
    struct PlayerKeys
    {
        PlayerKeys(): up(SDL_SCANCODE_UNKNOWN), down(SDL_SCANCODE_UNKNOWN), left(SDL_SCANCODE_UNKNOWN), right(SDL_SCANCODE_UNKNOWN), fire(SDL_SCANCODE_UNKNOWN) {}
        PlayerKeys(SDL_Scancode u, SDL_Scancode d, SDL_Scancode l, SDL_Scancode r, SDL_Scancode f): up(u), down(d), left(l), right(r), fire(f) {}
        /**
         * Key corresponding to moving up.
         */
        SDL_Scancode up;
        /**
         * Key corresponding to moving down.
         */
        SDL_Scancode down;
        /**
         * Key corresponding to moving left.
         */
        SDL_Scancode left;
        /**
         * Key corresponding to moving right.
         */
        SDL_Scancode right;
        /**
         * Key corresponding to firing a bullet.
         */
        SDL_Scancode fire;
    };

    /**
     * Creating a player in one of the player starting positions.
     * @see AppConfig::player_starting_point
     */
    Player();
    /**
     * Creating a player tank
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - player type
     */
    Player(double x, double y, SpriteType type);


    /**
     * The function is responsible for changing the player tank's animation and for checking the state of pressed keys and reacting to those keys that control the player's tank.
     * @param dt - time since the last function call, used when changing animations
     */
    void update(Uint32 dt);
    /**
     * The function is responsible for subtracting a life, clearing all flags, and enabling the tank spawning animation.
     */
    void respawn();
    /**
     * The function is responsible for enabling the tank explosion animation if the tank did not have a shield, boat, or three stars.
     */
    void destroy();
    /**
     * The function is responsible for creating a bullet if the maximum number has not yet been created,
     * giving it greater speed if the player has at least one star, and adding increased damage if the player has three stars.
     * @return pointer to the created bullet, if no bullet was created returns @a nullptr
     */
    Bullet* fire();

    /**
     * The function changes the number of stars currently held. With a non-zero number of stars, the default speed of the tank is increased,
     * and for a number of stars greater than 1 and for each positive @a c, the maximum number of bullets is increased.
     * @param c - change in the number of stars, can be negative
     */
    void changeStarCountBy(int c);

    /**
     * Keys controlling the movements of the current player.
     */
    PlayerKeys player_keys;
    /**
     * Points currently held by the player.
     */
    unsigned score;

private:
    /**
     * The current number of stars held; can range from [0, 3].
     */
    int star_count;
    /**
     * Time that has passed since the last bullet was fired.
     */
    Uint32 m_fire_time;
};

#endif // PLAYER_H
