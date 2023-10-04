#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1 < n){
            swap(arr[i], arr[i+1]);
        }
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

    //array 1
    cout<<"Enter the size of the array 1 : ";
    cin>>n1;
    int arr1[10];
    cout<<"Enter the values of elements of array 1 : ";
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    
    //array 1
    cout<<"Enter the size of the array 2 : ";
    cin>>n2;
    int arr2[10];
    cout<<"Enter the values of elements of array 1 : ";
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    //swaping the elements
    swapAlternate(arr1, n1);
    swapAlternate(arr2, n2);

    //printing arrays
    cout<<"Swapped array 1 : ";
    printArray(arr1, n1);
    cout<<"Swapped array 2 : ";
    printArray(arr2, n2);

    return 0;
}