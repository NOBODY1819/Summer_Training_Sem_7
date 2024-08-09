#include<iostream>
using namespace std;

class Node{
    public:
        Node *left,*right;
        int data;
        Node(){
            this->data=0;
            this->left=this->right=NULL;
        }
        Node(int data){
            this->data=data;
            this->left=this->right=NULL;
        }
};

class binarySearchTree{
    public:
    Node *insertNode(Node *root, int data){
        if(root==NULL) return new Node(data);
        if (data<root->data)
        {
            root->left=insertNode(root->left,data);
        }else{
            root->right=insertNode(root->right,data);
        }
        return root;
    }

    void inOrder(Node *root){
        if(root!=NULL){
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
    void postOrder(Node *root){
        if(root!=NULL){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    void preOrder(Node *root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

};

int main(){
    Node *root=NULL;
    binarySearchTree bst;
    char ch;
    while (true)
    {
        system("cls");
        cout<<"1. Insert Node In BST\n2.Pre-Order Traversal\n3.Post-Order Traversal\n4.In-Order Traversal 0. Exit\t";
        cout<<"Enter choice: ";
        cin>>ch;
        switch (ch)
        {
        case '1':
        //Insert code;
            int val;
            cout<<"Enter value: ";cin>>val;
            root=bst.insertNode(root,val);
            break;
        case '2':
        //Pre-Order code;
            cout<<"\n";
            bst.preOrder(root);
            cout<<"\n";
            break;
        case '3':
        //Post_order code;
            cout<<"\n";
            bst.postOrder(root);
            cout<<"\n";
            break;
        case '4':
        //In-Order code;
            cout<<"\n";
            bst.inOrder(root);
            cout<<"\n";
            break;
        case '0':
            cout<<"Exit ";
            exit(0);
        default:
        cout<<"Invalid Input";
            break;
        }
    }
    return 0;
}