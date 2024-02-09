#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans){
    //base case
    if(index >= str.length()){
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(str, output, index+1, ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main(){
    string str;
    cout<<"Enter the string : ";
    cin>>str;

    vector<string> sol = subsequences(str);
    cout<<"Spiral Matrix is : "; 
    for(string element : sol){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}