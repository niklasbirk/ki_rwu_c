#include "../../include/lib_ki_rwu_c.h"
#include <assert.h>

Node **dummy_successors(Node *node, int *k)
{
    return NULL;
}

int dummy_is_target_reached(Node *node, Node *target)
{
    return 0;
}

void test_node_value()
{
    int k = 5;

    NodeValue actualNodeValue = {
            .innerValue = (int *) &k,
            .successors = dummy_successors,
            .is_target_reached = dummy_is_target_reached
    };

    assert(actualNodeValue.innerValue == &k);
    assert(*((int *) actualNodeValue.innerValue) == k);
    assert(actualNodeValue.successors(NULL, NULL) == NULL);
    assert(actualNodeValue.is_target_reached(NULL, NULL) == 0);
}

void test_create_node_without_parent()
{
    NodeValue nodeValue = {
            .innerValue = NULL,
            .successors = dummy_successors,
            .is_target_reached = dummy_is_target_reached
    };

    Node *actualNode = create_node(NULL, &nodeValue);

    assert(actualNode->parent == NULL);
    assert(actualNode->value != NULL);

    free_node(actualNode);
}

void test_create_node()
{
    NodeValue nodeValue = {
            .innerValue = NULL,
            .successors = dummy_successors,
            .is_target_reached = dummy_is_target_reached
    };

    Node expectedParent = {
            .parent = NULL,
            .value = NULL
    };

    Node *actualNode = create_node(&expectedParent, &nodeValue);

    assert(actualNode->parent != NULL);
    assert(actualNode->parent == &expectedParent);
    assert(actualNode->value != NULL);

    free_node(actualNode);
}

void test_append_one_node_to_list()
{
    NodeValue nodeValue = {
            .innerValue = NULL,
            .successors = dummy_successors,
            .is_target_reached = dummy_is_target_reached
    };

    // initial list
    Node *node1 = create_node(NULL, &nodeValue);
    Node *node2 = create_node(node1, &nodeValue);

    Node **list = malloc(sizeof(Node *) * 2);
    list[0] = node1;
    list[1] = node2;

    // to append
    Node *node3 = create_node(node2, &nodeValue);
    Node **toAppend = &node3;

    int listSize = 2;
    list = append_nodes_to_list(list, &listSize, toAppend, 1);

    assert(listSize == 3);
    assert(list[0]->parent == node1->parent);
    assert(list[1]->parent == node2->parent);
    assert(list[2]->parent == node3->parent);

    free_nodes(list, 3);
}

void test_append_three_node_to_list()
{
    NodeValue nodeValue = {
            .successors = dummy_successors,
            .is_target_reached = dummy_is_target_reached
    };

    // initial list
    Node *node1 = create_node(NULL, &nodeValue);
    Node *node2 = create_node(node1, &nodeValue);

    Node **list = malloc(sizeof(Node *) * 2);
    list[0] = node1;
    list[1] = node2;

    // to append
    Node *node3 = create_node(node2, &nodeValue);
    Node *node4 = create_node(node3, &nodeValue);
    Node *node5 = create_node(node4, &nodeValue);

    Node **toAppend = malloc(sizeof(Node *) * 3);
    toAppend[0] = node3;
    toAppend[1] = node4;
    toAppend[2] = node5;

    int listSize = 2;
    list = append_nodes_to_list(list, &listSize, toAppend, 3);

    assert(listSize == 5);
    assert(list[0]->parent == node1->parent);
    assert(list[1]->parent == node2->parent);
    assert(list[2]->parent == node3->parent);
    assert(list[3]->parent == node4->parent);
    assert(list[4]->parent == node5->parent);

    free_nodes(list, 5);
}

int main(void)
{
    test_node_value();

    test_create_node_without_parent();
    test_create_node();

    test_append_one_node_to_list();
    test_append_three_node_to_list();

    return 0;
}
