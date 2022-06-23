#ifndef KI_RWU_C_NODE_H
#define KI_RWU_C_NODE_H

#include <stdlib.h>
#include <memory.h>

struct Node;

typedef struct NodeValue {
    /// A generic type that holds the actual node innerValue.
    /// Can be any type that is suitable for the given problem
    void *innerValue;

    /// Generates all successors of a given node.
    /// Stores the amount of generated successors in second argument.
    /// Returns a list of the successors.
    struct Node **(*successors)(struct Node *, int *);

    /// Check if target node is reached.
    /// Returns 1 if target is reached, else 0
    int (*is_target_reached)(struct Node *, struct Node *);
} NodeValue;

typedef struct Node {
    struct Node *parent;
    NodeValue *value;
} Node;

typedef struct HeuristicNode {
    Node *actualNode;
    int heuristic_costs;
    int heuristic_estimation;
} HeuristicNode;

Node *create_node(Node *parent, NodeValue *value);
HeuristicNode *create_heuristic_node(HeuristicNode *parent, int heuristic_costs, int heuristic_estimation, NodeValue *value);

void free_node(Node *node);
void free_nodes(Node **nodes, int n);
void free_heuristic_node(HeuristicNode *node);

Node **append_nodes_to_list(Node **list, int *listSize, Node **newNodes, int newNodesSize);

#endif //KI_RWU_C_NODE_H
