#include <bits/stdc++.h>
using namespace std;
class arrayLogic
{
public:
    void moveZeroToEnd(vector<int> &arr);
    int removeDuplicatesBrute(vector<int> &arr);
    int removeDuplicatesOptimal(vector<int> &arr);
    int missingElementBrute(vector<int> &arr);
    int missingElementBetter(vector<int> &arr);
    int missingElementOptimal(vector<int> &arr);
    int missingElementOptimal2(vector<int> &arr);
};

void arrayLogic::moveZeroToEnd(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] == 0 && arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        if (arr[j] == 0)
            j++;
    }
}

int arrayLogic::removeDuplicatesBrute(vector<int> &arr)
{
    set<int> st;
    for (auto it : arr)
    {
        st.insert(it);
    }
    int index = 0;
    for (auto it : st)
    {
        arr[index] = it;
        index++;
    }
    return index;
}
int arrayLogic::removeDuplicatesOptimal(vector<int> &arr)
{
    int n = arr.size() - 1;
    int i = 0;
    for (int j = i + 1; j <= n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}

int arrayLogic::missingElementBrute(vector<int> &arr)
{
    int N = arr.size();

    // Outer loop that runs from 0 to N
    for (int i = 0; i <= N; i++)
    {
        /* Flag variable to check
        if an element exists*/
        int flag = 0;

        // Search for the element using linear search
        for (int j = 0; j < N; j++) 
        {
            if (arr[j] == i)
            {
                // i is present in the array
                flag = 1;
                break;
            }
        }

        // Check if the element is missing (flag == 0)
        if (flag == 0)
            return i;
    }

    /*  The following line will never
    execute,it is just to avoid warnings*/
    return -1;
}
// ! using hash
int arrayLogic::missingElementBetter(vector<int> &arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        if (mp[i] == 0)
        {
            return i;
        }
    }
}
// ! using formula
int arrayLogic::missingElementOptimal(vector<int> &arr)
{
    int n = arr.size();
    int sum = (n * (n + 1)) / 2;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2 += arr[i];
    }
    return sum - sum2;
}

// ! using xor
int arrayLogic::missingElementOptimal2(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum = sum ^ i;
    }
    return sum;
}
int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the SIZE of the array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Before : ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    arrayLogic logic;
    // logic.moveZeroToEnd(arr);

    // cout << "After : ";
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // !Bellow code is for the removing duplicates elemnets in the array
    // int withoutDuplicates = logic.removeDuplicatesBrute(arr);

    // ! Bellow code is for the missing element

    int missing = logic.missingElementBrute(arr);
    // int missing = logic.missingElementBetter(arr);
    // int missing = logic.missingElementOptimal(arr);
    // int missing = logic.missingElementOptimal2(arr);

    cout << "The missing element is : " << missing << endl;

    // int withoutDuplicates = logic.removeDuplicatesOptimal(arr);

    // cout << "After the removing duplicates:  ";
    // for (int i = 0; i < withoutDuplicates; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}
