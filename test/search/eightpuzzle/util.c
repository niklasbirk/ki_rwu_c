#include "util.h"

void print_eightpuzzle_solution(Node *sol)
{
    printf("----------------------------\n");
    printf("END\n\n");

    Node *node = sol;
    while (node != NULL)
    {
        print_eightpuzzle_state(node->value->innerValue);
        printf("\n");
        node = node->parent;
    }

    printf("\nSTART\n");
    printf("----------------------------");
}

void print_eightpuzzle_state(Dyn2DIntArray *arr)
{
    for (int i = 0; i < 3; ++i)
    {
        printf("[");

        for (int j = 0; j < 3; ++j)
        {
            printf(" %d ", arr->values[i][j]);
        }

        printf("]\n");
    }
}