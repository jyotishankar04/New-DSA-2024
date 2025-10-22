#include<bits/stdc++.h>
using namespace std;
class arrayLogic
{
public:
    void moveZeroToEnd(vector<int> & arr);
    int removeDuplicatesBrute(vector<int> & arr);
    int removeDuplicatesOptimal(vector<int> & arr);
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

int arrayLogic::removeDuplicatesBrute(vector<int> & arr){
    set<int> st;
    for (auto it: arr)
    {
        st.insert(it);
    }
    int index = 0;
    for (auto it: st)
    {
        arr[index] = it;
        index++;
    }
    return index;
}
int arrayLogic::removeDuplicatesOptimal(vector<int> & arr){
    int n = arr.size() - 1;
    int i = 0;
    for (int j = i+1; j <= n; j++)
    {
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i + 1;    
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
    // logic.moveZeroToEnd(arr);
    
    // cout << "After : ";
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // !Bellow code is for the removing duplicates elemnets in the array
    // int withoutDuplicates = logic.removeDuplicatesBrute(arr);
    int withoutDuplicates = logic.removeDuplicatesOptimal(arr);

    cout<<"After the removing duplicates:  ";
    for (int i = 0; i < withoutDuplicates; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
