#pragma once
#include "raylib.h"
#include <map>
#include <vector>
#include "raylib.h"

struct node
{
    int id;

    int degree = 0;
    int visited;
    int state = 0;
    int radius = 30;

    Vector2 world_pos;
    std::vector<int> nbors;

    node(int id) : id(id) {}
};
