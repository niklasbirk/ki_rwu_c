#include "example_eightpuzzle.h"

Node **eightpuzzle_successors(Node *node, int *amount)
{
    Node **successors = NULL;
    int successorsListSize = 0;
    int x, y;

    detect_empty_position(node->value->innerValue, &y, &x);

    for (int i = 0; i < 4; i++)
    {
        int tmpNewState[3][3];
        copy_of_state(node->value->innerValue, tmpNewState);

        int k, l;

        switch(i)
        {
            case 0:
                k = y - 1;
                l = x;
                break;
            case 1:
                k = y;
                l = x + 1;
                break;
            case 2:
                k = y + 1;
                l = x;
                break;
            case 3:
                k = y;
                l = x - 1;
                break;
            default:
                break;
        }

        if (k >= 0 && k <= 2 && l >= 0 && l <= 2)
        {
            swap_state_field(tmpNewState, y, x, k, l);

            int **newState = malloc(sizeof(int *) * 3);

            for (int j = 0; j < 3; ++j)
            {
                newState[j] = malloc(sizeof(int) * 3);
            }

            for (int j = 0; j < 3; ++j)
            {
                for (int o = 0; o < 3; ++o)
                {
                    newState[j][o] = tmpNewState[j][o];
                }
            }

            NodeValue *newStateNodeValue = malloc(sizeof(Node *));
            newStateNodeValue->innerValue = newState;
            newStateNodeValue->successors = node->value->successors;
            newStateNodeValue->is_target_reached = node->value->is_target_reached;

            Node *successor = create_node(node, newStateNodeValue);
            Node **newSuccessor = &successor;

            if (!equal_state_values(tmpNewState, node->value->innerValue)
                && (node->parent == NULL || !equal_state_values(tmpNewState, node->parent->value->innerValue)))
            {
                successors = append_nodes_to_list(successors, successorsListSize++, newSuccessor, 1);
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

void copy_of_state(int src[3][3], int dest[3][3])
{
    memcpy(dest, src, sizeof(int) * 3 * 3);
}

void swap_state_field(int state[3][3], int i, int j, int k, int l)
{
    int tmp = state[k][l];
    state[k][l] = state[i][j];
    state[i][j] = tmp;
}

void detect_empty_position(int state[3][3], int *i, int *j)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (state[row][col] == 0)
            {
                *i = row;
                *j = col;

                return;
            }
        }
    }
}

int equal_state_values(int state[3][3], int target[3][3])
{
    if (state == NULL)
    {
        return 0;
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (state[row][col] != target[row][col])
            {
                return 0;
            }
        }
    }

    return 1;
}
