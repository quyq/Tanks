#ifndef ENEMY_H
#define ENEMY_H

#include "tank.h"

/**
 * @brief Class responsible for the movements of enemy tanks.
 */
class Enemy : public Tank
{
public:
    /**
     * Creating an enemy at one of the starting positions for enemies.
     * @see AppConfig::enemy_starting_point
     */
    Enemy();
    /**
     * Creating an enemy
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - type of enemy tank
     */
    Enemy(double x, double y, SpriteType type);

    /**
     * The function draws the enemy tank and if the flag @a AppConfig::show_enemy_target is set, it draws a line connecting the tank with its target.
     */
    void draw();
    /**
     * The function updates the position of the tank and decides on the direction and timing of the next shot depending on the type of enemy.
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Decrease the armor level by 1. If the armor level reaches zero, the tank explodes (is destroyed).
     */
    void destroy();
    /**
     * The function returns the number of points the player gets for hitting a given enemy tank.
     * @return points
     */
    unsigned scoreForHit();

    /**
     * The position towards which the enemy tank is heading.
     */
    SDL_Point target_position;

private:
    /**
     * Time since the last direction change.
     */
    Uint32 m_direction_time;
    /**
     * Driving time in the current direction. Time after which the direction will change.
     */
    Uint32 m_keep_direction_time;

    /**
     * Time since the last attempt to resume driving
     */
    Uint32 m_speed_time;
    /**
     * Time after which the next attempt to resume driving; setting a non-zero speed.
     */
    Uint32 m_try_to_go_time;

    /**
     * Time since the last attempt to fire a bullet.
     */
    Uint32 m_fire_time;
    /**
     * Time after which an attempt for the next shot will be made.
     */
    Uint32 m_reload_time;
};

#endif // ENEMY_H
