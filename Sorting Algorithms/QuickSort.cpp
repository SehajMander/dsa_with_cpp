#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    
    for(int i=start+1; i<=end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    //placing pivot at right place
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    //handling the left and right part
    int i= start, j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}



void quickSort(int arr[], int start, int end){
    //base case
    if(start >= end){
        return ;
    }

    //partitioning the array 
    int p = partition(arr, start, end);

    //sort left part
    quickSort(arr, start, p-1);
    //sort right part
    quickSort(arr, p+1, end);
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

    cout<<"Sorted array is :";
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}