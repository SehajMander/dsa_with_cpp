#include<iostream>
using namespace std;

void sortOne(int arr[], int n){
    int left = 0;
    int right = n-1;

    while(left<right){
        //condition 1
        while(arr[left] == 0 && left<right){
            left++;
        }

        //condition 2
        while(arr[right] == 1 && left<right){
            right--;
        }

        //condition 3
        if(arr[left] == 1 && arr[right] == 0 && left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sortOne(arr, n);
    printArray(arr, n);

    return 0;
}