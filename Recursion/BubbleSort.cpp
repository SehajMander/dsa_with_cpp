#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    //base case
    if(n == 0 || n == 1){
        return ;
    }

    //processing
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    //recursive call
    bubbleSort(arr, n-1);
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[10];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}