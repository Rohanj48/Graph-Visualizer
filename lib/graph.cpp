#include "graph.h"
#include <memory>
#include <iostream>
#include <raylib.h>
#include <cmath>
#include "alg.h"

Graph::Graph()
{
    Alg = new Algorithm(node_map);
}

void Graph::intitAllNodes(int node_count)
{

    for (int i = 0; i < node_count; i++)
    {

        std::unique_ptr<node> temp_node = std::make_unique<node>(i);
        node_map.emplace(i, *temp_node);
    }
}

void Graph::createNodeOverlay(Camera2D &cam_object)
{

    // state Variables for controlling the flow states
    static int node_click;
    static int edge_click;

    Vector2 offset = {600.0f, 20.0f};
    Vector2 mouse_pos = GetMousePosition();
    Rectangle add_node_buttonR = {offset.x, offset.y, 200, 50};
    Rectangle add_edge_buttonR = {offset.x + 300, offset.y, 200, 50};

    // UI drawing
    DrawRectangleRec(add_node_buttonR, BLACK);
    DrawRectangleRec(add_edge_buttonR, BLACK);
    DrawText("ADD NODE", add_node_buttonR.x + 30, add_node_buttonR.y + 10, 26, RED);
    DrawText("ADD EDGE", add_edge_buttonR.x + 30, add_edge_buttonR.y + 10, 26, RED);

    // Now Logic for adding making a node and placing it in the place
    // only refer new_node_id iff on_cli == 1
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse_pos, add_node_buttonR))
    {

        node_click = 1;
        new_node_id = node_map.size() + 1;
        std::unique_ptr<node> temp_node = std::make_unique<node>(new_node_id);
        node_map.emplace(new_node_id, *temp_node);
    }
    else if (node_click == 1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        node_click = 0;
    }
    else if (node_click == 1)
    {

        try
        {

            (node_map.at(new_node_id)).world_pos = GetScreenToWorld2D(mouse_pos, cam_object);
            //(node_map.at(new_node_id-1)).world_pos = mouse_pos;
        }
        catch (const std::out_of_range &e)
        {

            std::cout << "Node KEY INVALID " << e.what() << "\n";
            std::cout << new_node_id << "\n";
        }
    }

    // Logic for inserting a new edge handled by another function after firstClick
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse_pos, add_edge_buttonR))
    {
        edge_click = 1;
    }
    else if (edge_click >= 1)
        addSingleEdge(mouse_pos, cam_object, edge_click);
}

void Graph::addSingleEdge(Vector2 &mouse_position, Camera2D &cam_object, int &state_var)
{

    // should enable selection of of two edges
    // first poll all the nodes for position and clicks together
    static int id1;
    static int id2;
    for (auto it = node_map.begin(); it != node_map.end(); ++it)
    {

        Vector2 posV = it->second.world_pos;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointCircle(GetScreenToWorld2D(mouse_position, cam_object), posV, it->second.radius))
        {

            if (state_var == 1)
            {
                id1 = it->first;
                state_var = 2;
            }
            else if (state_var == 2)
            {
                id2 = it->first;
                state_var = 3;
            }
        }
        // After 2nd click statevar == 3 add the the 2 nodes to each others edgelists
        if (state_var == 2)
            DrawLineV(GetWorldToScreen2D(node_map.at(id1).world_pos, cam_object), mouse_position, BLACK);
        if (state_var == 3)
        {

            node_map.at(id1).nbors.push_back(id2);
            node_map.at(id1).degree++;
            node_map.at(id2).nbors.push_back(id1);
            node_map.at(id2).degree++;

            std::cout << "PUSHED = " << "\n";
            // resset for next node addition or smth
            state_var = 0;
        }
    }
}

void Graph::drawStructure(Camera2D &cam_object)
{

    // iterate through all nodes in node_map
    // draw position and edges

    for (auto it = node_map.begin(); it != node_map.end(); ++it)
    {

        // Vector2 posV = GetWorldToScreen2D(it->second.world_pos,cam_object);
        Vector2 posV = it->second.world_pos;

        for (int i = 0; i < it->second.degree; i++)
        {
            int id = (it->second.nbors)[i];
            DrawLineV(posV, node_map.at(id).world_pos, BLACK);
        }

        DrawCircleV(posV, 30, RED);
    }
}

std::map<int, node> &Graph::get_node_map()
{
    return node_map;
}

// void Graph::dfs(){

//     static int stack[50];
// }