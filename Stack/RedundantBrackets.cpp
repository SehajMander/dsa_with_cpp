#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch =='*' || ch == '/'){
            st.push(ch);
        }
        else{
            //either a closing bracket or lowercase letter
            if(ch == ')'){
                bool isRedundant = true;

                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Given string has redundant brackets or not? : " << findRedundantBrackets(s)<<endl;

    return 0;
}