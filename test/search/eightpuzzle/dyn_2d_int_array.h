#include <stdlib.h>

#ifndef KI_RWU_C_DYN_2D_INT_ARRAY_H
#define KI_RWU_C_DYN_2D_INT_ARRAY_H

typedef struct Dyn2DIntArray {
    int values[3][3];
} Dyn2DIntArray;

Dyn2DIntArray *create_dyn_2d_int_array();

void free_dyn_array(Dyn2DIntArray *arr);

#endif //KI_RWU_C_DYN_2D_INT_ARRAY_H
