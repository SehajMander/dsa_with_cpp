#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key){
    //base case
    if(n == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        bool remainingPart = linearSearch(arr+1, n-1, key);
        return remainingPart;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[10];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the value to be searched : ";
    cin>>key;

    cout<<"Element found or not? : "<<linearSearch(arr,n,key)<<endl;

    return 0;
}