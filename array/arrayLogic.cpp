#include<bits/stdc++.h>
using namespace std;
class arrayLogic
{
public:
    void moveZeroToEnd(vector<int> & arr);
};

void arrayLogic::moveZeroToEnd(vector<int> & arr){
    int n = arr.size();
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if(arr[i] == 0&& arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        if(arr[j] == 0) j++;
    }
}

int main(){
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
    logic.moveZeroToEnd(arr);
    cout << "After : ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}
