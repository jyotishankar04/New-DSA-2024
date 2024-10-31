#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class arrayBasics
{
public:
    int sumOfElementsInArray(int[], int);
    int countOfOddNumbersInArray(int[], int);
    void reverseTheArrayBrute(int[], int);
    void reverseTheArrayOptimal(int[], int);
    bool checkIfTheArrayIsSortedBrute(int[], int);
    bool checkIfTheArrayIsSortedOptimal(int[], int);
};

int arrayBasics::sumOfElementsInArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int arrayBasics::countOfOddNumbersInArray(int arr[], int n)
{
    int oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            oddCount++;
        }
    }
    return oddCount;
}

void arrayBasics::reverseTheArrayBrute(int arr[], int n)
{
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = arr[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = array[i];
    }
    return;
}

void arrayBasics::reverseTheArrayOptimal(int arr[], int n)
{
    int p1 = 0, p2 = n - 1;
    while (p1 < p2)
    {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
        p1++;
        p2--;
    }
    return;
}

bool arrayBasics::checkIfTheArrayIsSortedBrute(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool arrayBasics::checkIfTheArrayIsSortedOptimal(int arr[], int n)
{

    if (n == 1)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()

{
    arrayBasics obj;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of all elements are: " << obj.sumOfElementsInArray(arr, n) << endl;
    cout << "Count of odd numbers: " << obj.countOfOddNumbersInArray(arr, n) << endl;
    cout << "Reverse an array Brute: " << endl;
    // obj.reverseTheArrayBrute(arr, n);
    // printArray(arr, n);
    // cout << endl;

    // cout << "Reverse an array Optimal: " << endl;
    // obj.reverseTheArrayOptimal(arr, n);
    // printArray(arr, n);
    
    
    string result = obj.checkIfTheArrayIsSortedBrute(arr, n) ? "True" : "False";
    cout << "Is sortrd: " << result << endl;


    // string result = obj.checkIfTheArrayIsSortedOptimal(arr, n) ? "True" : "False";
    // cout << "Is sortrd: " << result << endl;

}