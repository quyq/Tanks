#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

/**
 * @brief
 * The class is responsible for rendering objects on the screen.
 */
class Renderer
{
public:
    Renderer();
    ~Renderer();
    /**
     * Loading a texture from a file and creating a renderer associated with the application window.
     * @param window - pointer to the application window content object
     */
    void loadTexture(SDL_Window* window);
    /**
     * Loading the font in three different sizes.
     */
    void loadFont();
    /**
     * Clearing the screen buffer.
     */
    void clear();
    /**
     * Presenting the screen buffer.
     */
    void flush();
    /**
     * Redrawing a part of the texture onto a part of the screen buffer.
     * @param texture_src - source rectangle from the texture
     * @param window_dest - target rectangle on the screen buffer
     */
    void drawObject(const SDL_Rect *texture_src, const SDL_Rect *window_dest);
    /**
     * Setting the scale of the displayed buffer, so that it maintains the proportions of the board and is positioned in the center of the application window.
     * @param xs - horizontal scale as the ratio of window width to map width
     * @param ys - vertical scale as the ratio of window height to map height
     * @see AppConfig::map_rect
     */
    void setScale(float xs, float ys);
    /**
     * Drawing text in the window buffer at a selected starting position.
     * @param start - position of the starting point of the drawn text; a negative value of any coordinate results in centering the text on that axis
     * @param text - text to draw
     * @param text_color - color of the drawn text
     * @param font_size - font number with which the text will be drawn; three values available: 1, 2, 3
     */
    void drawText(const SDL_Point* start, std::string text, SDL_Color text_color, int font_size = 1);
    /**
     * Function drawing a rectangle in the window buffer.
     * @param rect - position of the rectangle on the board
     * @param rect_color - color of the rectangle
     * @param fill - variable indicating whether the rectangle should be filled
     */
    void drawRect(const SDL_Rect* rect, SDL_Color rect_color, bool fill = false);

private:
    /**
     * Pointer to the object associated with the window buffer.
     */
    SDL_Renderer* m_renderer;
    /**
     * Pointer to the texture containing all visible elements of the game.
     */
    SDL_Texture* m_texture;
    /**
     * Pointer to the auxiliary texture for drawing text on the screen.
     */
    SDL_Texture* m_text_texture;
    /**
     * Font of size 28.
     */
    TTF_Font* m_font1;
    /**
     * Font of size 14.
     */
    TTF_Font* m_font2;
    /**
     * Font of size 10.
     */
    TTF_Font* m_font3;
};

#endif // RENDERER_H
