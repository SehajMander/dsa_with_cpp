#include<iostream>
using namespace std;

int main(){
    int row;
    int col;

    cout<<"Enter the number of rows : ";
    cin>>row;
    cout<<"Enter the number of columns : ";
    cin>>col;

    //creation of 2d array
    //has pointers
    int** arr = new int*[row];
    //corresponding arrays
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    //taking input
    //corresponding arrays input
    cout<<"Enter the values of the array : ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    //printing output
    //corresponding arrays output
    cout<<"Array : ";
    cout<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releaseing memory
    //releasing corresponding arrays
    for(int i=0; i<row; i++){
        delete [] arr[i];
    }

    //releasing pointer array 
    delete []arr;

    return 0;
}