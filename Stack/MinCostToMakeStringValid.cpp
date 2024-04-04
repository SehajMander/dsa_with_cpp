#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string s){
    //odd condition
    if(s.length()%2 == 1){
        return -1;
    }

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        int ch = s[i];

        if(ch == '{'){
            st.push(ch);
        }
        else{
            //ch is closed brace
            if((!st.empty()) && (st.top() == '{')){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    int a=0, b=0;
    while(!st.empty()){
        if(st.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        st.pop();
    }

    int ans = ((a+1)/2) + ((b+1)/2);

    return ans;
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Minimum cost to make a string valid is : "<<findMinimumCost(s)<<endl;

    return 0;
}