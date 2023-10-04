#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){
    int s = 0;
    int e = size-1;

    int mid = (s+e)/2;
    // int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }

        if(key>arr[mid]){
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = (s+e)/2;
        // int mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int arr[10];
    cout<<"Enter the elements of the array (either in decreasing order or increasing order) : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the value of the key to be searched : ";
    cin>>key;

    int index = BinarySearch(arr, size, key);
    cout<<"Index of the given key is : "<<index<<endl;

    return 0;
}