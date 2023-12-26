#include<iostream>
using namespace std;

void mergeArray(int n, int arr1[], int m, int arr2[], int arr3[]){
    int i=0, j=0;
    int k=0;

    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    while(i<n){
        //copy remaining elements of arr1 into arr3
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while(j<m){
        //copy remaining elements of arr2 into arr3
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

void print(int arr3[], int l){
    for(int i=0; i<l; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array1 : ";
    cin>>n;
    cout<<"Enter the elements of array 1 : ";
    int arr1[10];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter the size of array2 : ";
    cin>>m;
    cout<<"Enter the elements of array 2 : ";
    int arr2[10];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    int l = n+m;
    int arr3[20] = {0};

    mergeArray(n, arr1, m, arr2, arr3);
    print(arr3, l);

    return 0;
}