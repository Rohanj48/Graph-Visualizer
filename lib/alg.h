#pragma once

#include "utils.cpp"
class Algorithm
{

public:
    std::map<int, node> &node_map;

    int step_size = 0;

    Algorithm(std::map<int, node> &node_map);

    void dfs_step(int Starting_node_id);
};