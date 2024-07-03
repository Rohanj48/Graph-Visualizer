#pragma once
#include <map>
#include <vector>
#include "raylib.h"
#include "alg.h"
#include "utils.cpp"
class Graph
{
private:
    // map with [id] = node
    std::map<int, node> node_map;
    Algorithm *Alg;

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

    // overlay for starting the dfs

    // getter
    std::map<int, node> &get_node_map();
};
