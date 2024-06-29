#ifndef TANK_H
#define TANK_H

#include "object.h"
#include "bullet.h"
#include "../type.h"

#include <vector>

typedef unsigned TankStateFlags;

/**
 * @brief
 * Class responsible for basic tank mechanics: driving, shooting.
 */
class Tank : public Object
{
public:
    /**
     * Creating a tank at the first of the enemy starting positions.
     * @see AppConfig::enemy_starting_point
     */
    Tank();
    /**
     * Creating a tank
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - type of tank
     */
    Tank(double x, double y, SpriteType type);
    virtual ~Tank();

    /**
     * The function draws the tank image, if necessary draws a shield and a boat.
     * Calls drawing of bullets.
     */
    void draw();
    /**
     * The function is responsible for changing the position of the tank, updating the position of the dest_rect and collision_rect, position of shields and boats, tank animation,
     * calling bullet update and removing destroyed bullets. The function counts down the time of having a shield and freezing and disables these flags.
     * @param dt - time since the last function call, used when changing animations
     */
    void update(Uint32 dt);
    /**
     * The function is responsible for creating a bullet if the maximum number has not yet been created.
     * @return pointer to the created bullet, if no bullet was created returns @a nullptr
     */
    virtual Bullet* fire();
    /**
     * The function returns the collision rectangle that would be in the next frame assuming the speed and direction as they are currently.
     * @param dt - predicted time for calculating the next frame
     * @return next collision rectangle
     */
    SDL_Rect nextCollisionRect(Uint32 dt);
    /**
     * The function sets the next direction of movement taking into account slipping on ice. When changing direction, the tank is adjusted to the multiples of the dimensions of the board cell @a AppConfig::tile_rect.
     * @param d - new direction
     */
    void setDirection(Direction d);
    /**
     * The function stops the tank.
     * @param intersect_rect - collision area
     */
    void collide(SDL_Rect &intersect_rect);
    /**
     * The function is responsible for clearing all flags and enabling the tank spawning animation.
     */
    virtual void respawn();
    /**
     * The function is responsible for enabling the tank explosion animation.
     */
    virtual void destroy();
    /**
     * Setting the selected flag.
     * @param flag
     */
    void setFlag(TankStateFlag flag);
    /**
     * Clearing the selected flag.
     * @param flag
     */
    void clearFlag(TankStateFlag flag);
    /**
     * Check if the selected flag is set.
     * @param flag
     * @return @a true if the flag is set, otherwise @a false
     */
    bool testFlag(TankStateFlag flag);

    /**
     * Default speed of the given tank. It can vary for different types of tanks or can be changed after picking up a bonus by the player.
     */
    double default_speed;
    /**
     * Current speed of the tank.
     */
    double speed;
    /**
     * Variable stores information whether the tank is currently stopped.
     */
    bool stop;
    /**
     * Variable stores the current driving direction of the tank.
     */
    Direction direction;
    /**
     * Container with bullets fired by the tank.
     */
    std::vector<Bullet*> bullets;
    /**
     * Number of lives of the player or the armor level number of the enemy tank.
     */
    int lives_count;

protected:
    /**
     * Flags currently held by the tank.
     */
    TankStateFlags m_flags;
    /**
     * Time since the occurrence of slipping.
     */
    Sint32 m_slip_time;
    /**
     * Corresponds to the tank's direction in a slip and can be different from the direction of movement of the tank on ice.
     */
    Direction new_direction;
    /**
     * Maximum number of bullets the tank can fire.
     */
    unsigned m_bullet_max_size;

    /**
     * Pointer to the tank's shield. If the tank does not have a shield, the variable is nullptr;
     */
    Object* m_shield;
    /**
     * Pointer to the boat the tank may have. If the tank does not have a boat, the variable is nullptr;
     */
    Object* m_boat;
    /**
     * Time since acquiring the shield.
     */
    Uint32 m_shield_time;
    /**
     * Time since the tank was frozen.
     */
    Uint32 m_frozen_time;
};

#endif // TANK_H
