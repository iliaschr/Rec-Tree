///////////////////////////////////////CompTree////////////////////////////
//
// Υλοποίηση του ADT CompTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "../../include/ADTRecTree.h"
#include "../../include/ADTCompTree.h"
#include "../../include/ADTRecTree_utils.h"


// Προς υλοποίηση...


//  Ένα δέντρο είναι pointer σε αυτό το struct
struct comp_tree {
	//RIP
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

CompTree comptree_create(Pointer value, CompTree left, CompTree right) {

    return (CompTree)rectree_create(value, (RecTree)left, (RecTree)right);
    
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int comptree_size(CompTree tree) {
    if(tree == COMP_TREE_EMPTY) return 0;
	return rectree_size((RecTree)tree);
}

CompTree comptree_insert_last(CompTree tree, Pointer value){

    CompTree returntree = comptree_create(value, COMP_TREE_EMPTY, COMP_TREE_EMPTY);
    if(tree == COMP_TREE_EMPTY)
        return returntree;
    return (CompTree)rectree_replace_subtree((RecTree)tree, rectree_size((RecTree)tree) , (RecTree)returntree);
}

CompTree comptree_remove_last(CompTree tree){
    if(tree == COMP_TREE_EMPTY)
        return COMP_TREE_EMPTY;
    return (CompTree)rectree_replace_subtree((RecTree)tree, rectree_size((RecTree)tree) - 1, (RecTree)COMP_TREE_EMPTY);
}

CompTree comptree_get_at(CompTree tree, int pos){
    return (CompTree)rectree_get_subtree((RecTree)tree, pos);
}

CompTree comptree_replace(CompTree tree, int pos, CompTree subtree){
    return (CompTree)rectree_replace_subtree((RecTree)tree, pos, (RecTree)subtree);
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void comptree_destroy(CompTree tree) {
    rectree_destroy((RecTree)tree);
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer comptree_value(CompTree tree) {
	return rectree_value((RecTree)tree);
}

CompTree comptree_left(CompTree tree) {
	return (CompTree)rectree_left((RecTree)tree);
}

CompTree comptree_right(CompTree tree) {
	return (CompTree)rectree_right((RecTree)tree);
}

