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

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};

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

//deletion
void deleteNode(Node* &tail, int element){
    if(tail == NULL){
        //empty list
        cout<<"List is empty, please check again"<<endl;
        return ;
    }
    else{
        //non empty list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != element){
            prev = curr;
            curr = curr -> next;
        }

        //deletion
        prev -> next = curr -> next;
        //if linked list has only one node
        if(curr == prev){
            tail = NULL;
        }
        //if linked list has more than one node
        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}


//traversal of linked list
void print(Node* &tail){
    Node* temp = tail;

    //empty linked list
    if(tail == NULL){
        cout<< "List is empty"<<endl;
        return ;
    }

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
    // cout<<"Enter the value of the data to be inserted : ";
    // cin>> data;
    // insertNode(tail, 3, data);
    // cout<<"Enter the value of the data to be inserted : ";
    // cin>> data;
    // insertNode(tail, 5, data);
    // cout<<"Enter the value of the data to be inserted : ";
    // cin>> data;
    // insertNode(tail, 7, data);
    cout<<"Linked list after insertion : ";
    print(tail);

    int element;
    cout<<"Enter the node to be deleted : ";
    cin>>element;
    deleteNode(tail, element);
    cout<<"Linked list after deletion : ";
    print(tail);
    

    return 0;
}