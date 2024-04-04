#include<iostream>
#include<stack>
using namespace std;

int main() {
    //creation of stack
    stack<int> s;

    //push operation
    s.push(1);
    s.push(2);

    //size of stack
    cout<<"Size of stack is : "<<s.size()<<endl;

    //pop operation
    s.pop();
    
    cout<<"Prining top element : "<<s.top() <<endl;

    if(s.empty()){
        cout<<"Stack empty!"<<endl;
    } else {
        cout<<"Stack NOT empty!"<<endl;
    }

    //size of stack
    cout<<"Size of stack is : "<<s.size()<<endl;

    return 0;
}