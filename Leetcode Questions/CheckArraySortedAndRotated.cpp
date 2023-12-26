#include<iostream>
#include<vector>
using namespace std;

bool checkArray(vector<int>& arr, int n){
    int count = 0;
    
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }

    if(arr[n-1] > arr[0]){
        count++;
    }

    return count<=1;
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

    bool sol = checkArray(arr, n);
    cout<<"Array is rotated and sorted ? : "<<sol<<endl;

    return 0;
}