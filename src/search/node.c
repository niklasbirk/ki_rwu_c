#include "node.h"

Node *create_node(Node *parent, NodeValue *value)
{
    Node *node = malloc(sizeof(Node));

    node->parent = parent;
    node->value = value;

    return node;
}

HeuristicNode *create_heuristic_node(HeuristicNode *parent, int heuristic_costs, int heuristic_estimation, NodeValue *value)
{
    Node node = {
            .parent = parent->actualNode,
            .value = value
    };

    HeuristicNode *heuristicNode = malloc(sizeof(HeuristicNode));

    heuristicNode->actualNode = &node;
    heuristicNode->heuristic_costs = heuristic_costs;
    heuristicNode->heuristic_estimation = heuristic_estimation;

    return heuristicNode;
}

void free_node(Node *node)
{
    free(node);
}

void free_nodes(Node **nodes, int n)
{
    for (int i = 0; i < n; i++)
    {
        free_node(nodes[i]);
    }
}

void free_heuristic_node(HeuristicNode *node)
{
    free_nodes(&(node->actualNode), 1);
    free(node);
}

Node **append_nodes_to_list(Node **list, int listSize, Node **newNodes, int newNodesSize)
{
    int newListSize = listSize + newNodesSize;

    Node **newList = realloc(list, newListSize * sizeof(Node));

    for (int i = 0; i < newNodesSize; i++)
    {
        newList[i + listSize] = newNodes[i];
    }

    return newList;
}