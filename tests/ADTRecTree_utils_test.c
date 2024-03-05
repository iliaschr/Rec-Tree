//////////////////////////////////////////////////////////////////
//
// Unit tests για τον ADT Priority Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "../include/ADTRecTree.h"
#include "../include/ADTRecTree_utils.h"


Pointer create_int(int i){
    int* value = malloc(sizeof(int *));
    *value = i;
    return (Pointer) value;
}

void test_rectree_utils(void){
    Pointer value = create_int(3);
    Pointer value2 = create_int(9);
    Pointer value3 = create_int(5);
    RecTree tree1 = rectree_create(value, REC_TREE_EMPTY, REC_TREE_EMPTY);
    RecTree tree2 = rectree_create(value2, REC_TREE_EMPTY, REC_TREE_EMPTY);
    RecTree tree = rectree_create(value3, tree1, tree2);
    TEST_ASSERT(rectree_get_subtree(tree, 1) == tree1);
    TEST_ASSERT(rectree_get_subtree(tree, 3) != tree1);
    TEST_ASSERT(rectree_get_subtree(tree, 2) == tree2);
    TEST_ASSERT(rectree_get_subtree(tree, 4) == REC_TREE_EMPTY);
    rectree_destroy(tree);
    rectree_destroy(tree1);
    rectree_destroy(tree2);
    free(value);
    free(value2);
    free(value3);   

    //Create values
    Pointer value4 = create_int(13);
    Pointer value5 = create_int(11);
    Pointer value6 = create_int(7);
    Pointer value7 = create_int(26);
    Pointer value8 = create_int(20);
    Pointer value9 = create_int(14);

    
    RecTree tree3LL = rectree_create(value4, REC_TREE_EMPTY, REC_TREE_EMPTY);
    RecTree tree3L = rectree_create(value5, tree3LL, REC_TREE_EMPTY);
    RecTree tree3 = rectree_create(value6, tree3L, REC_TREE_EMPTY);
    RecTree subLR = rectree_create(value7, REC_TREE_EMPTY, REC_TREE_EMPTY);
    RecTree subL = rectree_create(value8, REC_TREE_EMPTY, subLR);
    RecTree sub = rectree_create(value9, subL, REC_TREE_EMPTY);
    RecTree new_tree = rectree_replace_subtree(tree3, 7, sub);


    TEST_ASSERT(rectree_left(rectree_left(rectree_left(new_tree))) == sub);
    TEST_ASSERT(rectree_left(rectree_left(rectree_left(rectree_left(new_tree)))) == subL);
    TEST_ASSERT(rectree_right(rectree_left(rectree_left(rectree_left(rectree_left(new_tree))))) == subLR);


    
    rectree_destroy(subLR);
    rectree_destroy(subL);
    rectree_destroy(sub);
    rectree_destroy(rectree_left(rectree_left(new_tree)));
    rectree_destroy(rectree_left(new_tree));
    rectree_destroy(new_tree);
    //Free create ints
    free(value4);
    free(value5);
    free(value6);
    free(value7);
    free(value8);
    free(value9);
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
    { "rectree_utils", test_rectree_utils },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
