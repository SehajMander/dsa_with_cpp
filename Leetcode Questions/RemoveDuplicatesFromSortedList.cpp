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
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};


//remove duplicates from sorted linked list
Node* removeDuplicates(Node* head){
    //empty linked list
    if(head == NULL){
        return head;
    }

    Node* curr = head;

    while(curr -> next != NULL){
        if(curr -> data == curr -> next -> data){
            Node* next_next = curr -> next -> next;
            delete curr -> next;
            curr -> next = next_next;
        }
        else{
            //not equal
            curr = curr -> next;
        }
    }
    return head;
}


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
    Node* node1 = new Node(3);

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
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data1;
    insertAtHead(head, data1);
    data2;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data2;
    insertAtTail(tail, data2);
    cout<<"Linked list after insertion : ";
    print(head);

    head = removeDuplicates(head);
    cout<<"Linked list after duplication removal : ";
    print(head);

    return 0;
}