#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "objects/player.h"
#include <iostream>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

using namespace std;

enum sound_type {
    SND_start,
    SND_fire,
    SND_hit,
    SND_MAX
};

/**
 * @brief a class that contains a set of application parameters.
 */
class AppConfig
{
public:
    /**
     * path to the texture of objects.
     */
    static string texture_path;
    /**
     * path to the directory with levels.
     */
    static string levels_path;
    /**
     * font path.
     */
    static string font_name;
    /**
     * displayed after a loss.
     */
    static string game_over_text;
    /**
     * dimensions of the game board.
     */
    static SDL_Rect map_rect;
    /**
     * dimensions and location relative to the game status area board.
     */
    static SDL_Rect status_rect;
    /**
     * application window size.
     */
    static SDL_Rect windows_rect;
    /**
     * cell size on the board.
     */
    static SDL_Rect tile_rect;
    /**
     * two starting positions of players.
     */
    static vector<SDL_Point> player_starting_point;
    /**
     * three starting positions of enemies.
     */
    static vector<SDL_Point> enemy_starting_point;
    /**
     * controlling players' tanks.
     */
    static vector <Player::PlayerKeys> player_keys;
    /**
     * time displayed and number of the round at its start.
     */
    static unsigned level_start_time;
    /**
     * duration of slip on ice in milliseconds.
     */
    static unsigned slip_time;
    /**
     * number of enemies to kill in one round.
     */
    static unsigned enemy_start_count;
    /**
     * the time after which a new enemy may appear on the map in milliseconds.
     */
    static unsigned enemy_redy_time;
    /**
     * default maximum number of shells a player can fire.
     */
    static unsigned player_bullet_max_size;
    /**
     * Time to show results after the countdown in milliseconds is completed.
     */
    static unsigned score_show_time;
    /**
     * the length of time the bonus is visible on the map in milliseconds.
     */
    static unsigned bonus_show_time;
    /**
     * casing operating time in milliseconds.
     */
    static unsigned tank_shield_time;
    /**
     * the length of time enemies are frozen in milliseconds.
     */
    static unsigned tank_frozen_time;
    /**
     * Time between killing all enemies and going to the result window in milliseconds.
     */
    static unsigned level_end_time;
    /**
     * duration of the stone casing around the eagle in milliseconds.
     */
    static unsigned protect_eagle_time;
    /**
     * bonus flashing time in milliseconds.
     */
    static unsigned bonus_blink_time;
    /**
     * Minimum time between the player firing projectiles in milliseconds.
     */
    static unsigned player_reload_time;
    /**
     * maximum number of tanks on the map in one moment.
     */
    static int enemy_max_count_on_map;
    /**
     * speed of movement napsu game over.
     */
    static double game_over_entry_speed;
    /**
     * nominal tank speed.
     */
    static double tank_default_speed;
    /**
     * nominal projectile velocity.
     */
    static double bullet_default_speed;
    /**
     * The variable stores information about whether showing enemy targets has been enabled.
     */
    static bool show_enemy_target;
    /**
     * Sound effect
     */
    static Mix_Chunk* sounds[SND_MAX];
};

#endif // APPCONFIG_H
