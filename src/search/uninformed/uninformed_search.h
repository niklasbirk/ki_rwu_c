#include "../node.h"

#ifndef KI_RWU_C_UNINFORMED_SEARCH_H
#define KI_RWU_C_UNINFORMED_SEARCH_H

Node *breadth_first_search(Node **nodes, int n, Node *target);
Node *depth_first_search(Node *nodes, int n, Node *target);
Node *iterative_deepening(Node *nodes, int n, Node *target);

#endif //KI_RWU_C_UNINFORMED_SEARCH_H
