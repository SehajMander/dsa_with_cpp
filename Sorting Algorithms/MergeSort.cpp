#include<iostream>
using namespace std;

void mergeArray(int *arr, int start, int end){
    int mid = (start+end)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *leftArray = new int[len1];
    int *rightArray = new int[len2];

    //copy the values into corresponding arrays
    int mainArrayIndex = start;
    for(int i=0; i<len1; i++){
        leftArray[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        rightArray[i] = arr[mainArrayIndex++];
    }

    //now merge the 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2){
        if(leftArray[index1] < rightArray[index2]){
            arr[mainArrayIndex++] = leftArray[index1++];
        }
        else{
            arr[mainArrayIndex++] = rightArray[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = leftArray[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = rightArray[index2++];
    }
    //deleting heap memory
    delete []leftArray;
    delete []rightArray;
}

void mergeSort(int *arr, int start, int end){
    //base case
    if(start >= end){
        return ;
    }

    int mid = (start+end)/2;

    // left part 
    mergeSort(arr, start, mid);
    //right part
    mergeSort(arr, mid+1, end);

    //merge the arrays
    mergeArray(arr, start, end);
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

    mergeSort(arr, 0, n-1);
    
    cout<<"Sorted Array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }

    return 0;
}