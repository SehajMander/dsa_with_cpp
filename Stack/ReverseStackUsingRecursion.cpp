#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int num){
    //base case
    if(s.empty()){
        s.push(num);
        return ;
    }

    int val = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, num);
    
    //push the number back to stack
    s.push(val);
}

void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call
    reverseStack(s);

    insertAtBottom(s, num);
}

void printStack(stack<int> &s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;

    int n;
    cout<<"Enter the size of the stack : ";
    cin>>n;

    int data;
    cout<<"Enter the data to be entered into stack : ";
    for(int i=0; i<n; i++){
        cin>>data;
        s.push(data);
    }

    cout<<"Original stack : ";
    printStack(s);

    cout<<"Stack after reversing : ";
    reverseStack(s);
    printStack(s);
    
    return 0;
}