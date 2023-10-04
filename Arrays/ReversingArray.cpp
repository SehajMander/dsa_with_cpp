#include<iostream>
using namespace std;

void ReverseArray(int arr[], int n){
    int start = 0;
    int end = n-1;

    while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}



int main(){
    int n1, n2;

    cout<<"Enter the size of array 1 : ";
    cin>>n1;

    //array 1
    int arr1[10];
    cout<<"Enter the elements of array 1 : ";
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    cout<<"Enter the size of array 2 : ";
    cin>>n2;

    //array 2
    int arr2[10];
    cout<<"Enter the elements of array 2 : ";
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    //reversing the arrays
    ReverseArray(arr1, n1);
    ReverseArray(arr2, n2);

    //printing the reversed arrays
    cout<<"The reverse of array 1 :";
    printArray(arr1, n1);
    cout<<"The reverse of array 2 :";
    printArray(arr2, n2);

    return 0;
}