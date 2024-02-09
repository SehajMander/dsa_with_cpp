#include<iostream>
#include<map>
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
};


//detecting loop
// APPROACH 1 :
// bool detect(Node* head){
//     if(head == NULL){
//         return false;
//     }

//     map<Node* , bool> visited;

//     Node* temp = head;
    
//     while(temp != NULL){
//         //cycle is present
//         if(visited[temp] == true){
//             return true;
//         }

//         visited[temp] = true;
//         temp = temp -> next;
//     }
//     return false;
// }

// APPROACH 2 : floyd's cycle detection algorithm
Node* floydDetectCycle(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

bool detect(Node* head){
    if(floydDetectCycle(head) != NULL){
        return true;
    }
    else{
        return false;
    }
}


//finding starting node of the loop or cycle
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydDetectCycle(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}


//removing cycle or loop in the linked list
void removeLoop(Node* head){
    if(head == NULL){
        return ;
    }

    Node* startofLoop = getStartingNode(head);
    Node* temp = startofLoop;
    while(temp -> next != startofLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
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

    tail -> next = head -> next;
    if(detect(head)){
        cout<<"Cycle PRESENT!"<<endl;
    }
    else{
        cout<<"Cycle NOT present!"<<endl;
    }

    Node* startingNode = getStartingNode(head);
    cout<<"Starting node of loop or cycle is : "<< startingNode -> data <<endl;

    removeLoop(head);
    if(detect(head)){
        cout<<"Cycle PRESENT!"<<endl;
    }
    else{
        cout<<"Cycle NOT present!"<<endl;
    }


    return 0;
}