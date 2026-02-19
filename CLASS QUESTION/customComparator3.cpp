//Here we are implemeting a custom comparator in priority queue.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

// Define the student struct with custom comparison logic
struct student {
    int marks;
    int rollno;

    // Custom comparison for priority queue
    bool operator< (const student &s2) const 
    {
        // Higher marks have higher priority
        // If marks are equal, student with smaller rollno has higher priority
        if (marks == s2.marks)
        {
            return rollno > s2.rollno;
        }
        return (marks < s2.marks);
    }
    
};

void VivekTiwary_1092()
{
    // Create a priority queue of students
    priority_queue<student> pq;

    // Insert students into the priority queue
    pq.push({3, 1});
    pq.push({6, 0});
    pq.push({8, 2});
    pq.push({8, 1});

    // Display the student with the highest priority (top of the priority queue)
    cout << "Top student has marks: " << pq.top().marks << " and roll number: " 
    << pq.top().rollno << "\n";
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