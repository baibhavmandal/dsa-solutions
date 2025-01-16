// Note: This solution is using recursive approach, we can also use level order traversal for iterative solution.
// Basic
// 1. Learn about Binary Tree and types of Binary Tree.
// 2. Learn about preorder, inorder and post order traversal
// 3. Learn about level order traversal.

// Tree Code
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

// Solution using preorder traversal

// Serialization (Preorder Traversal to Array):
//   1. Traverse the binary tree using preorder traversal (visit root → left → right).
//   2. Store each node’s value in an array.
//   3. If a node has no children (i.e., nullptr), store -1 in the array to signify the absence of a child. This ensures the structure of the tree is fully captured.

// Deserialization (Recreating the Tree):

//    1. Using the array from step 1, recursively recreate the tree using the preorder traversal concept.
//    2. If a -1 is encountered in the array, return nullptr to represent the absence of a node.
//    3. Use an index variable passed by reference to track the current position in the array during recursion.

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        if(root == NULL) return {-1};
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    
    void preorder(Node* root, vector<int> &ans) {
        if(root == NULL) return;
        
        ans.push_back(root->data);
        
        if(root->left) preorder(root->left, ans);
        else ans.push_back(-1);
        
        if(root->right) preorder(root->right, ans);
        else ans.push_back(-1);
        
        return;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        int index = 0;
        return helper(arr, index);
    }
    
    Node* helper(vector<int>& arr, int &index) {
        if(index >= arr.size() || arr[index] == -1) {
            index++;
            return nullptr;
        }
        
        Node* root = new Node(arr[index]);
        index++;
        
        root->left = helper(arr, index);
        root->right = helper(arr, index);
        
        return root;
    }
};
