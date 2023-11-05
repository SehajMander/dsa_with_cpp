#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int>& arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    cout<<"The sorted array is : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> arr;
    int x;
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    SelectionSort(arr, n);
    
    return 0;
}