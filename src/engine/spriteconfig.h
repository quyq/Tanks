#ifndef SPRITECONFIG_H
#define SPRITECONFIG_H

#include "../type.h"
#include <map>
#include <SDL2/SDL.h>

/**
 * @brief
 * Structure storing information about a given type of object animation.
 */
struct SpriteData
{
    SpriteData() { rect.x = 0; rect.y = 0; rect.w = 0; rect.h = 0; frames_count = 0; frame_duration = 0; loop = false;}
    SpriteData(int x, int y, int w, int h, int fc, int fd, bool l)
        { rect.x = x; rect.y = y; rect.w = w; rect.h = h; frames_count = fc; frame_duration = fd; loop = l;}

    /**
     * Position and dimensions of the first animation frame
     */
    SDL_Rect rect;
    /**
     * Number of frames in the animation.
     */
    int frames_count;
    /**
     * Time of displaying one frame in milliseconds.
     */
    unsigned frame_duration;
    /**
     * Variable determining whether the animation is looped.
     */
    bool loop;
};

/**
 * @brief
 * Class stores information about all types of animations in the game.
 */
class SpriteConfig
{
public:
    /**
     * The constructor performs the addition of subsequent animations using the @a SpriteConfig::insert function.
     */
    SpriteConfig();
    /**
     * Retrieving a selected type of animation.
     * @param sp - the searched type of animation
     * @return animation of the given type
     */
    const SpriteData* getSpriteData(SpriteType sp) const;
private:
    /**
     * Container storing all types of animations.
     */
    std::map<SpriteType, SpriteData> m_configs;
    /**
     * Function used when adding a new type of animation.
     * @param st - type of animation
     * @param x - horizontal position of the first frame of animation in the texture
     * @param y - vertical position of the first frame of animation in the texture
     * @param w - width of the animation frames
     * @param h - height of the animation frames
     * @param fc - number of frames in the animation
     * @param fd - time of displaying one frame
     * @param l - looping of the animation
     */
    void insert(SpriteType st , int x, int y, int w, int h, int fc, int fd, bool l);
};

#endif // SPRITECONFIG_H
