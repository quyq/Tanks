#ifndef ENGINE_H
#define ENGINE_H

#include "renderer.h"
#include "spriteconfig.h"

/**
 * @brief The class connects elements related to the operation of the program.
 */
class Engine
{
public:
    Engine();

    /**
     * @return a static instance of the @a Engine object
     */
    static Engine& getEngine(); // the engine can be accessible in any module by using only the namespace, not a pointer
    /**
     * The function converts the given numerical value to text.
     * @param num - an integer
     * @return the integer as text
     */
    static std::string intToString(int num);
    /**
     * The function creates component objects of the engine.
     */
    void initModules();
    /**
     * The function destroys component objects of the engine.
     */
    void destroyModules();

    /**
     * @return a pointer to the Renderer object allowing drawing on the screen
     */
    Renderer* getRenderer() const;
    /**
     * @return a pointer to the SpriteConfig object storing information about textures
     */
    SpriteConfig* getSpriteConfig() const;
private:
    Renderer* m_renderer;
    SpriteConfig* m_sprite_config;
};

#endif // ENGINE_H
