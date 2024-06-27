#include<iostream>
#include <algorithm>
#include <string>
using namespace std;


//APPROACH 1 :
// void SortLexicographically(string arr[], int n){
//     sort(arr, arr+n);

//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }

//     return ;
// }


//APPROACH 2 :
void merge(string arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    string L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }

    for(int j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr,l,mid,r);
    }
}

void printSortedArray(string arr[], int n){
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string arr[] = {"are", "ant", "art", "an"};
    int n = sizeof(arr)/sizeof(arr[0]);

    //APPROACH 1:
    // SortLexicographically(arr, n);

    //APPROACH 2 :
    mergeSort(arr, 0, n-1);
    printSortedArray(arr, n);

    return 0;
}