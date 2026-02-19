//This is based on recursion
//Youtube Link :- https://www.youtube.com/watch?v=WIrA4YexLRQ&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC :- O(Nlog2N) 
//SC :- O(1) -> as no extra space is used.
//In this algo we are taking first elemnt as the pivot aur usko uske correct position 
//pe place kar rahe hai(say it's correct place is partiotionIndex) so now after doing this, 
//all the elements to it's left will be smaller than it and all the elements to it's right 
//will be larger than it and then again we  do the quick sort for array 0 to partionIndex-1
//to partitionIndex + 1 to n-1.
//The crucial part is finding the partionIndex and we do it in the function partition.

//Below in comments randomized quick sort is also discussed.
int n;
vector<int> arr;

int partition(int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] >= pivot && i <= high - 1)
        {
            //isme we are finding the last element which is larger than pivot from
            //index 0 side.
            i++;
        }
        while (arr[j] < pivot && j >= low + 1)
        {
            //isme we are finding the last element which is smaller than pivot from
            //index n-1 side.
            j--;
        }
        if (i < j) {swap(arr[i], arr[j]);} //then we swap i and j.
        //we do it until j crosses i and this j will be the correct position of pivot.
    }
    swap(arr[low], arr[j]); //finally low jispe pivot tha, usko aur j ko swap kar die.
    return j; //j is the partionIndex.
}
void qs(int low, int high)
{
    if (low < high)
    {
        int partionIndex = partition(low, high);
        qs(low, partionIndex - 1);
        qs(partionIndex + 1, high);
    }
}
void VivekTiwary_1092()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }   
    qs(0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
//Randomized Quick Sort
//The core idea of Randomized Quicksort is to prevent the worst-case scenario by 
//introducing randomness into the algorithm.
//In a standard Quicksort, the performance can drastically degrade if the pivot element 
//is consistently chosen poorly (for example, always selecting the smallest or largest 
//element in the sub-array). This leads to a highly unbalanced partitioning, where one 
//sub-array is very large and the other is very small, causing the time complexity to 
//increase from an average of O(nlogn) to a worst-case of O(n^2).
//Randomized Quicksort avoids this problem by randomly selecting the pivot element from 
//the array. This simple change ensures that, on average, the pivot will be a good 
//choice, leading to a more balanced partitioning. Even though a specific run might 
//still get unlucky with a bad pivot, the probability of this happening repeatedly 
//across all recursive calls is extremely low.
//By randomly choosing the pivot, the worst-case scenario is no longer dependent on the 
//initial order of the data. Instead, it relies on chance. This makes the worst-case 
//performance rare and ensures that the average-case time complexity of O(nlogn) is the 
//expected outcome for any input data set.