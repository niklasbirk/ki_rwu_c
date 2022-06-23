#include "example_eightpuzzle.h"

Node **eightpuzzle_successors(Node *node, int *amount)
{
    Node **successors = NULL;
    int successorsListSize = 0;
    int x, y;

    detect_empty_position(node->value->innerValue, &y, &x);

    for (int dir = TOP; dir <= LEFT; dir++)
    {
        Dyn2DIntArray *newState = create_dyn_2d_int_array();

        copy_of_state(node->value->innerValue, newState);

        int k, l;
        calculate_indizes_from_direction(dir, x, y, &k, &l);

        if (k >= 0 && k <= 2 && l >= 0 && l <= 2)
        {
            swap_state_field(newState, y, x, k, l);

            for (int j = 0; j < 3; ++j)
            {
                for (int o = 0; o < 3; ++o)
                {
                    newState->values[j][o] = newState->values[j][o];
                }
            }

            NodeValue *newStateNodeValue = malloc(sizeof(Node *));
            newStateNodeValue->innerValue = newState;
            newStateNodeValue->successors = node->value->successors;
            newStateNodeValue->is_target_reached = node->value->is_target_reached;

            Node *successor = create_node(node, newStateNodeValue);
            Node **newSuccessor = &successor;

            if (!equal_state_values(newState, node->value->innerValue)
                && (node->parent == NULL || !equal_state_values(newState, node->parent->value->innerValue)))
            {
                successors = append_nodes_to_list(successors, &successorsListSize, newSuccessor, 1);
            }
        }
    }

    *amount = successorsListSize;
    return successors;
}

int eightpuzzle_is_target_reached(Node *node, Node *target)
{
    return equal_state_values(node->value->innerValue, target->value->innerValue);
}

void calculate_indizes_from_direction(Direction i, int x, int y, int *k, int *l)
{
    switch(i)
    {
        case TOP:
            *k = y - 1;
            *l = x;
            break;
        case RIGHT:
            *k = y;
            *l = x + 1;
            break;
        case DOWN:
            *k = y + 1;
            *l = x;
            break;
        case LEFT:
            *k = y;
            *l = x - 1;
            break;
        default:
            break;
    }
}

void copy_of_state(Dyn2DIntArray *src, Dyn2DIntArray *dest)
{
    memcpy(dest->values, src->values, sizeof(int) * 3 * 3);
}

void swap_state_field(Dyn2DIntArray *state, int i, int j, int k, int l)
{
    int tmp = state->values[k][l];
    state->values[k][l] = state->values[i][j];
    state->values[i][j] = tmp;
}

void detect_empty_position(Dyn2DIntArray *state, int *i, int *j)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (state->values[row][col] == 0)
            {
                *i = row;
                *j = col;

                return;
            }
        }
    }
}

int equal_state_values(Dyn2DIntArray *state, Dyn2DIntArray *target)
{
    if (state == NULL || target == NULL)
    {
        return 0;
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (state->values[row][col] != target->values[row][col])
            {
                return 0;
            }
        }
    }

    return 1;
}
