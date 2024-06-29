#ifndef BRICK_H
#define BRICK_H

#include "object.h"

/**
 * @brief Class responsible for a single piece of the wall.
 */
class Brick : public Object
{
public:
    /**
     * Creating a wall at position (0, 0).
     */
    Brick();
    /**
     * Creating a wall
     * @param x - initial horizontal position
     * @param y - initial vertical position
     */
    Brick(double x, double y);

    /**
     * The function was implemented to avoid changing collision_rect.
     * @param dt - time since the last function call.
     */
    void update(Uint32 dt);
    /**
     * Function changing the state of the wall after being hit by a bullet. The function changes collision_rect.
     * @param bullet_direction - the direction of bullet movement
     */
    void bulletHit(Direction bullet_direction);
private:
    /**
     * Number of bullet hits in the wall.
     */
    int m_collision_count;
    /**
     * One of the ten states in which the brick can be.
     */
    int m_state_code;
};

#endif // BRICK_H
