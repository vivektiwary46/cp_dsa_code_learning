//Multisets are a type of associative containers similar to the set, with the 
//exception that multiple elements can have the same values. Some Basic Functions 
//associated with multiset: 

//begin() – Returns an iterator to the first element in the multiset –>  O(1)
//end() – Returns an iterator to the theoretical element that follows the last 
//element in the multiset –> O(1)
//size() – Returns the number of elements in the multiset –> O(1)
//max_size() – Returns the maximum number of elements that the multiset can hold –> O(1)
//empty() – Returns whether the multiset is empty –> O(1)
//insert (x) – Inserts the element x in the multiset –> O(log n)
//clear () – Removes all the elements from the multiset –> O(n)
//erase(x) – Removes all the occurrences of x –> O(log n)


// CPP Program to demonstrate the 
// implementation of multiset
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    // empty multiset container
    multiset<int, greater<int> > st1;

    // insert elements in random order
    st1.insert(40);
    st1.insert(30);
    st1.insert(60);
    st1.insert(20);
    st1.insert(50);

    // 50 will be added again to
    // the multiset unlike set
    st1.insert(50);
    st1.insert(10);

    // printing multiset st1
    multiset<int, greater<int> >::iterator itr;
    cout << "\nThe multiset st1 is : \n";
    for (itr = st1.begin(); itr != st1.end(); ++itr) 
    {
        cout << *itr << " ";
    }
    cout << endl;

    // assigning the elements from st1 to st2
    multiset<int> st2(st1.begin(), st1.end());

    // print all elements of the multiset st2
    cout << "\nThe multiset st2 after assign from st1 is : \n";
    for (itr = st2.begin(); itr != st2.end(); ++itr) 
    {
        cout << *itr << " ";
    }
    cout << endl;

    // remove all elements up to element
    // with value 30 in st2
    cout << "\nst2 after removal of elements less than 30 : \n";
    st2.erase(st2.begin(), st2.find(30)); //use of erase and find function.
    for (itr = st2.begin(); itr != st2.end(); ++itr) 
    {
        cout << *itr << " ";
    }

    // remove all elements with value 50 in st2
    int num;
    num = st2.erase(50);
    cout << "\nst2.erase(50) : \n";
    cout << num << " removed \n";
    for (itr = st2.begin(); itr != st2.end(); ++itr) 
    {
        cout << *itr << " ";
    }

    cout << endl;

    //Use of lower bound and upper bound function.
    // lower bound and upper bound for multiset st1
    cout << "\nst1.lower_bound(40) : \n" << *st1.lower_bound(40) << endl;
    cout << "st1.upper_bound(40) : \n"   << *st1.upper_bound(40) << endl;

    // lower bound and upper bound for multiset st2
    cout << "st2.lower_bound(40) : \n" << *st2.lower_bound(40) << endl;
    cout << "st2.upper_bound(40) : \n" << *st2.upper_bound(40) << endl;

    return 0;
}