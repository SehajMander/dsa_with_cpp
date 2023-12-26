#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& arr, int n){
    int i=0; //represents non zero element
    for(int j=0; j<n; j++){
        if(arr[j] != 0){
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

void printArray(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> arr;
    int x;
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    moveZeroes(arr, n);
    printArray(arr, n);

    return 0;
}