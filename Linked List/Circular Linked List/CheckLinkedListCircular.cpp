#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
      this -> data = data;
      this -> next = NULL;  
    }
};

//check is linked list is circular or not
bool isCircular(Node* head){
    //empty linked list
    if(head == NULL){
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }
    return false;
}

// insertion
void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        //empty linked list
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //Non-empty linked list
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        //element found
        //creating new node
        Node* temp = new Node(data);
        //insertion
        temp -> next = curr -> next;
        curr -> next = temp;
        // tail = temp;
    }
}

//traversal of linked list
void print(Node* &tail){
    Node* temp = tail;

    do{
        cout<< tail -> data <<" ";
        tail = tail -> next;
    }while( tail != temp);

    cout<<endl;
}

int main(){
    //non empty linked list
    //creating a new node
    // Node* node1 = new Node(10);
    // Node* tail = node1;

    //Empty linked list
    Node* tail = NULL;

    int data;
    cout<<"Enter the value of the data to be inserted : ";
    cin>> data;
    insertNode(tail, 10, data);
    cout<<"Enter the value of the data to be inserted : ";
    cin>> data;
    insertNode(tail, 3, data);
    print(tail);

    if(isCircular(tail)){
        cout<<"Linked list is circular in nature."<<endl;
    }
    else{
        cout<<"Linked list is not circular in nature."<<endl;
    }

    return 0;
}