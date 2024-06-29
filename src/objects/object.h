#ifndef OBJECT_H
#define OBJECT_H

#include "../engine/engine.h"

/**
 * @brief
 * Base class for objects in the game.
 */
class Object
{
public:
    /**
     * Creating an object at position (0, 0).
     */
    Object();
    /**
     * Creating an object.
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - type of object
     */
    Object(double x, double y, SpriteType type);
    /**
     * Creating an object.
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param sprite - animation of the object of a given type
     */
    Object(double x, double y, const SpriteData* sprite);
    virtual ~Object();

    /**
     * Drawing using the @a drawObject method from the @a Renderer class, the object from the texture at src_rect coordinates in the map area at dest_rect coordinates.
     */
    virtual void draw();
    /**
     * Updating the dest_rect rectangle based on the object's position: pos_x, pos_y. Counting the display time of one animation frame and changing the frame after counting the appropriate time.
     * @param dt - time since the last function call, used to count the frame display time
     */
    virtual void update(Uint32 dt);

    /**
     * Variable says whether the object is to be deleted. If the change is equal to @a true, then updating and drawing the object is skipped.
     */
    bool to_erase;
    /**
     * Collision rectangle; may be smaller than the dimensions of dest_rect.
     */
    SDL_Rect collision_rect;
    /**
     * The object's target position on the screen.
     */
    SDL_Rect dest_rect;
    /**
     * Position on the texture of the currently displayed frame.
     */
    SDL_Rect src_rect;
    /**
     * Type of object.
     */
    SpriteType type;
    /**
     * Exact horizontal position of the object.
     */
    double pos_x;
    /**
     * Exact vertical position of the object.
     */
    double pos_y;

protected:
    /**
     * The function returns a rectangle shifted by multiples of the size of the rectangle rect.
     * @param rect - base rectangle
     * @param x - horizontal shift
     * @param y - vertical shift
      * @return shifted rectangle
     */
    SDL_Rect moveRect(const SDL_Rect &rect, int x, int y);

    /**
     * Animation corresponding to a given object type.
     */
    const SpriteData* m_sprite;
    /**
     * Time of displaying the current animation frame.
     */
    Uint32 m_frame_display_time;
    /**
     * Number of the current animation frame.
     */
    int m_current_frame;
};

/**
 * Function determining the intersection of two rectangles
 * @param rect1
 * @param rect2
 * @return the intersection, if rect1 and rect2 do not intersect the output rectangle will have negative dimensions
 */
SDL_Rect intersectRect(SDL_Rect* rect1, SDL_Rect* rect2);

#endif // OBJECT_H
