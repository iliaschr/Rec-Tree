///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω ADTMap
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "../../include/ADTRecTree.h"
#include "../../include/ADTMap.h"

// Προς υλοποίηση...
static int compare_pointers(Pointer a, Pointer b){ //static γιατί χρησιμοποιειται μόνο εδώ
	return a - b; // αρνητικός, μηδέν ή θετικός, ανάλογα με τη διάταξη των a,b
}

static int count = 0;
static bool flag = false; //flag για όταν γίνεται destroy

Map TreeMap; //Δημιουργώ 4 γκλομπαλ μαπς
Map leftmap;
Map rightmap;
Map size;

struct rec_tree {
	//
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	count++;
	int size1 = 1; //Βάζουμε ένα size που το αρχικοποιούμε με 1
	if(count == 1 || flag == false){ //Δημιουργούμε τα μαπς μόνο μια φορά
		TreeMap = map_create(compare_pointers, NULL, NULL);
		leftmap = map_create(compare_pointers, NULL, NULL);
		rightmap = map_create(compare_pointers, NULL, NULL);
		size = map_create(compare_pointers, NULL, NULL);
		flag = true;
	}
	map_insert(TreeMap, (RecTree)(size_t)count, value); //Βάζει το value στο μαπ
	if(left == REC_TREE_EMPTY) //Αν είναι null τότε με βάση την εκφώνηση έχει την τιμή 0
		map_insert(leftmap, (RecTree)(size_t)count, REC_TREE_EMPTY); 
	else{
		map_insert(leftmap, (RecTree)(size_t)count, left);
		Pointer temp = map_find(size, left);
		size1 += (int)(size_t)temp; //προσθήκη size left
	}
	if(right == REC_TREE_EMPTY) //Μπορούμε να βάλουμε και απευθείας το left απλά κρατάω το if.
		map_insert(rightmap, (RecTree)(size_t)count, REC_TREE_EMPTY);	
	else{
		map_insert(rightmap, (RecTree)(size_t)count, right);
		Pointer temp = map_find(size, right);
		size1 += (int)(size_t)temp; //προσθήκη size right
	}
	map_insert(size, (RecTree)(size_t)count, (Pointer)(size_t)size1);
	
	return (RecTree)(size_t)count; //επιστρέφει ένα νέο δέντρο
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {
	if(tree == REC_TREE_EMPTY)
		return 0;
	return (int)(size_t)map_find(size, tree);
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void rectree_destroy(RecTree tree) {
	map_remove(TreeMap, tree);
	map_remove(size, tree);
	map_remove(leftmap, tree); //Σβήνουμε και αυτά καθώς δεν αντιστοιχούν πια στο μαπ
	map_remove(rightmap, tree);
	if(map_size(TreeMap) == 0){ //Αν δεν έχει άλλα στοιχεία τότε φρεε
		map_destroy(TreeMap);
		map_destroy(leftmap);
		map_destroy(rightmap);
		map_destroy(size);
		flag = false;
		count = 0;
	}
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {
	return map_find(TreeMap, tree);
}

RecTree rectree_left(RecTree tree) {
	return map_find(leftmap, tree);
}

RecTree rectree_right(RecTree tree) {
	return map_find(rightmap, tree);
}
