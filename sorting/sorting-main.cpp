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
    insertionSort(arr,n);
    cout << "After sorting the array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}