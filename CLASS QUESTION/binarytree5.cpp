#include <bits/stdc++.h>
using namespace std;
//LEVEL ORDER TRAVERSAL IN A BINARY TREE I.E. DFS
//TC : O(N), N is the number of nodes and we visit all the nodes.
//SC : O(N), N is the number of nodes and we can have at max all the nodes in the queue.


// TreeNode struct represents
// a node in a binary tree
struct TreeNode 
{
    int val; 
    TreeNode* left; 
    TreeNode* right;

    TreeNode (int data)
    {
        val = data;
        left = right = NULL;
    }
};


// Function to perform level-order
// traversal of a binary tree
vector<vector<int>> levelOrder(TreeNode* root) 
{
    // Create a 2D vector to store levels
    vector<vector<int>> ans; 
    if (root == nullptr) 
    {
        // If the tree is empty,
        // return an empty vector
        return ans; 
    }
    
    // Create a queue to store nodes
    // for level-order traversal
    queue<TreeNode*> q; //TreeNode is like int and TreeNode* as q mein har node ka pointer dal rahe hai.
    // Push the root node to the queue
    q.push(root); 
    while (!q.empty()) 
    {
        // Get the size of the current level
        int size = q.size(); 
        // Create a vector to store
        // nodes at the current level
        vector<int> level; 
        for (int i = 0; i < size; i++) 
        {
            // Get the front node in the queue
            TreeNode* node = q.front(); 
            // Remove the front node from the queue
            q.pop(); 
            // Store the node value
            // in the current level vector
            level.push_back(node->val); 
            // Enqueue the child nodes if they exist
            if (node->left != nullptr) 
            {
                q.push(node->left);
            }
            if (node->right != nullptr) 
            {
                q.push(node->right);
            }
        }
        // Store the current level
        // in the answer vector
        ans.push_back(level); 
    }
    // Return the level-order
    // traversal of the tree
    return ans; 
}


// Function to print
// the elements of a vector
void printVector(const vector<int>& vec) 
{
    // Iterate through the
    // vector and print each element
    for (int num : vec) 
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() 
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    // Perform level-order traversal
    vector<vector<int>> result = levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) 
    {
        printVector(level);
    }

    return 0;
}
  