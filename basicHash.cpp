#include <bits/stdc++.h>
using namespace std;

class basicHash
{
public:
    int highestFrequentElementBrute(int arr[], int n);
    int highestFrequentElementOptimal(int arr[], int n);
};
int basicHash::highestFrequentElementBrute(int arr[], int n)
{
    int maxFreq = 0;
    int maxEl;
    vector<bool> visitedArr(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visitedArr[i] == true)
        {
            cout << arr[i] << endl;
            continue;
        }

        int freq = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
                visitedArr[j] = true;
            }
        }

        //* Update variables if new element having highest frequency is found */
        if (freq > maxFreq)
        {
            maxEl = arr[i];
            maxFreq = freq;
        }
        else if (freq == maxFreq)
        {
            maxEl = min(maxEl, arr[i]);
        }
    }
    return maxEl;
}

int basicHash::highestFrequentElementOptimal(int arr[], int n)
{
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 5, 5, 5, 6, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    basicHash obj;
    cout << "Highest frequent element Brute : " << obj.highestFrequentElementBrute(arr, n) << endl;
    cout << "Highest frequent element Optimal :" << obj.highestFrequentElementOptimal(arr, n) << endl;
    return 0;
}
