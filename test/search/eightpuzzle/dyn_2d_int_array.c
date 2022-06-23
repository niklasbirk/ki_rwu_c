#include "dyn_2d_int_array.h"

Dyn2DIntArray *create_dyn_2d_int_array()
{
    Dyn2DIntArray *arr = malloc(sizeof(Dyn2DIntArray));

    return arr;
}

void free_dyn_array(Dyn2DIntArray *arr)
{
    free(arr);
}