#include<iostream>
#include<stack>
using namespace std;

// void solve(stack<int> s, int count, int size){
//     //base case
//     if(count == size/2){
//         s.pop();
//         return ;
//     }

//     int num = s.top();
//     s.pop();

//     //recursive call
//     solve(s, count+1, size);

//     //push the number back to stack
//     s.push(num);
// }

// stack<int> deleteMiddleElement(stack<int> s, int n){
//     int count = 0;
//     solve(s,count,n);
// }

stack<int> deleteMiddleElement(stack<int> s, int n) {
    if (n == 0) {
        return s;
    }
    
    s.pop();
    
    stack<int> temp;
    
    for (int i = 0; i < n - 1; i++) {
        temp.push(s.top());
        s.pop();
    }
    
    stack<int> ans;
    
    while (!s.empty()) {
        ans.push(s.top());
        s.pop();
    }
    
    while (!temp.empty()) {
        ans.push(temp.top());
        temp.pop();
    }
    
    return ans;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    int n = 2;
    
    stack<int> ans = deleteMiddleElement(s, n);
    
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}