#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int uniqueNum(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int main(){
    int n;
    int arr[10];
    
    //array size
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the values of elements of array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"The unique number in the array is : "<<uniqueNum(arr, n)<<endl;
    
    return 0;
}