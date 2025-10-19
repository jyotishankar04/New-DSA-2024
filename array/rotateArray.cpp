#include<bits/stdc++.h>
using namespace std;

class rotateArray
{
    public:
    void rotateArrayByKBrute(vector<int> & arr, int k){
        if(arr.size() == k){
            return;
        }
        for (int i = 0; i < k; i++)
        {   
            int temp = arr[0];
            for (int j = 0; j < arr.size() - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[arr.size()-1] = temp;
        }
    }
};


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
    cout<<"Before Rotate: ";
    for (auto it : arr)
    {
        cout<<it<<" ";
    }
    cout << endl;
     rotateArray rotateArr; 
    rotateArr.rotateArrayByKBrute(arr,3);
    cout<<"After Rotate: ";
    for (auto it : arr)
    {
        cout<<it<<" ";
    }
 
    
    return 0;
}