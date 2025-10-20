#include<bits/stdc++.h>
using namespace std;

class rotateArray
{
    private:
    void reverseArray(vector<int> & arr, int start, int end){
        while (start <  end)
        {
            int temp = arr[start];
            arr[start]  = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    public:
    void rotateArrayByKBrute(vector<int> & arr, int k){
        if(arr.size() == k){
            return;
        }
        k = k % arr.size();
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

    void rotateArrayByKBatter(vector<int> & arr, int k){
        int n = arr.size();
        k = k % n;
        vector<int> temp;
        for (int i = 0; i < k; i++)
        {
            temp.push_back(arr[i]);  
        }
        for(int i = 0; i <n - k; i ++){
            arr[i] = arr[i + 1];
        }
        // for(int i = (n - k); i < n; i++){
        //     arr[i] = temp[n - k - i];
        // }
    }
    void rotateArrayByKOptimal(vector<int> & arr, int k){
        int n = arr.size();
        k = k%n; // ! This like ensures that if the k is grater the length of the array then we should take the remainder - this ersures the unnecessary loops
        
        this->reverseArray(arr, 0,k-1);
        this->reverseArray(arr,k, n-1);
        this->reverseArray(arr,0, n-1);
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
    // rotateArr.rotateArrayByKBrute(arr,8);
    // rotateArr.rotateArrayByKBatter(arr,3);
    rotateArr.rotateArrayByKOptimal(arr,3);
    cout<<"After Rotate: ";
    for (auto it : arr)
    {
        cout<<it<<" ";
    }
 
    
    return 0;
}