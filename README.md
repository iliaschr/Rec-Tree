![run-tests](../../workflows/run-tests/badge.svg)

## 2023 Project 2

Εκφώνηση: https://k08.chatzi.org/projects/project2/


### Προσωπικά στοιχεία

__Όνομα__: ΗΛΊΑΣ ΧΡΥΣΌΓΕΛΟΣ

__Α.Μ.__: sdi2200217

### Ασκήσεις που παραδίδονται

Συμπληρώστε εδώ τις ασκήσεις (και τυχόν bonus) που παραδίδετε. Αν κάποια άσκηση
βρίσκεται σε μη αναμενόμενα αρχεία αναφέρετε και τα αρχεία αυτά.

- Άσκηση 1
- Άσκηση 2 
- Άσκηση 3
- Άσκηση 4
- Άσκηση 5

### Documentation

Συμπληρώστε εδώ __όσο documentation χρειάζεται__ ώστε οι βαθμολογητές να
κατανοήσουν πλήρως τις λύσεις σας και να τις βαθμολογήσουν ανάλογα. Αυτό θα
πρέπει να γίνει ανεξάρτητα με το αν ο κώδικάς σας είναι καλά σχολιασμένος,
πράγμα που συνιστάται.

- Πολυπλοκότητα άσκηση 2:
    rectree_create: O(logn) επειδή χρησιμοποιούμε την map_find
    rectree_size: O(logn)
    rectree_destroy: O(1)
    rectree_value: O(logn)
    rectree_left: O(logn)
    rectree_right: O(logn)
    σε σχέση με της UsingLinkedTree που είναι όλες Ο(1).

- Πολυπλοκότητα άσκηση 3:
    rectree_get_subtree: O(logn) στη χειρότερη περίπτωση κάνουμε όσες κινήσεις όσο είναι και το ύψος του δέντρου, που είναι logn άφου αν έχουμε n υπόδεντρα.
    rectree_replace_subtree: Ο(logn+logn)= O(logn) αφου έχει τη get_subtree και διασχίζει το ύψος του δέντρου.


- Πολυπλοκότητα άσκηση 4: εξαρτάται ποια υλοποίηση χρησιμοποιούμε
    -με LinkedTree ADTRecTree:
        comptree_create: O(1)
        comptree_size: O(1)
        comptree_insert_last: O(logn)
        comptree_remove_last: O(logn)
        comptree_get_at: O(logn)
        comptree_replace: O(logn)
        comptree_destroy: O(1)
        comptree_value: O(1)
        comptree_left: O(1)
        comptree_right: O(1)
    
    -με ADTMap ADTRecTree:
        comptree_create: O(logn)
        comptree_size: O(logn)
        comptree_insert_last: O(logn)
        comptree_remove_last: O(logn)
        comptree_get_at: O(logn)
        comptree_replace: O(logn)
        comptree_destroy: O(1)
        comptree_value: O(logn)
        comptree_left: O(logn)
        comptree_right: O(logn)




