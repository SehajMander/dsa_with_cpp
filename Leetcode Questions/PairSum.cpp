#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s){
    vector<vector<int>> ans;

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j] == s){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    vector<int> arr;
    int x;
    cout<<"Enter the elements of array :";
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    int s;
    cout<<"Enter the given sum :";
    cin>>s;

    vector<vector<int>> sol;
    sol = pairSum(arr, s);

    for(int i=0; i<sol.size(); i++){
        for(int j=0; j<sol[i].size(); j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}