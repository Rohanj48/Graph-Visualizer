#include "raylib.h"
#include "raywin.h"
#include "raymath.h"
#include "alg.h"

#include <iostream>
Raywin::Raywin()
{

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Ray-win 1.0");

    main_camera = {0};
    main_camera.target = (Vector2){SCREENWIDTH / 2, SCREENHEIGHT / 2};
    main_camera.offset = (Vector2){SCREENWIDTH / 2, SCREENHEIGHT / 2};
    main_camera.rotation = 0.0f;
    main_camera.zoom = 1.0f;

    SetTargetFPS(60);
}

Raywin::~Raywin()
{
    CloseWindow();
}

void Raywin::windowDrawCalls()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(10, 10);
}

void Raywin::CameraDrawCalls()
{
    BeginMode2D(main_camera);

    // utills to be removed
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << GetMousePosition().x << "  " << GetMousePosition().y << "\n";
    }
    //
    panDisplay();
    winDrawMesh(50, 3000);
}

void Raywin::windowCameraEndDrawCalls()
{
    EndMode2D();
    EndDrawing();
}

bool Raywin::windowShouldNotClose()
{
    return !WindowShouldClose();
}

void Raywin::winDrawMesh(int mesh_step, int mesh_limit)
{

    for (int i = -mesh_limit; i < mesh_limit; i += mesh_step)
    {
        DrawLine(-mesh_limit, i, mesh_limit, i, BLACK);
    }

    for (int i = -mesh_limit; i < mesh_limit; i += mesh_step)
    {
        DrawLine(i, -mesh_limit, i, mesh_limit, BLACK);
    }
}

void Raywin::panDisplay()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        main_camera.target = Vector2Subtract(main_camera.target, GetMouseDelta());
    }
    main_camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
}
