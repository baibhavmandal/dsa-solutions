/* 
Question: Check if a Binary Tree (S) is subtree of another Binary Tree (T).

Sol: 
  Example -

   S (Tree 1)
            x 
          /    \
        a       b
         \
          c
          T (Tree 2)
                z
              /   \
            x      e
          /    \     \
        a       b      k
         \
          c
  Methods -
    1. Using naive solution which will take O(n^2) time and O(n) space.
    2. Second method will take a time of O(n) and space of O(n).
    3. Thrid method will take a time of O(n) and space of O(2^h) where h is height of binary tree.
    4. Last method will take a time of O(n) and space of O(n).
*/
