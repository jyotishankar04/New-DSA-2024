#include <bits/stdc++.h>
using namespace std;
void pairFn()
{
    // initialization and asign
    pair<int, int> p1 = {1, 2};
    p1.first = 10;
    p1.second = 20;
    // cout << p1.first << " " << p1.second;

    pair<int, pair<int, string>> complexPair;
    complexPair.first = 10;
    complexPair.second.first = 20;
    complexPair.second.second = "Hello from complex Pair";
    cout << complexPair.first << " " << complexPair.second.first << " " << complexPair.second.second;
}

void vectorFn()
{
    // int arr[5] = {1, 4, 6};
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // Vercter is a dynamic array with additonal functionalities
    // Initialization
    vector<int> vec;
    vec.push_back(10); // Adding an element to the end
    vec.push_back(20);
    vec.push_back(30);

    // 2. Accessing elements
    cout << "First element (front): " << vec.front() << endl;            // Output: 10
    cout << "Last element (back): " << vec.back() << endl;               // Output: 30
    cout << "Element at index 1 (using at): " << vec.at(1) << endl;      // Output: 20
    cout << "Element at index 2 (using operator[]): " << vec[2] << endl; // Output: 30

    // 3. Checking size and capacity
    cout << "Size: " << vec.size() << endl;         // Output: 3
    cout << "Capacity: " << vec.capacity() << endl; // Output depends on system

    // 4. Reserving capacity
    vec.reserve(10); // Reserve space for at least 10 elements
    cout << "New capacity after reserve: " << vec.capacity() << endl;

    // 5. Modifying elements
    vec.insert(vec.begin() + 1, 15); // Insert 15 at index 1
    vec.pop_back();                  // Remove the last element
    vec.push_back(25);               // Add another element

    // 6. Using iterators to display elements
    cout << "Elements in vector: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    cout << "Elements in vector: after swaping  ";
    iter_swap(vec.begin(), vec.end() - 1);
    cout << endl;

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 7. Resizing and clearing
    vec.resize(2); // Resize to 2 elements (removes extra elements)
    cout << "Size after resize: " << vec.size() << endl;

    vec.clear(); // Clear all elements
    cout << "Size after clear: " << vec.size() << endl;
}

