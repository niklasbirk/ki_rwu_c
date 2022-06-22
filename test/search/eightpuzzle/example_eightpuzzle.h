#ifndef KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H
#define KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H

#include "../../../include/lib_ki_rwu_c.h"

Node **eightpuzzle_successors(Node *node, int *k);
int eightpuzzle_is_target_reached(Node *node, Node *target);

void copy_of_state(int src[3][3], int dest[3][3]);
void swap_state_field(int state[3][3], int i, int j, int k, int l);
void detect_empty_position(int state[3][3], int *i, int *j);
int equal_state_values(int state[3][3], int target[3][3]);

#endif //KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H
