#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int>& ans){
    int start = 0;
    int end = ans.size() - 1;

    while(start<end){
        swap(ans[start++], ans[end--]);
    }

    return ans;
}

vector<int> arraySum(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int i = n-1;
    int j = m-1;

    vector<int> ans;
    int carry = 0;

    while(i>=0 && j>=0){
        int val1 = arr1[i];
        int val2 = arr2[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    //first case : n>m
    while(i>=0){
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    //second case : m>n
    while(j>=0){
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    //third case : carry != 0
    while(carry != 0){
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

void printArray(vector<int> sol){
    int a = sol.size();
    for(int i=0; i<a; i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array1 : ";
    cin>>n;

    vector<int> arr1;
    int x1;
    cout<<"Enter the elements of the array1 : ";
    for(int i=0; i<n; i++){
        cin>>x1;
        arr1.push_back(x1);
    }


    int m;
    cout<<"Enter the size of array2 : ";
    cin>>m;

    vector<int> arr2;
    int x2;
    cout<<"Enter the elements of the array2 : ";
    for(int j=0; j<m; j++){
        cin>>x2;
        arr2.push_back(x2);
    }

    vector<int> sol = arraySum(arr1, n, arr2, m);
    printArray(sol);

    return 0;
}