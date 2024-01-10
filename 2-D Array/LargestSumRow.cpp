#include<iostream>
using namespace std;

int largestSumRow(int arr[][10], int row, int col){
    int max = INT16_MIN;
    int rowIndex = -1;

    cout<<"Row-wise Sum : ";
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
        if(sum > max){
            max = sum;
            rowIndex = row;
        }
    }
    cout<<endl;
    cout<<"Maximum sum is : "<<max<<endl;
    return rowIndex;
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

    int ansIndex = largestSumRow(arr, row, col);
    cout<<"Largest sum row is at index : "<<ansIndex<<endl;
    return 0;
}