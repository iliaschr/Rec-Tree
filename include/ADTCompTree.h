///////////////////////////////////////////////////////////////////
//
// ADT CompTree
//
// Abstract αναδρομικό (recursive) δέντρο. Κάθε δέντρο περιέχει μια
// τιμή (στη ρίζα), και δύο υποδέντρα. Τα δέντρα είναι immutable,
// δεν μπορεί να αλλάξει ούτε η τιμή τους ούτε τα υποδέντρα τους.
//
///////////////////////////////////////////////////////////////////

#pragma once // #include το πολύ μία φορά

#include "common_types.h"

// Η παρακάτω σταθερά συμβολίζει ένα κενό δέντρο
#define COMP_TREE_EMPTY (CompTree)0


//  Ένα δέντρο αναπαριστάται από τον τύπο CompTree. Ο χρήστης δε χρειάζεται να γνωρίζει το περιεχόμενο
// του τύπου αυτού, απλά χρησιμοποιεί τις συναρτήσεις CompTree_<foo> που δέχονται και επιστρέφουν CompTree.
//
// Ο τύπος αυτός ορίζεται ως pointer στο "struct comp_tree" του οποίου το περιεχόμενο είναι άγνωστο
// (incomplete struct), και εξαρτάται από την υλοποίηση του ADT CompTree.
//
typedef struct comp_tree* CompTree;


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

CompTree comptree_create(Pointer value, CompTree left, CompTree right);

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο (0 για κενά δέντρα).

int comptree_size(CompTree tree);

// Ελευθερώνει τη μνήμη που δεσμεύει το δέντρο tree (ΔΕΝ καταστρέφει τα υποδέντρα του).

void comptree_destroy(CompTree tree);

// Δημιουργεί και επιστρέφει ένα νέο δέντρο που προκύπτει από το tree μετά την προσθήκη της
// τιμής value στο "τέλος" του δέντρου (ώστε να παραμείνει complete). Τυχόν υποδέντρα που
// "μεταβάλλονται" κατά την προσθήκη αυτή καταστρέφονται αυτόματα.

CompTree comptree_insert_last(CompTree tree, Pointer value);

// Δημιουργεί και επιστρέφει ένα νέο δέντρο που προκύπτει από το tree μετά την διαγραφή του
// "τελευταίου" υποδέντρου του (ώστε να παραμείνει complete). Το υποδέντρο που αφαιρείται, και
// τυχόν υποδέντρα που "μεταβάλλονται" κατά τη διαγραφή αυτή καταστρέφονται αυτόματα.

CompTree comptree_remove_last(CompTree tree);


// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer comptree_value(CompTree tree);
CompTree comptree_left(CompTree tree);
CompTree comptree_right(CompTree tree);


CompTree comptree_get_at(CompTree tree, int pos);


CompTree comptree_replace(CompTree tree, int pos, CompTree subtree);

