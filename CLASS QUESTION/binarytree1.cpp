#include <bits/stdc++.h>
using namespace std;

struct node 
{
    // Defining the value of
    // the node (integer data)
    int data;
    // Reference pointer to
    // the left child node
    node *left; //struct node ek structure bana and node *left 
    //ek left wale structure banaya aur usko point kar raha hai. 

    // Reference pointer to
    // the right child node
    node *right; //similarly this

    // Method to initialize
    // the node with a value
    node (int val)
    {
        // Set the value of the
        // node to the passed integer
        data = val;
        // Initialize left and 
        //right pointers as NULL
        left = right = NULL; //left and right structure ko intially null se point kar
        //rahe hai.
    }
};
int main ()
{
    // Creating a new node for the root of the 
    // binary tree using dynamic allocation
    node *root = new node(1); //*root ek memory address ko point kar raha hai aur
    //new is used to allocate something to a memory address only so root wale address pe
    //1 assign kar die.

    // Creating left and right child
    // nodes for the root node
    root->left = new node(2); //root ke left wale stucture pe 2 assign karne bol raha hai
    //aur wo jab assign hua toh phir wo apna ek left aur right null pointer banaya hoga.
    root->right = new node(3);

    // Creating a right child node for
    // the left child node of the root
    root->left->right = new node(4);
}