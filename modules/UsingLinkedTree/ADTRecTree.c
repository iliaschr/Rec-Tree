///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "../../include/ADTRecTree.h"


// Προς υλοποίηση...


//  Ένα δέντρο είναι pointer σε αυτό το struct
struct rec_tree {
	Pointer value;	//Ρίζα
	RecTree left;	//Αριστερό υποδεντρο
	RecTree right;	//Δεξί υποδεντρο
	int size;
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	RecTree rectree = malloc(sizeof(struct rec_tree)); //Δημιουργεί ένα νέο δέντρο
	rectree->value = value; //με τιμή (στη ρίζα) value
	rectree->left = left;
	rectree->right = right; //και υποδέντρα left και right.
	rectree->size = 1 + (left == REC_TREE_EMPTY ? 0 : left->size) + (right == REC_TREE_EMPTY ? 0 : right->size);
	return rectree; //επιστρέφει ένα νέο δέντρο
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {
	if(tree == REC_TREE_EMPTY)
		return 0;
	return tree->size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void rectree_destroy(RecTree tree) {
	free(tree); // Ελευθερώνει τη μνήμη που δεσμεύει το δέντρο tree (ΔΕΝ καταστρέφει τα υποδέντρα του).
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {
	return tree->value;
}

RecTree rectree_left(RecTree tree) {
	return tree->left;
}

RecTree rectree_right(RecTree tree) {
	return tree->right;
}

