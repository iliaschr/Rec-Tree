///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Priority Queue μέσω σωρού.
//
///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include "../include/ADTCompTree.h"
#include "ADTPriorityQueue.h"
#include "ADTVector.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί Vector

//Συναντάμε πολλά +1, -1, -2 κλπ. επειδή προσπαθώ από 1-based που είναι να το κάνω 0-based


// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	CompTree tree;				// Τα δεδομένα, σε Vector ώστε να έχουμε μεταβλητό μέγεθος χωρίς κόπο
	CompareFunc compare;		// Η διάταξη
	DestroyFunc destroy_value;	// Συνάρτηση που καταστρέφει ένα στοιχείο του vector.
};


// Βοηθητικές συναρτήσεις ////////////////////////////////////////////////////////////////////////////

// Προσοχή: στην αναπαράσταση ενός complete binary tree με πίνακα, είναι βολικό τα ids των κόμβων να
// ξεκινάνε από το 1 (ρίζα), το οποίο απλοποιεί τις φόρμουλες για εύρεση πατέρα/παιδιών. Οι θέσεις
// ενός vector όμως ξεκινάνε από το 0. Θα μπορούσαμε απλά να αφήσουμε μία θέση κενή, αλλά δεν είναι ανάγκη,
// μπορούμε απλά να αφαιρούμε 1 όταν διαβάζουμε/γράφουμε στο vector. Για απλοποίηση του κώδικα, η
// πρόσβαση στα στοιχεία του vector γίνεται από τις παρακάτω 2 βοηθητικές συναρτήσεις.

// Επιστρέφει την τιμή του κόμβου node_id

static Pointer node_value(PriorityQueue pqueue, int node_id) {
	return comptree_value(comptree_get_at(pqueue->tree, node_id));
}

// Ανταλλάσει τις τιμές των κόμβων node_id1 και node_id2

static void node_swap(PriorityQueue pqueue, int node_id1, int node_id2) {
	// τα node_ids είναι 1-based, το node_id αποθηκεύεται στη θέση node_id - 1
	if(node_id1 != node_id2){
		Pointer value1 = node_value(pqueue, node_id1);
		Pointer value2 = node_value(pqueue, node_id2);

		CompTree tree1 = comptree_get_at(pqueue->tree, node_id1);
		CompTree tree2 = comptree_get_at(pqueue->tree, node_id2);

		CompTree temp1 = comptree_create(value2, comptree_left(tree1), comptree_right(tree1));
		CompTree temp2 = comptree_create(value1, comptree_left(tree2), comptree_right(tree2));
		
		pqueue->tree = comptree_replace(pqueue->tree, node_id1, temp1);
		pqueue->tree = comptree_replace(pqueue->tree, node_id2, temp2);	
	}
}

// Αποκαθιστά την ιδιότητα του σωρού.
// Πριν: όλοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού, εκτός από
//       τον node_id που μπορεί να είναι _μεγαλύτερος_ από τον πατέρα του.
// Μετά: όλοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού.

static void bubble_up(PriorityQueue pqueue, int node_id) {
	// Αν φτάσαμε στη ρίζα, σταματάμε
	if (node_id == 0)
		return;

	int parent = (node_id - 1) / 2;		// Ο πατέρας του κόμβου. Τα node_ids είναι 1-based

	// Αν ο πατέρας έχει μικρότερη τιμή από τον κόμβο, swap και συνεχίζουμε αναδρομικά προς τα πάνω
	if (pqueue->compare(node_value(pqueue, parent), node_value(pqueue, node_id)) < 0) {
		node_swap(pqueue, parent, node_id);
		bubble_up(pqueue, parent);
	}
}

// Αποκαθιστά την ιδιότητα του σωρού.
// Πριν: όλοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού, εκτός από τον
//       node_id που μπορεί να είναι _μικρότερος_ από κάποιο από τα παιδιά του.
// Μετά: όλοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού.

static void bubble_down(PriorityQueue pqueue, int node_id) {
	// βρίσκουμε τα παιδιά του κόμβου (αν δεν υπάρχουν σταματάμε)
	int left_child = (node_id + 1) * 2 - 1;
	int right_child = left_child + 1;

	int size = pqueue_size(pqueue);
	if (left_child >= size)
		return;

	// βρίσκουμε το μέγιστο από τα 2 παιδιά
	int max_child = left_child;
	if (right_child < size && pqueue->compare(node_value(pqueue, left_child), node_value(pqueue, right_child)) < 0)
			max_child = right_child;

	// Αν ο κόμβος είναι μικρότερος από το μέγιστο παιδί, swap και συνεχίζουμε προς τα κάτω
	if (pqueue->compare(node_value(pqueue, node_id), node_value(pqueue, max_child)) < 0) {
		node_swap(pqueue, node_id, max_child);
		bubble_down(pqueue, max_child);
	}
}

// Αρχικοποιεί το σωρό από τα στοιχεία του vector values.

// static void naive_heapify(PriorityQueue pqueue, Vector values) {
// 	// Απλά κάνουμε insert τα στοιχεία ένα ένα.
// 	// TODO: υπάρχει πιο αποδοτικός τρόπος να γίνει αυτό!
// 	int size = vector_size(values);
// 	for (int i = 0; i < size; i++)
// 		pqueue_insert(pqueue, vector_get_at(values, i));
// }

