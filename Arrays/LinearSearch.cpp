#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(key == arr[i]){
            return 1;
        }
    }

    return 0;
}

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int arr[15];

    cout<<"Enter the values of elements of the array : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    //value to be searched
    int key;
    cout<<"Enter the element to be searched : ";
    cin>>key;

    bool found = LinearSearch(arr, size, key);
    if(found){
        cout<<"Element found!!"<<endl;
    } else{
        cout<<"Element not found!!"<<endl;
    }

    return 0;
}