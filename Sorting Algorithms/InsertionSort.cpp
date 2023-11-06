#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<int>& arr, int n){
    for(int i=1; i<n; i++){ // for number of rounds
        int temp = arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else{
                //stop
                break;
            }
        }
        arr[j+1] = temp;
    }

    cout<<"The sorted array is : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
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

    InsertionSort(arr, n);

    return 0;
}