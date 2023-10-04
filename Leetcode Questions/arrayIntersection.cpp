#include<iostream>
#include <string>
#include<vector>
using namespace std;

vector<int> arrayIntersection(vector<int> arr1, vector<int> arr2, int n, int m){
    // vector<int> ans;

    // for(int i=0; i<n; i++){
    //     int element = arr1[i];

    //     for(int j=0; j<m; j++){
    //         if(element == arr2[j]){
    //             ans.push_back(element);
    //             arr2[j] = -2;
    //             break;
    //         }
    //     }
    // }
    // return ans;

    //optimized solution
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        //condition 1
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        } 
        //condition 2
        else if(arr1[i]<arr2[j]){
            i++;
        }
        //condition 3
        else{
            j++;
        }
    }
    return ans;
}

int main(){
    int n,m;
    //array 1
    cout<<"Enter the size of arr1 : ";
    cin>>n;
    int x1;
    vector<int> arr1;
    cout<<"Enter the elements of arr1 :";
    for(int i=0; i<n; i++){
        cin>>x1;
        arr1.push_back(x1);
    }

    //array 2
    cout<<"Enter the size of arr2 : ";
    cin>>m;
    int x2;
    vector<int> arr2;
    cout<<"Enter the elements of arr2 :";
    for(int j=0; j<m; j++){
        cin>>x2;
        arr2.push_back(x2);
    }

    vector<int> sol;
    sol = arrayIntersection(arr1, arr2, n, m);

    cout<<"Intersection elements : ";
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<" ";
    }
    
    return 0;
}