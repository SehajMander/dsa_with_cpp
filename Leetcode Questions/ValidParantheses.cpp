#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> sol;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        //if opening bracet -> push into stack
        if(ch == '(' || ch == '[' || ch == '{'){
            sol.push(ch);
        }
        else{
            //if opening bracket -> check with stack top and pop
            if(!sol.empty()){
                char top = sol.top();
                if(((ch == '}') && top == '{') || ((ch == ')') && top == '(') || ((ch == ']') && top == '[')){
                    sol.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(sol.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cout<<"Enter the string of parantheses : ";
    cin>>s;

    cout<<"Is given string of parantheses valid or not : "<<isValid(s)<<endl;

    return 0;
}