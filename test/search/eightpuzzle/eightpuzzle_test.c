#include "example_eightpuzzle.h"
#include <assert.h>
#include <stdio.h>

void test_equal_state_values()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    int target[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    assert(equal_state_values(state, target));
}

void test_not_equal_state_values()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    int target[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    assert(!equal_state_values(state, target));
}

void test_detect_empty_position()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    int i, j;

    detect_empty_position(state, &i, &j);

    assert(i == 2);
    assert(j == 1);
}

void test_swap_state_field()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    swap_state_field(state, 2, 1, 2, 2);

    assert(state[2][1] == 8);
    assert(state[2][2] == 0);
}

void test_copy_of_state()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    int target[3][3];

    copy_of_state(state, target);

    assert(target != state);
    assert(target[0][0] == state[0][0]);
    assert(target[0][1] == state[0][1]);
    assert(target[0][2] == state[0][2]);
    assert(target[1][0] == state[1][0]);
    assert(target[1][1] == state[1][1]);
    assert(target[1][2] == state[1][2]);
    assert(target[2][0] == state[2][0]);
    assert(target[2][1] == state[2][1]);
    assert(target[2][2] == state[2][2]);
}

void test_eightpuzzle_is_target_reached()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    int targetInnerValue[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    NodeValue stateValue = {
            .innerValue = state
    };
    NodeValue targetValue = {
            .innerValue = targetInnerValue
    };

    Node *node = create_node(NULL, &stateValue);
    Node *target = create_node(NULL, &targetValue);

    assert(eightpuzzle_is_target_reached(node, target));

    free_node(node);
    free_node(target);
}

void test_eightpuzzle_is_target_not_reached()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    int targetInnerValue[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    NodeValue stateValue = {
            .innerValue = state
    };
    NodeValue targetValue = {
            .innerValue = targetInnerValue
    };

    Node *node = create_node(NULL, &stateValue);
    Node *target = create_node(NULL, &targetValue);

    assert(!eightpuzzle_is_target_reached(node, target));

    free_node(node);
    free_node(target);
}

void test_eightpuzzle_successors()
{
    int state[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 0, 8}
    };

    int stateSwapped1[3][3] = {
            {1, 2, 3},
            {4, 0, 6},
            {7, 5, 8}
    };

    int stateSwapped2[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
    };

    int stateSwapped3[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {0, 7, 8}
    };

    NodeValue stateValue = {
            .innerValue = state
    };

    Node *node = create_node(NULL, &stateValue);
    int amount;

    Node **successors = eightpuzzle_successors(node, &amount);

    assert(amount == 3);
//    assert(equal_state_values(successors[0]->value->innerValue, stateSwapped1));
//    assert(equal_state_values(successors[1]->value->innerValue, stateSwapped2));
//    assert(equal_state_values(successors[2]->value->innerValue, stateSwapped3));

    free_node(node);
    free_nodes(successors, amount);

}

int main(void)
{
    test_equal_state_values();
    test_not_equal_state_values();

    test_detect_empty_position();

    test_swap_state_field();

    test_copy_of_state();

    test_eightpuzzle_is_target_reached();
    test_eightpuzzle_is_target_not_reached();

    test_eightpuzzle_successors();

    return 0;
}
