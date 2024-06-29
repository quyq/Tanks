#ifndef TYPE_H
#define TYPE_H

enum SpriteType
{
    ST_TANK_A,
    ST_TANK_B,
    ST_TANK_C,
    ST_TANK_D,

    ST_PLAYER_1,
    ST_PLAYER_2,

    ST_BRICK_WALL,
    ST_STONE_WALL,
    ST_WATER,
    ST_BUSH,
    ST_ICE,

    ST_BONUS_GRENADE,
    ST_BONUS_HELMET,
    ST_BONUS_CLOCK,
    ST_BONUS_SHOVEL,
    ST_BONUS_TANK,
    ST_BONUS_STAR,
    ST_BONUS_GUN,
    ST_BONUS_BOAT,

    ST_SHIELD,
    ST_CREATE,
    ST_DESTROY_TANK,
    ST_DESTROY_BULLET,
    ST_BOAT_P1,
    ST_BOAT_P2,

    ST_EAGLE,
    ST_DESTROY_EAGLE,
    ST_FLAG,

    ST_BULLET,

    ST_LEFT_ENEMY,
    ST_STAGE_STATUS,

    ST_TANKS_LOGO,

    ST_NONE
};

enum TankStateFlag
{
    TSF_SHIELD = 1 << 1, // after taking a helmet
    TSF_FROZEN = 1 << 2, // after the enemy takes a clock
    TSF_DESTROYED = 1 << 3, // after taking a bomb by the enemy or being hit by a bullet
    TSF_BOAT = 1 << 4, // after taking a boat, allows passing through water
    TSF_BONUS = 1 << 5, // after hitting this tank a bonus appears on the map
    TSF_ON_ICE = 1 << 6,  // if the tank is on ice, it slides
    TSF_CREATE = 1 << 7, // creating a tank
    TSF_LIFE = 1 << 8,
    TSF_MENU = 1 << 9 // double speed of animation
};

enum Direction
{
    D_UP = 0,
    D_RIGHT = 1,
    D_DOWN = 2,
    D_LEFT = 3
};

#endif // TYPE_H
