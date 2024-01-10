#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(int arr[][10], int row, int col){
    vector<int> ans;
    int count = 0;
    int total = row*col;

    //index initialisation
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count < total){

        //print starting row
        for(int index = startingCol; count<total && index <=  endingCol; index++){
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;


        //print ending column
        for(int index = startingRow; count<total && index <=  endingRow; index++){
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;


        //print ending row
        for(int index = endingCol; count<total && index >=  startingCol; index--){
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        //print starting column
        for(int index = endingRow; count<total && index >=  startingRow; index--){
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
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

    vector<int> sol = spiralMatrix(arr, row, col);
    cout<<"Spiral Matrix is : "; 
    for(int element : sol){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}