#include <bits/stdc++.h>
using namespace std;

class basicHash
{
public:
    int highestFrequentElementBrute(int arr[], int n);
    int highestFrequentElementOptimal(int arr[], int n);

    int secondFrequentElementBrute(int arr[], int n);
    int secondFrequentElementOptimal(int arr[], int n);

    int sumOfMaxAndMinFrequentElementsBrute(int arr[], int n);
    int sumOfMaxAndMinFrequentElementsOptimal(int arr[], int n);
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
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    int maxCount = 0;
    int maxElement = arr[0];
    unordered_map<int, int> hashArr;
    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    for (auto it : hashArr)
    {
        int first = it.first;
        int second = it.second;

        if (second > maxCount)
        {
            maxCount = second;
            maxElement = first;
        }
        else if (second == maxCount)
        {
            maxElement = min(maxElement, first);
        }
    }
    return maxElement;
}

int basicHash::secondFrequentElementBrute(int arr[], int n)
{
    int maxCount = 0;
    int secMaxCount = 0;
    int maxEl = arr[0];
    int secMaxEl = arr[0];
    vector<bool> isVisitedArray(n, false);

    for (int i = 0; i < n; i++)
    {
        if (isVisitedArray[i] == true)
            continue;

        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                isVisitedArray[j] = true;
            }
        }

        if (count > maxCount)
        {
            secMaxCount = maxCount;
            maxCount = count;
            secMaxEl = maxEl;
            maxEl = arr[i];
        }
    }

    return secMaxEl;
}

int basicHash::secondFrequentElementOptimal(int arr[], int n)
{
    int maxCount = -1;
    int maxEl = arr[0];
    int secMaxCount = -1;
    int secMaxEl = arr[0];

    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]]++;
    }

    for (auto it : hashMap)
    {
        int element = it.first;
        int frequency = it.second;
        if (maxCount < frequency)
        {
            secMaxCount = maxCount;
            secMaxEl = maxEl;

            maxCount = frequency;
            maxEl = element;
        }

        if (secMaxCount < frequency && frequency < maxCount)
        {
            secMaxCount = frequency;
            secMaxEl = element;
        }
    }
    return secMaxEl;
}

int basicHash::sumOfMaxAndMinFrequentElementsBrute(int arr[], int n)
{

    int maxFreq = 0;
    int minFreq = INT_MAX;
    vector<bool> visitedArr(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visitedArr[i] == true)
        {
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
            maxFreq = freq;
        }
        if (freq < minFreq)
        {
            minFreq = freq;
        }
    }
    return maxFreq + minFreq;
}

int basicHash::sumOfMaxAndMinFrequentElementsOptimal(int arr[], int n)
{
    int maxFreq = 0;
    int minFreq = INT_MAX;

    unordered_map<int, int> hashArr;

    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    for (auto it : hashArr)
    {
        int element = it.first;
        int frequency = it.second;

        if (frequency > maxFreq)
        {
            maxFreq = frequency;
        }
        if (frequency < minFreq)
        {
            minFreq = frequency;
        }
    }
    return minFreq + maxFreq;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    basicHash obj;
    // cout << "Highest frequent element Brute : " << obj.highestFrequentElementBrute(arr, n) << endl;
    // cout << "Highest frequent element Optimal :" << obj.highestFrequentElementOptimal(arr, n) << endl;

    // cout << "Second Highest Brute: " << obj.secondFrequentElementBrute(arr, n) << endl;
    // cout << "Second Highest Optimal : " << obj.secondFrequentElementOptimal(arr, n) << endl;

    // cout << "Sum of max and min frequent elements Brute : " << obj.sumOfMaxAndMinFrequentElementsBrute(arr, n) << endl;
    // cout << "Sum of max and min frequent elements Optimal : " << obj.sumOfMaxAndMinFrequentElementsBrute(arr, n) << endl;
    return 0;
}
