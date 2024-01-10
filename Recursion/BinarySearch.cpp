#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key){
    //base cases
    //element not found
    if(start > end){
        return false;
    }
    int mid = start + (end-start)/2;
    //element found 
    if(arr[mid] == key){
        return true;
    }

    if(arr[mid]<key){
        return binarySearch(arr, mid+1, end, key);
    }
    else{
        return binarySearch(arr, start, mid-1, key);
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

    int key;
    cout<<"Enter the element to be searched : ";
    cin>>key;

    bool ans = binarySearch(arr, 0, n, key);

    if(ans){
        cout<<"Element found!!"<<endl;
    }
    else{
        cout<<"Element NOT found :("<<endl;
    }

    return 0;
}