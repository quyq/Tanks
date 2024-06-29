#ifndef EAGLE_H
#define EAGLE_H

#include "object.h"

/**
 * @brief Class of the eagle, which players must defend and enemies must destroy.
 */
class Eagle : public Object
{
public:
    /**
     * Creating an eagle at position (0, 0).
     */
    Eagle();
    /**
     * Creating an eagle
     * @param x - initial horizontal position
     * @param y - initial vertical position
     */
    Eagle(double x, double y);
    /**
     * Updating the eagle's animation.
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Triggering the eagle's explosion.
     */
    void destroy();
};

#endif // EAGLE_H
