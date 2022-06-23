#include "../eightpuzzle/dyn_2d_int_array.h"
#include "../eightpuzzle/example_eightpuzzle.h"
#include "../eightpuzzle/util.h"
#include "../../../src/search/uninformed/uninformed_search.h"

void test_should_return_correct_node_TMP()
{
    Dyn2DIntArray state = {
            {
                    {1, 2, 3},
                    {4, 5, 0},
                    {7, 8, 6}
            }
    };
    NodeValue stateValue = {
            .innerValue = &state,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *node = create_node(NULL, &stateValue);

    Dyn2DIntArray target = {
            {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 0}
            }
    };
    NodeValue targetValue = {
            .innerValue = &target,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *targetNode = create_node(NULL, &targetValue);

    Node *actual = breadth_first_search(&node, 1, targetNode);

    print_eightpuzzle_solution(actual);

    free_node(node);
    free_node(targetNode);
    free_node(actual);
}

/****************************
 ********** FAILS ***********
 ****************************/
void test_should_return_correct_node()
{
    Dyn2DIntArray state = {
            {
                    {5, 0, 3},
                    {2, 1, 6},
                    {4, 7, 8}
            }
    };
    NodeValue stateValue = {
            .innerValue = &state,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *node = create_node(NULL, &stateValue);

    Dyn2DIntArray target = {
            {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 0}
            }
    };
    NodeValue targetValue = {
            .innerValue = &target,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *targetNode = create_node(NULL, &targetValue);

    Node *actual = breadth_first_search(&node, 1, targetNode);

    print_eightpuzzle_solution(actual);

    free_node(node);
    free_node(targetNode);
    free_node(actual);
}

void test_should_return_correct_cubek_node()
{
    Dyn2DIntArray state = {
            {
                {2, 0, 4},
                {6, 7, 1},
                {8, 5, 3}
            }
    };
    NodeValue stateValue = {
            .innerValue = &state,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *node = create_node(NULL, &stateValue);

    Dyn2DIntArray target = {
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 0}
            }
    };
    NodeValue targetValue = {
            .innerValue = &target,
            .is_target_reached = eightpuzzle_is_target_reached,
            .successors = eightpuzzle_successors
    };
    Node *targetNode = create_node(NULL, &targetValue);

    Node *actual = breadth_first_search(&node, 1, targetNode);

    print_eightpuzzle_solution(actual);

    free_node(node);
    free_node(targetNode);
    free_node(actual);
}

int main(void)
{
    test_should_return_correct_node_TMP();

    // Fails because of SegFault.
    //
    // But why?
    // Too many nodes in list?
    // Memory Problems because of bad memory allocations and freeing?
//    test_should_return_correct_node();
//    test_should_return_correct_cubek_node();

    return 0;
}
