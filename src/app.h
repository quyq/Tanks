#ifndef APP_H
#define APP_H

#include "app_state/appstate.h"

/**
 * @brief
 * Main class of the application. Its operation is equivalent to the operation of the application.
 */
class App
{
public:
    App();
    ~App();
    /**
     * The function includes initialization of the SDL2 library, game engine, loading textures, and fonts.
     * After successful initialization, it enters the main loop of the program, which sequentially: responds to an event,
     * updates the current state of the application, draws objects on the screen.
     */
    void run();
    /**
     * Function handling events waiting in the queue.
     */
    void eventProces();
private:
    /**
     * Variable maintaining the operation of the main program loop.
     */
    bool is_running;
    /**
     * Current state of the application.
     */
    AppState* m_app_state;
    /**
     * Application window object.
     */
    SDL_Window* m_window;
};

#endif // APP_H
