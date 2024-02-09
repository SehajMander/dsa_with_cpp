#include<iostream>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data " << value << endl;
    }
};


//insert at the head
void insertAtHead(Node* &head, int d){
    //created a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


//insert at the tail
void insertAtTail(Node* &tail, int d){
    //created a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}


//insert at a given position
void insertAtPosition(Node* &head, Node* & tail, int position, int d){
    //insert at beginning
    if(position == 1){
        insertAtHead(head, d);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //insert at last
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return ;
    }

    //creating a new node
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

//deletion
void deleteNode(Node* &head, int position){
    //deleting first or head node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free of start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or tail node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //created a new node
    Node* node1 = new Node(10);

    //head pointed to node1
    Node* head = node1;
    int data1;
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data1;
    insertAtHead(head, data1);

    //tail pointed to node1
    Node* tail = node1;
    int data2;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data2;
    insertAtTail(tail, data2);

    int position;
    cout<<"Enter the position where element is to be inserted : ";
    cin>>position;
    int data3;
    cout<<"Enter the data to be inserted : ";
    cin>>data3;
    cout<<"Linked list : ";
    insertAtPosition(head, tail, position, data3);
    print(head);

    int position1;
    cout<<"Enter the position to be deleted : ";
    cin>>position1;
    deleteNode(head, position1);
    cout<<"Linked list after deletion : ";
    print(head);

    return 0;
}