#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> TripletSum(vector<int> arr, int s){
    vector<vector<int>> ans;

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            for(int k=j+1; k<arr.size(); k++){
                if(arr[i]+ arr[j] + arr[k] == s){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
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

    int s;
    cout<<"Enter the given sum : ";
    cin>>s;

    vector<vector<int>> sol;
    sol = TripletSum(arr, s);

    if(sol.empty()){
        cout<<"No triplets found with the given sum."<<endl;
    } else {
        cout<<"Triplets with the sum "<<s<<" are :  "<<endl;
        for(int i=0; i<sol.size(); i++){
            for(int j=0; j<sol[i].size(); j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}