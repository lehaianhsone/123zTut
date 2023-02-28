#ifndef COMONFUNC_H
#define COMONFUNC_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 641;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 255;

#define TILE_SIZE 64
//so hinh anh can render ra: 64 x 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10

struct Input{
    int left;
    int right;
    int up;
    int down;
    int jump;
};

struct Map
{
    //toa do
    int start_x;
    int start_y;
    //gia tri toi da cua ban do
    int max_x;
    int max_y;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    char* file_name;
};

#endif // COMONFUNC_H
