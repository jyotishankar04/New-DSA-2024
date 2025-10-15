#include<bits/stdc++.h>
using namespace std;

// Selection Sort   

// [4,7,2,5,3,1]
void selectionSort(vector<int> & arr, int n){

    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            swap(arr[i],arr[minIndex]);
        }
    }
}

// Bubble sort
// [4,7,2,5,3,1]

void bubbleSort(vector<int> & arr, int n){
    for(int i = n -1 ; i >= 0; i--){
        for(int j = 0; j <= i; j ++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(vector<int> & arr, int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j -1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
void merge(vector<int> & arr, int low, int mid, int high){
    vector<int> tempArr;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {   
        if(arr[left] >= arr[right]){
            tempArr.push_back(arr[right]);
            right++;
        }
        if(arr[left] < arr[right]){
            tempArr.push_back(arr[left]);
            left++;
        }
    }
    while (left <= mid)
    {
        tempArr.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        tempArr.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {   
        arr[i] = tempArr[i - low];
    }
    
}

void mergeSort(vector<int> & arr, int low,int high){
    if(low >= high) return;
    int mid = (low + high)/2;

    mergeSort(arr,low, mid);
    mergeSort(arr,mid+1, high);
    merge(arr, low, mid, high);
}


int main(){
vector<int> arr;
    int n;
    cout << "Enter the SIZE of the array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Unsorted Array: ";
    for (auto it : arr) cout << it << " ";
    cout << endl;

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr,n);
    mergeSort(arr,0,n-1);

    cout << "After sorting the array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}