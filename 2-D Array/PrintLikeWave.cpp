#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(int arr[][3], int row, int col){
    vector<int> ans;

    for(int j=0; j<col; j++){
        if( j%2 == 0 ){
            //even index -> top to bottom
            for(int i=0; i<row; i++){
                cout<<arr[i][j]<<" ";
                ans.push_back(arr[i][j]);
            }
        }
        else{
            //odd index -> bottom to top
            for(int i= row-1; i>=0; i--){
                cout<< arr[i][j]<<" ";
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}

int main(){
    int row, col;
    cout<<"Enter the rows of the array : ";
    cin>>row;
    cout<<"Enter the columns of the array : ";
    cin>>col;

    int arr[row][3];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Printing wave pattern array : "<<endl;
    vector<int> result = wavePrint(arr, row, col);

    // for(int i=0; i< row; i++){
    //     cout<<endl;
    // }
    
    // for(int element : result){
    //     cout<< element <<" ";
    // }

    return 0;
}