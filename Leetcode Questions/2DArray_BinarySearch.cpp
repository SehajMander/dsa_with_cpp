#include<iostream>
using namespace std;

bool binarySearch(int arr[][10], int row, int col, int target){
    int start = 0;
    int end = row*col - 1;

    int mid = start + (end-start)/2;

    while(start<=end){
        int element = arr[mid/col][mid%col];
        //case 1
        if(element == target){
            return 1;
        }
        //case 2
        if(element < target){
            start = mid+1;
        }
        else{
            //case 3
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return 0;
}

int main(){
    int row, col;
    cout<<"Enter the rows of the array : ";
    cin>>row;
    cout<<"Enter the columns of the array : ";
    cin>>col;

    int arr[row][10];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"Enter the element to be searched : ";
    cin>>target;

    cout<<"Element found or not? : "<<binarySearch(arr, row, col, target)<<endl;

    return 0;
}