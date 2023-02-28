#include "ComonFunc.h"
#include "BaseObject.h"
#include "game_map.h"
#include "MainObject.h"

BaseObject g_background;

bool Init()
{
    bool sc = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }
    //Set a hint with normal priority
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    //Create window
    g_window = SDL_CreateWindow("SONE", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(g_window == NULL) sc = false;
    else{
        //Create renderer for window
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL) sc = false;
        else{
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            //Declare SDL_Image
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags)) sc = false;
        }
    }
    return sc;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img/bg4.jpg", g_screen);
    return ret;
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen); g_screen = NULL;
    SDL_DestroyWindow(g_window); g_window = NULL;

    IMG_Quit();
    SDL_Quit();

}

int main(int argc, char* argv[])
{
    if(!Init()) return -1;
    if(!LoadBackground()) return -1;

    GameMap game_map;
    game_map.LoadMap("map/map02.txt");
    game_map.LoadTiles(g_screen);

    MainObject player;
    player.LoadImg("img/player_right.png", g_screen);
    player.set_clips();

    bool is_quit = false;
    while(!is_quit)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT){
                is_quit = true;
            }
            player.HandleInputAction(g_event, g_screen);
        }
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);
        Map map_data = game_map.getMap();

        player.SetMapXY(map_data.start_x, map_data.start_y);
        player.DoPlayer(map_data);
        player.Show(g_screen);

        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen);
        SDL_RenderPresent(g_screen);
    }
    close();
    return 0;
}
