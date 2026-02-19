#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"


// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// Function to find the length of the linked list
int lengthOfLinkedList(Node* head) {
    // Initialize counter to 0
    int count = 0;
    // Initialize a temporary pointer to head
    Node* temp = head;
    // Traverse the linked list
    while (temp != nullptr) {
        // Increment count for each node
        count++;
        // Move to the next node
        temp = temp->next;
    }
    // Return the total count
    return count;
}


void VivekTiwary_1092()
{
    // Creating a sample linked list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Find and print the length of linked list
    cout << "Length of Linked List: " << lengthOfLinkedList(head) << endl;
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