#ifndef KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H
#define KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H

#include "../../../include/lib_ki_rwu_c.h"
#include "dyn_2d_int_array.h"

typedef enum Direction {
    TOP,
    RIGHT,
    DOWN,
    LEFT
} Direction;

Node **eightpuzzle_successors(Node *node, int *k);
int eightpuzzle_is_target_reached(Node *node, Node *target);

void calculate_indizes_from_direction(Direction i, int x, int y, int *k, int *l);
void copy_of_state(Dyn2DIntArray *src, Dyn2DIntArray *dest);
void swap_state_field(Dyn2DIntArray *state, int i, int j, int k, int l);
void detect_empty_position(Dyn2DIntArray *state, int *i, int *j);
int equal_state_values(Dyn2DIntArray *state, Dyn2DIntArray *target);

#endif //KI_RWU_C_EXAMPLE_EIGHTPUZZLE_H
