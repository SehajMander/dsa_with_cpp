#include<iostream>
using namespace std;

void printSum(int arr[][10], int row, int col){
    cout<<"Printing row-wise sum : ";
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }
        cout<< sum << " ";
    }
    cout<<endl;
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

    printSum(arr, row, col);

    return 0;
}