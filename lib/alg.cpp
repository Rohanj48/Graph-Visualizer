#include "alg.h"
#include <vector>
#include <iostream>
Algorithm::Algorithm(std::map<int, node> &node_map) : node_map(node_map)
{
}

void Algorithm::dfs_step(int starting_node_id)
{
    std::vector<int> unvisited_nodes;
    for (auto iter = node_map.begin(); iter != node_map.end(); iter++)
    {
        std::cout << "ITEM = " << iter->first << "\n";
    }
}