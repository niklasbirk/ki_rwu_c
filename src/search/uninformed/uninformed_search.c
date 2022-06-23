#include "uninformed_search.h"

Node *breadth_first_search(Node **nodes, int n, Node *target)
{
    Node **newNodes;
    int newNodesSize = 0;

    for (int i = 0; i < n; i++)
    {
        if (nodes[i]->value->is_target_reached(nodes[i], target))
        {
            return nodes[i];
        }

        int successorsListSize;
        Node **successors = nodes[i]->value->successors(nodes[i], &successorsListSize);
        newNodes = append_nodes_to_list(newNodes, &newNodesSize, successors, successorsListSize);
    }

    if (newNodesSize > 0)
    {
        return breadth_first_search(newNodes, newNodesSize, target);
    }

    return NULL;
}

Node *depth_first_search(Node *nodes, int n, Node *target)
{
    return NULL;
}

Node *iterative_deepening(Node *nodes, int n, Node *target)
{
    return NULL;
}