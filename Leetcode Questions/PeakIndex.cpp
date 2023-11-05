//Peak Index of mountain array
#include<iostream>
#include<vector>
using namespace std;

int PeakIndex(vector<int> arr, int n){
    int start = 0;
    int end = arr.size()-1;

    int mid = start + (end - start)/2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }

        mid = start + (end- start)/2;
    }
    return start;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int x;
    vector<int> arr;
    cout<<"Enter the elements of the array  : ";
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    int sol = PeakIndex(arr, n);
    cout<<"The peak index in the given mountain array is :"<< sol << endl;

    return 0;
}
