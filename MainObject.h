#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "ComonFunc.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.5
#define MAX_FALL_SPEED 3
#define PLAYER_SPEED 8

class MainObject : public BaseObject
{
    public:
        MainObject();
        ~MainObject();

        enum WalkType{
            WALK_RIGHT = 0,
            WALK_LEFT = 1,
        };
        bool LoadImg(std::string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des);
        void HandleInputAction(SDL_Event event, SDL_Renderer* screen);
        void set_clips();

        void DoPlayer(Map& map_data);
        void CheckToMap(Map& map_data);
        void SetMapXY(const int map_x, const int map_y)
        {this->map_x = map_x; this->map_y = map_y;}
        void CenterEntityOnMap(Map& map_data);
    private:
        float x_val;
        float y_val;

        float x_pos;
        float y_pos;

        int width_frame;
        int height_frame;

        SDL_Rect frame_clip[8];
        Input input_type;
        int frame;
        int status;
        bool on_ground;
        int map_x;
        int map_y;
};

#endif // MAINOBJECT_H
