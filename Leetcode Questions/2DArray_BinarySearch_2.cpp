#include<iostream>
using namespace std;

bool searchMatrix(int arr[][10], int row, int col, int target){
    int rowIndex = 0;
    int colIndex = col-1;

    while(rowIndex<row && colIndex<col){
        int element = arr[rowIndex][colIndex];
        //case 1
        if(element == target){
            return 1;
        }
        //case 2
        if(element < target){
            rowIndex++;
        }
        //case 3
        else{
            colIndex--;
        }
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

    cout<<"Element found or not? : "<<searchMatrix(arr, row, col, target)<<endl;

    return 0;
}