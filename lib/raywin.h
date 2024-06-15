#pragma once
#include "raylib.h"

#define SCREENWIDTH  1200
#define SCREENHEIGHT 800  


class Raywin{
    private:


    public:
    Camera2D main_camera;

    Raywin();
    ~Raywin();


    // has to be called inside a while loop
    void windowDrawCalls();
    void CameraDrawCalls();
    void singleStep();
    void windowCameraEndDrawCalls();
    bool windowShouldNotClose();
    /// @brief Draws the Outer Mesh for visability on camera movement
    void winDrawMesh(int mesh_step,int mesh_limit);

    /// enable camera movemnt call iside 2d draw
    void panDisplay();

};

