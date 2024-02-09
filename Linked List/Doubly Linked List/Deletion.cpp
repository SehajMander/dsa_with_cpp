#include<iostream>
using namespace std;

//creating a node
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<< "Memory free for the node with data " << value <<endl;
    }
};

//traversing a linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

//getting the lenght of the linked list
int getLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}


//insert at head
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        //linked list is empty
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        //creating a new node
        Node* temp = new Node(data);
        //insertion
        temp -> next = head;
        head -> prev = temp;
        head = temp; 
    } 
}

//insert at tail
void insertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        //linked list is empty
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        //creating a new node
        Node* temp = new Node(data);
        //insertion
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }   
}

//insert at a given position
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    //insertion at beginning
    if(position == 1){
        insertAtHead(head,tail,data);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //insertion at last position
    if(temp -> next == NULL){
        insertAtTail(tail,head,data);
        return ;
    }

    //creating a new node
    Node* newNode = new Node(data);
    //insertion at given position
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
    newNode -> prev = temp;
}

//deletion of node
void deleteNode(int position, Node* &head){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    //empty linked list
    // Node* head = NULL;
    // Node* tail = NULL;

    int data1;
    cout<<"Enter the data to be inserted at head : ";
    cin>> data1;
    insertAtHead(head, tail, data1);

    int data2;
    cout<<"Enter the data to be inserted at tail : ";
    cin>> data2;
    insertAtTail(tail, head, data2);

    int data3;
    int position;
    cout<<"Enter the data to be inserted at a given position : ";
    cin>> data3;
    cout<<"Enter the position where the data is to be inserted : ";
    cin>> position;
    insertAtPosition(head, tail, position, data3);
    cout<<"After insertion : ";
    print(head);

    cout<<"Lenght of the linked list is : " << getLength(head)<<endl;

    int position1;
    cout<<"Enter the position of the node to be deleted : ";
    cin>>position1;
    deleteNode(position1, head);
    print(head);

    cout<<"Lenght of the linked list after deletion is : " << getLength(head)<<endl;

    return 0;
}