#include<iostream>
#include<map>
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

//linked list has cycle or not
//APPROACH 1 :
// bool hasCycle(Node* head){
//     if(head == NULL){
//         return false;
//     }

//     map<Node*, bool> visited;

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

//APPROACH 2 : floyd's cycle detection method
Node* floydDetectLoop(Node* head){
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

bool hasCycle(Node* head){
    if(floydDetectLoop(head) != NULL){
        return true;
    }
    else{
        return false;
    }
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
    cout<<"Enter the value of the data to be inserted : ";
    cin>> data;
    insertNode(tail, 5, data);
    print(tail);

    if(hasCycle(tail)){
        cout<<"Cycle is present in linked list!"<<endl;
    }
    else{
        cout<<"No cycle present in linked list!"<<endl;
    }

    return 0;
}