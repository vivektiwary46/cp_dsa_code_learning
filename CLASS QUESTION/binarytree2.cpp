#include <bits/stdc++.h>
using namespace std;
//PREORDER DFS IN BINARY TREE.
//RECURSIVE

//TC : O(N) -> where n is the number of nodes and that is what we are visiting in total traversal.
//SC : O(N) -> it will be equal to the total level of the tree and in worst case the 
//degenerate tree case can come and the levels in degenerate tree will be the number of nodes
//itself.

// Node structure for
// the binary tree
struct Node 
{
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr)
{
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr)
    {
        return;
    }
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the left subtree
    preorder(root->left, arr);
    // Recursively traverse 
    // the right subtree
    preorder(root->right, arr);
}
// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root)
{
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}


// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}