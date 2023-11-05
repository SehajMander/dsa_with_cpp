//Search in a rotated sorted array
#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int> arr, int n){
    int start = 0;
    int end = n-1;
    
    int mid = start +(end - start)/2;

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

int BinarySearch(vector<int> arr, int s, int e, int key){
    int start = s;
    int end = e;

    int mid = start + (end - start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }

        if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

int RotatedArraySearch(vector<int> arr, int n, int key){
    int pivot = getPivot(arr, n);
    if(key>=arr[pivot] && key<=arr[n-1]){
        return BinarySearch(arr, pivot, n-1, key);
    }
    else{
        return BinarySearch(arr, 0, pivot, key);
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

    int key;
    cout<<"Enter the element to be searched : ";
    cin>>key;

    cout<<"The index of the searched element is : "<<RotatedArraySearch(arr,n,key)<<endl;
    
    return 0;

}