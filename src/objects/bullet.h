#ifndef BULLET_H
#define BULLET_H

#include "object.h"

/**
 * @brief Class responsible for bullets fired by tanks.
 */
class Bullet : public Object
{
public:
    /**
     * Creating a bullet at position (0, 0).
     */
    Bullet();
    /**
     * Creating a bullet
     * @param x - initial horizontal position
     * @param y - initial vertical position
     */
    Bullet(double x, double y);

    /**
     * Updating the bullet's position.
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Activating the bullet's explosion animation.
     */
    void destroy();
    
    /**
     * The speed of the bullet's movement.
     */
    double speed;
    /**
     * Variable stores information whether the bullet has collided with something.
     */
    bool collide;
    /**
     * Variable stores information whether the bullet has increased damage.
     * Increased damage allows destroying stone walls and bushes.
     */
    bool increased_damage;
    /**
     * The direction of the bullet's movement.
     */
    Direction direction;
};

#endif // BULLET_H
