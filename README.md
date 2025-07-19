![run-tests](../../workflows/run-tests/badge.svg)

## 2023 Project 2

Assignment description: https://k08.chatzi.org/2023/projects/project2/

### Submitted Exercises

Fill in here the exercises (and any bonus ones) that you are submitting. If any exercise  
is located in unexpected files, mention those files as well.

- Exercise 1  
- Exercise 2  
- Exercise 3  
- Exercise 4  
- Exercise 5  

### Documentation

Fill in here __as much documentation as needed__ so that the graders can fully  
understand your solutions and grade them accordingly. This should be done  
regardless of whether your code is well-commented, which is recommended.

- Complexity of Exercise 2:
  - `rectree_create`: O(logn), because we use `map_find`
  - `rectree_size`: O(logn)
  - `rectree_destroy`: O(1)
  - `rectree_value`: O(logn)
  - `rectree_left`: O(logn)
  - `rectree_right`: O(logn)  
  Compared to the `UsingLinkedTree` implementation, where all operations are O(1).

- Complexity of Exercise 3:
  - `rectree_get_subtree`: O(logn) – in the worst case, we perform as many moves as the height of the tree, which is logn if we have n subtrees.
  - `rectree_replace_subtree`: O(logn + logn) = O(logn), since it calls `get_subtree` and traverses the height of the tree.

- Complexity of Exercise 4: depends on which implementation is used:
  
  - Using `LinkedTree` (ADTRecTree):
    - `comptree_create`: O(1)
    - `comptree_size`: O(1)
    - `comptree_insert_last`: O(logn)
    - `comptree_remove_last`: O(logn)
    - `comptree_get_at`: O(logn)
    - `comptree_replace`: O(logn)
    - `comptree_destroy`: O(1)
    - `comptree_value`: O(1)
    - `comptree_left`: O(1)
    - `comptree_right`: O(1)

  - Using `ADTMap` (ADTRecTree):
    - `comptree_create`: O(logn)
    - `comptree_size`: O(logn)
    - `comptree_insert_last`: O(logn)
    - `comptree_remove_last`: O(logn)
    - `comptree_get_at`: O(logn)
    - `comptree_replace`: O(logn)
    - `comptree_destroy`: O(1)
    - `comptree_value`: O(logn)
    - `comptree_left`: O(logn)
    - `comptree_right`: O(logn)
