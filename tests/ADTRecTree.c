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

void test_rectree(void) {
	// create με αρχικά στοιχεία
    Pointer value = create_int(4);
    RecTree treetest = rectree_create(value, REC_TREE_EMPTY, REC_TREE_EMPTY);
    TEST_ASSERT(rectree_value(treetest) == value);
    TEST_ASSERT(rectree_left(treetest) == REC_TREE_EMPTY);
    TEST_ASSERT(rectree_right(treetest) == REC_TREE_EMPTY);
    
    free(value);
    rectree_destroy(treetest);

    Pointer value1 = create_int(3);
	RecTree tree1 = rectree_create(value1, REC_TREE_EMPTY, REC_TREE_EMPTY);
    TEST_ASSERT(rectree_value(tree1) == value1);


    Pointer value2 = create_int(9);
    Pointer value3 = create_int(5);
    RecTree tree2 = rectree_create(value2, REC_TREE_EMPTY, REC_TREE_EMPTY);
    RecTree tree = rectree_create(value3, tree1, tree2);
	TEST_ASSERT(tree1 != REC_TREE_EMPTY);
    TEST_ASSERT(tree2 != REC_TREE_EMPTY);
    TEST_ASSERT(tree != REC_TREE_EMPTY);
	TEST_ASSERT(rectree_size(tree) == 3);
    TEST_ASSERT(rectree_left(tree) == tree1);
    TEST_ASSERT(rectree_right(tree) == tree2);
    rectree_destroy(tree);
    TEST_ASSERT(tree1 != REC_TREE_EMPTY);
    TEST_ASSERT(tree2 != REC_TREE_EMPTY);
    free(value1);
    free(value2);
    free(value3);
    rectree_destroy(tree1);
    rectree_destroy(tree2);
}	


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "rectree_test", test_rectree },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
