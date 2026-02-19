#include <bits/stdc++.h>
using namespace std;
//POSTORDER DFS IN BINARY TREE.
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

// Function to perform postorder traversal
// of the tree and store values in 'arr'
void postorder(Node* root, vector<int> &arr)
{
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr)
    {
        return;
    }
    // Recursively traverse
    // the left subtree
    postorder(root->left, arr);
    // Recursively traverse 
    // the right subtree
    postorder(root->right, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
}
// Function to initiate postorder traversal
// and return the resulting vector
vector<int> postorder(Node* root)
{
    // Create an empty vector to
    // store postorder traversal values
    vector<int> arr;
    // Call the postorder traversal function
    postorder(root, arr);
    // Return the resulting vector
    // containing postorder traversal values
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

    // Getting postorder traversal
    vector<int> result = postorder(root);

    // Displaying the postorder traversal result
    cout << "postorder Traversal: ";
    // Output each value in the
    // postorder traversal result
    for(int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}