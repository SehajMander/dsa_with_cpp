#include<iostream>
using namespace std;

bool isSorted(int *arr, int n){
    //base case 
    if(n==0 || n==1){
        return true;
    }

    if(arr[0] >  arr[1]){
        return false;
    }
    else{
        int remainingPart = isSorted(arr+1, n-1);
        return remainingPart;
    }
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

    int ans = isSorted(arr, n);

    if(ans){
        cout<<"Array is sorted!"<<endl;
    }
    else{
        cout<<"Array not sorted :("<<endl;
    }

    return 0;
}