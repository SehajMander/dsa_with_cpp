#include<iostream>
using namespace std;

bool isPresent(int arr[][10], int target, int row, int col){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(arr[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int row, col;
    cout<<"Enter the rows of array : ";
    cin>>row;
    cout<<"Enter the columns of array : ";
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

    if(isPresent(arr, target, row, col)){
        cout<<"Element Found!"<<endl;
    }
    else{
        cout<<"Element not found :|";
    }

    return 0;
}