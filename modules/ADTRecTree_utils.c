#include "../include/ADTRecTree_utils.h"


// Επιστρέφει το υποδέντρο του tree στη θέση pos. Η αρίθμηση των θέσεων ξεκινάει
// από το 0 (ρίζα) και κινείται κατά επίπεδα, τα παιδιά της ρίζας έχουν θέση 1
// και 2, τα δικά τους παιδιά έχουν θέσεις 3,4,5,6, κλπ. Αν το υποδέντρο δεν
// υπάρχει θα επιστρέφεται REC_TREE_EMPTY. 

RecTree rectree_get_subtree(RecTree tree, int pos){
    
    if(tree == REC_TREE_EMPTY) //Αν το δέντρο δεν υπάρχει τότε επιστρέφεται REC_TREE_EMPTY
        return REC_TREE_EMPTY;
    else if(pos == 0)
        return tree;
    int BorderL = 1;
    int BorderH = 2;
    int count = 2;
    int stage = 1;
    RecTree currtree = tree;
    while(!(pos >= BorderL && pos <= BorderH)){ //Βρίσκουμε σε ποιο stage είναι το pos
        BorderL = 1 + BorderH;
        count *= 2;
        BorderH = BorderL + count - 1;
        stage++;
    }
    

    for(int i = 0; i < stage; i++){ //Επανάληψη μέχρι να φτάσουμε στο stage
        int comptree = (BorderL + BorderH) / 2; //comparison tree
        if(pos > comptree){ //αριστερά ή δεξία ανάλογα
            

            
            if(rectree_right(currtree) == REC_TREE_EMPTY) //current tree
                return REC_TREE_EMPTY; 
            else{
                BorderL = comptree + 1;
                currtree = rectree_right(currtree);
            }
            
        }
        else if(pos <= comptree){


            if(rectree_left(currtree) == REC_TREE_EMPTY)
                return REC_TREE_EMPTY;
            else{
                BorderH = comptree;
                currtree = rectree_left(currtree);
            }
        }

    }
    return currtree;
}

// Δημιουργεί και επιστρέφει ένα νέο δέντρο, το οποίο προκύπτει αντικαθιστώντας
// το υποδέντρο του tree στη θέση pos με το subtree που δίνεται.  Η θέση pos
// πρέπει να αντιστοιχεί είτε σε υπάρχον κόμβο (που αντικαθίσταται), είτε στο
// κενό παιδί ενός υπάρχοντος κόμβου (οπότε προστίθεται εκεί το subtree).  Αν το
// tree είναι κενό τότε επιστρέφεται το ίδιο το subtree.
//
// Η συνάρτηση καταστρέφεται αυτόματα τόσο το παλιό υποδέντρο που αντικαθίσταται
// (αν υπάρχει), καθώς και όλους τους προγόνους του που μεταβάλλονται (οπότε
// ξαναδημιουργούνται).

RecTree rectree_replace_subtree(RecTree tree, int pos, RecTree subtree){
    if(pos == 0){
        rectree_destroy(tree);
        return subtree;
    }
    if(tree == REC_TREE_EMPTY)
        return subtree;

    int parentpos = (pos-1)/2; //Πάμε προς τα πάνω

    RecTree parent = rectree_get_subtree(tree, parentpos); //Πάνω tree
    RecTree returntree; 
    if(pos % 2 != 0){ //είναι αριστερά
        rectree_destroy(rectree_left(parent));
        returntree = rectree_create(rectree_value(parent), subtree, rectree_right(parent) );
    }
    else{
        rectree_destroy(rectree_right(parent));
        returntree = rectree_create(rectree_value(parent), rectree_left(parent), subtree  );
    }
    
    return rectree_replace_subtree(tree, parentpos, returntree); //Κάνει replace τα trees μέχρι να φτάσει
    //στις αρχικές συνθήκες
}