#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

// Definition for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to delete tail node of linked list
Node* deleteTail(Node* head) {
    // If list is empty or has one node
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }
    // Traverse to the second last node
    Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    // Delete tail node
    delete curr->next;
    curr->next = NULL;
    // Return updated head
    return head;
}

void VivekTiwary_1092()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    //ll created is 1->2->3

    head = deleteTail(head);

    // Print list after deletion
    Node* temp = head;
    while (temp) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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