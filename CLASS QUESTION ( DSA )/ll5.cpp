#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to search for a value in LL
bool searchValue(Node* head, int key) 
{
    // Pointer to traverse the list
    Node* current = head;
    // Traverse until end
    while (current != NULL) {
        // Check if current node matches key
        if (current->data == key) {
            // Return true if found
            return true;
        }
        // Move to next node
        current = current->next;
    }
    // Return false if not found
    return false;
}


void VivekTiwary_1092()
{
    // Creating linked list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    if (searchValue(head, 20)) cout << "Found\n";
    else cout << "Not Found\n";
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