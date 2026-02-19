#include <bits/stdc++.h>
using namespace std;
//INORDER DFS IN BINARY TREE.
//RECURSIVE.

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

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr)
{
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr)
    {
        return;
    }
    
    // Recursively traverse
    // the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}
// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inorder(Node* root)
{
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
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

    // Getting inorder traversal
    vector<int> result = inorder(root);

    // Displaying the inorder traversal result
    cout << "inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}