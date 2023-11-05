#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>& arr, int n){
    for(int i=1; i<n; i++){
        //for loop for 1 to n-1 rounds
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout<<"Sorted array is : ";
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

    BubbleSort(arr, n);
    
    return 0;
}