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
    2. Second method will take a time of O(n) and space of O(n). (Need pre-knowledge of alogrithms to check weather a string is substring of another)
    3. Thrid method will take a time of O(n) and space of O(2^h) where h is height of binary tree.
    4. Last method will take a time of O(n) and space of O(n).
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solve {
  public:
    // Function to check if two trees match
    bool match(Node* T, Node* S) {
        if (T == NULL && S == NULL) return true; // Both trees are empty
        if (T == NULL || S == NULL) return false; // One of the trees is empty
        if (T->data != S->data) return false; // Data doesn't match

        // Check left and right subtrees
        return match(T->left, S->left) && match(T->right, S->right);
    }

    // Function to check if tree S is a subtree of T
    bool solve1(Node* T, Node* S) {
        if (S == NULL) return true; // An empty tree S is always a subtree
        if (T == NULL) return false; // Tree T is empty, so S can't be a subtree

        // Check if current trees match or if S is a subtree of left or right subtrees of T
        if (match(T, S)) return true;

        return solve1(T->left, S) || solve1(T->right, S);
    }
};