void listFn()
{
    // Sequence of containers that supports non-contigues memory allocation
    // -> vecter gives faster retrival it gives slower retrival
    // -> a dubble linkedlist that allows elemeents to be efficiently inserted or deleted from both ends as well as from the middle

    list<int> ls;
    ls.push_back(10);
    ls.push_front(0);
    ls.push_back(20);
    ls.insert(ls.begin(), 30);
    cout << "Elemenets in the list: " << endl;
    for (list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
    {
        cout << *it << " ";
    }
}

void dequeFn()
{
    // is a sequence container with the ability to expand and contat on the both ends
    // _>supperts fast insertion and deletion at the begin and  end
    deque<int> d;
    d.insert(d.begin(), 10);
    d.insert(d.end(), 20);
    d.insert(d.begin(), 30);

    // d.insert(20);
    // d.insert(30);
    cout << "Elements : ";
    for (auto it : d)
    {
        cout << it << " ";
    }
}
void stackFn()
{
    // A powerfull container adaptor that follows the last in first out principle
    // -> it provides a stream lined interface for adding add removing elements from end

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void queueFn()
{
    // A powerfull container adaptor that follows the first in first out principle
    // -> it provides a stream lined interface for adding add removing elements from end

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
void priority_queueFn()
{
    // A powerfull container adaptor that follows the first in first out principle
    // -> it provides a stream lined interface for adding add removing elements from end
    // stores the highest element in the top

    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(40);
    pq.push(50);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

void setFn()
{
    // Stores only unique elements and in ascending order or sorted order
    // -> it provides a stream lined interface for adding add removing elements from end
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.find(600);         // returns iterator to the element if present else returns iterator to end
    cout << s.count(20); // returns 1 if present else 0
    s.erase(10);         // removes element 10

    /// lower_bound and upper_bound
    cout << endl;
    cout << "Elements in the set: ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    auto it = s.lower_bound(20);  // returns the iterator to the element greater than or equal to 20
    auto it2 = s.upper_bound(20); // returns the iterator to the element greater than 20
    cout << endl;
    cout << "Lowor_bound: " << *it << endl;
    cout << "Upper_bound: " << *it2 << endl;
}

void multisetFn()
{
    // Stores elements  in ascending order or sorted order with multiple occurences

    // -> it provides a stream lined interface for adding add removing elements from end
    multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.find(600);         // returns iterator to the element if present else returns iterator to end
    cout << s.count(20); // returns 1 if present else 0
    s.erase(10);         // removes element 10 and all occurences
    s.erase(s.find(20)); // removes element 20 only the first occurence

    /// lower_bound and upper_bound
    cout << endl;
    cout << "Elements in the set: ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    auto it = s.lower_bound(20);  // returns the iterator to the element greater than or equal to 20
    auto it2 = s.upper_bound(20); // returns the iterator to the element greater than 20
    cout << endl;
    cout << "Lowor_bound: " << *it << endl;
    cout << "Upper_bound: " << *it2 << endl;
}
void unordered_setFn()
{
    // store unique elements in unordered manner
    // -> it provides a stream lined interface for adding add removing elements from end
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.find(600);         // returns iterator to the element if present else returns iterator to end
    cout << s.count(20); // returns 1 if present else 0
    s.erase(10);         // removes element 10

    /// lower_bound and upper_bound
    cout << endl;
    cout << "Elements in the set: ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    // lower_bound and upper_bound are not applicable on unordered_set
}
void mapFn()
{
    // stores key value pairs
    // -> it provides a stream lined interface for adding add removing elements from end
    // like container that stores key value pairs in a sorted order. Based on the key
    // it provides efficient lookup and insertion operations
    // insert / emplace/ assignment
    // map<key, value> name;

    map<int, int> m;
    m.insert({1, 10});
    m.insert({3, 30});
    m.insert({2, 20});
    m.insert({5, 50});
    m.insert({4, 40});
    // it stores as asscending order of keys
    // doesnot store duplicate keys

    for (auto it : m)
    {
        cout << it.first << " -> " << it.second << endl;
    }
    // find
    auto it = m.find(5);
    cout << "5 : " << (*it).first << "->" << it->second << endl;
    // if not found returns iterator to end of the map
}

void unordered_mapFn()
{
    // stores key value pairs
    // -> it provides a stream lined interface for adding add removing elements from end
    // like container that stores key value pairs in a sorted order. Based on the key
    // it provides efficient lookup and insertion operations
    // insert / emplace/ assignment
    // map<key, value> name;

    unordered_map<int, int> m;
    m.insert({1, 10});
    m.insert({3, 30});
    m.insert({2, 20});
    m.insert({5, 50});
    m.insert({4, 40});
    // it stores as asscending order of keys
    // doesnot store duplicate keys
    // find
    auto it = m.find(5);
    cout << "5 : " << (*it).first << "->" << it->second << endl;
    // if not found returns iterator to end of the map

    for (auto it : m)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

void multimapFn()
{
    // stores key value pairs
    // -> it provides a stream lined interface for adding add removing elements from end
    // like container that stores key value pairs in a sorted order. Based on the key
    // it provides efficient lookup and insertion operations
    // insert / emplace/ assignment
    // map<key, value> name;

    multimap<int, int> m;
    m.insert({1, 10});
    m.insert({3, 30});
    m.insert({2, 20});
    m.insert({2, 20});
    m.insert({5, 50});
    m.insert({4, 40});
    // it stores as asscending order of keys
    //  store duplicate keys
    // find
    auto it = m.find(5);
    cout << "5 : " << (*it).first << "->" << it->second << endl;
    // if not found returns iterator to end of the map

    for (auto it : m)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}
void sortFn()
{
    // sort
    vector<int> v = {10, 40, 60, 20, 50};
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << " ";
    }
}

void accumulateFn()
{
    // accumulate
    // it adds all the elements in the vector
    vector<int> v = {10, 40, 60, 20, 50};
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
}
void countFn()
{
    // count
    // it counts the occurences of an element
    vector<int> v = {10, 10, 40, 60, 20, 50};
    int countResult = count(v.begin(), v.end(), 40);
    cout << countResult << endl;
}

void findFn()
{
    // find
    // it finds the first occurence of an element
    vector<int> v = {10, 10, 40, 60, 20, 50};
    auto it = find(v.begin(), v.end(), 40);
    cout << (*it) << endl;
}

void nextPermutation()
{
    // prints all the possible permutations in sorted order
    vector<int> v = {1, 2, 3};
    do
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

void prevPermutation()
{
    // prints all the possible permutations in reverse sorted order
    vector<int> v = {3, 2, 1};
    do
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));
}
void maxElement()
{
    // max_element
    vector<int> v = {10, 40, 60, 20, 50};
    auto it = max_element(v.begin(), v.end());
    cout << (*it) << endl;
}
void minElement()
{
    // min_element
    vector<int> v = {10, 40, 60, 20, 50};
    auto it = min_element(v.begin(), v.end());
    cout << (*it) << endl;
}

// custom comparator
bool myCompare(int a, int b)
{
    if (a < b)
        return false;
    return true;
}
void comparatorFn()
{
    // comparator
    // Internal comparator that takes two elements and returns true if the first element is less than the second then returns in boolean
    vector<int> v = {10, 40, 70, 20, 50};
    // sort(v.begin(), v.end(), greater<int>()); // ! inbuilt function
    sort(v.begin(), v.end(), myCompare);
    // we can provide the sort rule  using the camparator
    for (auto it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    // pairFn();
    // vectorFn();
    // listFn();
    // dequeFn();

    // stackFn();
    // queueFn();
    // priority_queueFn();
    // setFn();
    // multisetFn();
    // unordered_setFn();

    // mapFn();
    // unordered_mapFn();
    // multimapFn();
    /// stl functions
    // sortFn();
    // accumulateFn();
    // countFn();
    // findFn();
    // nextPermutation();
    // prevPermutation();
    // maxElement();
    // minElement();
    //! comparators
    // comparatorFn();
    return 0;
}