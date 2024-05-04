#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void fun(vector<int> &arr)
{
    int length = arr.size();
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    // int arr[] = {1, -2, 3, -4, 5, -6, -7, 8};
    vector<int> arr = {1, -2, 3, -4, 5, -6, -7, 8};

    fun(arr);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}