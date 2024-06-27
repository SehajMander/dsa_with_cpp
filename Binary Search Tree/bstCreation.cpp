#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //level is complete
            cout<<endl;
            if(!q.empty()){
                //some nodes are left in the queue
                q.push(NULL);
            }
        } else {
            cout<< temp -> data <<" ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}


Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        //insert into the right part of the tree
        root -> right = insertIntoBST(root -> right, d);
    } else {
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}


void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


Node* minVal(Node* root){
    Node* temp = root;

    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}


Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val){
        //node with 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        //node with 1 child
        //if left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        //if right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        //node with 2 children - right and left
        if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    } else if(root -> data > val){
        //go to the left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    } else{
        //go to the right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter the data to create a BST : "<<endl;
    takeInput(root);

    cout<<"The BST :"<<endl;
    levelOrderTraversal(root);

    cout<<"Minimun value in the BST is : " << minVal(root) -> data <<endl;

    cout<<"Maximum value in the BST is : "<< maxVal(root) -> data << endl;

    root = deleteFromBST(root, 50);
    cout<<"The BST after deletion:"<<endl;
    levelOrderTraversal(root);

    return 0;
}