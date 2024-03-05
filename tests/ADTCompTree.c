//////////////////////////////////////////////////////////////////
//
// Unit tests για τον ADT Priority Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "../include/ADTCompTree.h"
#include "../include/ADTRecTree_utils.h"


Pointer create_int(int i){
    int* value = malloc(sizeof(int *));
    *value = i;
    return (Pointer) value;
}

void test_comptree(void) {
	// create με αρχικά στοιχεία
    Pointer value = create_int(32);
    CompTree treetest = comptree_create(value, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
    TEST_CHECK(comptree_value(treetest) == value);
    TEST_CHECK(comptree_left(treetest) == COMP_TREE_EMPTY);
    TEST_CHECK(comptree_right(treetest) == COMP_TREE_EMPTY);

    comptree_destroy(treetest);

    Pointer value1 = create_int(3);
	CompTree tree1 = comptree_create(value1, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
    TEST_CHECK(comptree_value(tree1) == value1);
    

    Pointer value2 = create_int(9);
    Pointer value3 = create_int(5);
    CompTree tree2 = comptree_create(value2, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
    CompTree tree = comptree_create(value3, tree1, tree2);
	TEST_ASSERT(tree1 != COMP_TREE_EMPTY);
    TEST_ASSERT(tree2 != COMP_TREE_EMPTY);
    TEST_ASSERT(tree != COMP_TREE_EMPTY);
	TEST_ASSERT(comptree_size(tree) == 3);
    comptree_destroy(tree);
    TEST_ASSERT(tree1 != COMP_TREE_EMPTY);
    TEST_ASSERT(tree2 != COMP_TREE_EMPTY);

    //test insert
    free(value);
    free(value1);
    free(value2);
    free(value3);
    comptree_destroy(tree1);
    comptree_destroy(tree2);
    //test has no leaks
}	



// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "comptree_test", test_comptree },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
