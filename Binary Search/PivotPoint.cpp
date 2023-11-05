#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
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

    int sol = getPivot(arr, n);
    cout<<"The pivot point in the given array is : "<< sol <<endl;
    
    return 0;
}