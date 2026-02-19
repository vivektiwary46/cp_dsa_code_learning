#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = NULL;
    } 
};

// Function to insert a new node at the head
Node* insertAtHead(Node* head, int newData) 
{
    // Create a new node whose next points to current head
    Node* newNode = new Node(newData, head);
    // Return the new node as the head
    return newNode;
}

// Function to print the linked list
void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void VivekTiwary_1092()
{
    // Creating a sample linked list: 2 -> 3
    Node* head = new Node(2);
    head->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    // Inserting new node at head
    head = insertAtHead(head, 1);

    cout << "After Insertion at Head: ";
    printList(head);
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