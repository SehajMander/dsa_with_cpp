#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>>& ans, int index){
    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, ans, index+1);
        //backtrack
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permutation(vector<int>& nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> nums;
    int x;
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>x;
        nums.push_back(x);
    }

    vector<vector<int>> sol = permutation(nums);
    cout<<"Possible permutations are : "<<endl;
    for(vector<int> element : sol){
        for(int num : element){
            cout<<num<<" ";
        }
    cout<<endl;
    }

    return 0;
}