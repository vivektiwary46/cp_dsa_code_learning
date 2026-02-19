#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//code shows how to create a linked list.
//There are two information sets to store at every node, thus there is a need to create a 
//self-defined data type to handle them. Therefore, we will use the help of structs and 
//classes


// Node class represents a node in the linked list
struct Node {
    int data;     // Data value
    Node* next;   // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1) 
    {
        data = data1;
        next = next1;
    }

    //any one of the constructor can be used.

    // Constructor with only data
    Node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};

void VivekTiwary_1092()
{
    // Create node
    Node* y = new Node(1);

    // Print memory location of node
    cout << y << '\n';

    // Print data stored in node
    cout << y->data << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}