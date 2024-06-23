#pragma once
#include <map>
#include <vector>
#include "raylib.h"

struct node
{
    int id;

    int degree = 0;
    int visited;

    Vector2 world_pos;
    int radius = 30;
    std::vector<int> nbors;

    node(int id) : id(id) {}
};

class Graph
{
private:
    std::map<int, node> node_map;
    int graph_display_structure;

    int new_node_id;

public:
    Graph();

    //~Graph();

    /// @brief Create all the nodes together
    void intitAllNodes(int node_count);

    /// @brief Add an Edge between two nodes
    void addSingleEdge(Vector2 &mouse_position, Camera2D &cam_object, int &state_var);

    /// @brief a overlay for creating the nodes and edges
    /// to be called on the window Draw area
    void createNodeOverlay(Camera2D &cam_object);

    /// @brief handles the drawing of the graph structure
    void drawStructure(Camera2D &cam_object);

    // algorithim for dfs
};