static CompTree build_tree(Vector values, int pos){
	int size = vector_size(values);

	if(pos >= size)
		return COMP_TREE_EMPTY; //Αν είναι εκτός του size τότε επιστρέφουμε COMP_TREE_EMPTY, επίσης >= γιατί είναι 1-based
	
	if(pos<= size && pos >= size/2) //Αν είναι φύλλο του δέντρου τότε έχουμε COMP_TREE_EMPY children
		return comptree_create(vector_get_at(values, pos), COMP_TREE_EMPTY, COMP_TREE_EMPTY);

	CompTree tree = comptree_create(vector_get_at(values, pos), build_tree(values, 2 * pos + 1), build_tree(values, 2 * pos + 2)); //π.χ. αν ποσ = 0 τότε θα πάμε στις θέσεις 1, 2 οπότε τα ποσ είναι σωστά
	return tree;
}

static void efficient_heapify(PriorityQueue pqueue, Vector values){
    // int size = vector_size(values); // This the bad way to insert
    // for(int i = 0; i < size; i++) 
	// 	pqueue->tree = comptree_insert_last(pqueue->tree, vector_get_at(values, i));
	pqueue->tree = build_tree(values, 0);
	int size = pqueue_size(pqueue);
    for(int i = (size-2)/2; i >= 0; i--) //Ξεκινάμε απο το 0 οπότε -1 και όπως βρίσκαμε το parent χρειάζομαστε άλλο ένα -1.
        bubble_down(pqueue, i);
}

// Συναρτήσεις του ADTPriorityQueue //////////////////////////////////////////////////

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	assert(compare != NULL);	// LCOV_EXCL_LINE

	PriorityQueue pqueue = malloc(sizeof(*pqueue));
	pqueue->compare = compare;
	pqueue->destroy_value = destroy_value;

	// Δημιουργία του vector που αποθηκεύει τα στοιχεία.
	// ΠΡΟΣΟΧΗ: ΔΕΝ περνάμε την destroy_value στο vector!
	// Αν την περάσουμε θα καλείται όταν κάνουμε swap 2 στοιχεία, το οποίο δεν το επιθυμούμε.
	pqueue->tree = COMP_TREE_EMPTY; //pqueue->tree = vector_create(0, NULL);


	// Αν values != NULL, αρχικοποιούμε το σωρό.
	if (values != NULL)
		efficient_heapify(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	return comptree_size(pqueue->tree);
}

Pointer pqueue_max(PriorityQueue pqueue) {
	return node_value(pqueue, 0);		// root
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) {
	// Προσθέτουμε την τιμή στο τέλος το σωρού
	pqueue->tree = comptree_insert_last(pqueue->tree, value); //vector_insert_last(pqueue->vector, value);

 	// Ολοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού εκτός από τον τελευταίο, που μπορεί να είναι
	// μεγαλύτερος από τον πατέρα του. Αρα μπορούμε να επαναφέρουμε την ιδιότητα του σωρού καλώντας
	// τη bubble_up γα τον τελευταίο κόμβο (του οποίου το 1-based id ισούται με το νέο μέγεθος του σωρού).
	bubble_up(pqueue, pqueue_size(pqueue) - 1);
}

void pqueue_remove_max(PriorityQueue pqueue) {
	int last_node = pqueue_size(pqueue) - 1;
	assert(last_node + 1 != 0);		// LCOV_EXCL_LINE
	//+1 επειδή ξεκινάει από το 0
	node_swap(pqueue, 0, last_node); //το ανταλλάζουμε και μετά το διαγράφουμε
	// Destroy την τιμή που αφαιρείται
	if (pqueue->destroy_value != NULL)
		pqueue->destroy_value(comptree_value(comptree_get_at(pqueue->tree, last_node))); //pqueue->destroy_value(pqueue_max(pqueue));
	
	// Αντικαθιστούμε τον πρώτο κόμβο με τον τελευταίο και αφαιρούμε τον τελευταίο

	pqueue->tree = comptree_remove_last(pqueue->tree);

 	// Ολοι οι κόμβοι ικανοποιούν την ιδιότητα του σωρού εκτός από τη νέα ρίζα
 	// που μπορεί να είναι μικρότερη από κάποιο παιδί της. Αρα μπορούμε να
 	// επαναφέρουμε την ιδιότητα του σωρού καλώντας τη bubble_down για τη ρίζα.
	bubble_down(pqueue, 0);
	
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	DestroyFunc old = pqueue->destroy_value;
	pqueue->destroy_value = destroy_value;
	return old;
}

void pqueue_destroy(PriorityQueue pqueue) {
	// Αντί να κάνουμε εμείς destroy τα στοιχεία, είναι απλούστερο να
	// προσθέσουμε τη destroy_value στο vector ώστε να κληθεί κατά το vector_destroy.
	for(int i = pqueue_size(pqueue) - 1; i >= 0; i--){
		if (pqueue->destroy_value != NULL)
		pqueue->destroy_value(comptree_value(comptree_get_at(pqueue->tree, i))); //pqueue->destroy_value(pqueue_max(pqueue));

		// Αντικαθιστούμε τον πρώτο κόμβο με τον τελευταίο και αφαιρούμε τον τελευταίο

		pqueue->tree = comptree_remove_last(pqueue->tree);
	}
	//vector_set_destroy_value(pqueue->vector, pqueue->destroy_value);
	//vector_destroy(pqueue->vector);

	free(pqueue);
}