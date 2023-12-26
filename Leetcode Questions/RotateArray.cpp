#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int>& arr, int n, int k){
    vector<int> temp(n);

    for(int i=0; i<n; i++){
        temp[(i+k)%n] = arr[i];
    }
    //copy temp into vector
    arr = temp;
}

void printArray(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

    int k;
    cout<<"Enter the value with which the array is to be rotated : ";
    cin>>k;

    rotateArray(arr, n, k);
    cout<<"Rotated array : ";
    printArray(arr, n);

    return 0;
}