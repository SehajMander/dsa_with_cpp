 #include<iostream>
 #include<stack>
 using namespace std;

 class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    //behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    //push operation
    void push(int element){
        if(size-top > 1){ //checks for the empty space
            top++;
            arr[top] = element;
        } 
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    //pop operation
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    //peek opreation
    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    //checking if stack is empty or not
    bool isEmpty(){
        if( top == -1){
            return true;
        }
        else{
            return false;
        }
    }
 };

int main(){
    Stack st(5);
    
    st.push(22);
    st.push(43);
    st.push(44);
    // st.push(55);
    // st.push(56);
    // st.push(66);

    cout<<"peek element is : "<<st.peek()<<endl;
    st.pop();
    cout<<"peek element is : "<<st.peek()<<endl;
    st.pop();
    cout<<"peek element is : "<<st.peek()<<endl;
    st.pop();
    cout<<"peek element is : "<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is NOT empty"<<endl;
    }

    // st.push(55);
    // if(st.isEmpty()){
    //     cout<<"Stack is empty"<<endl;
    // }
    // else{
    //     cout<<"Stack is NOT empty"<<endl;
    // }

    return 0;
}