#include<bits/stdc++.h>
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
        vector<int>v;
    };
    node* root;
    node* insert(int x, node* t)
    {
        if(t==NULL)
        {
            t=new node;
            t->data=x;
            t->left=NULL;
            t->right=NULL;
        }
        else if(x<t->data){
            t->left=insert(x,t->left);
        }
        else if(x>t->data){
            t->right=insert(x,t->right);
        }
        return t;
    }
    vector<int>tree;
    void preorder(node* t){
        if(t==NULL){return;}
        tree.push_back(t->data);
        preorder(t->left);
        preorder(t->right);
    }
    void inorder(node* t){
        if(t==NULL){return;}
        inorder(t->left);
        tree.push_back(t->data);
        inorder(t->right);
    }
    void postorder(node* t){
        if(t==NULL){return;}
        postorder(t->left);
        postorder(t->right);
        tree.push_back(t->data);
    }
    
public:
    BST(){
        root=NULL;
    }
    void insert(int x){
        root=insert(x, root);
    }
    vector<int> display(){
        tree.clear();
        preorder(root);
        return tree;
    }
    vector<int> returntree(){
        return tree;
    }
};

signed main(){
    BST bst;
    vector<int>v;
    while(true){
        int n,count=0;cin>>n;
        if(n==-1){break;}
        v.push_back(n);
        bst.insert(n);
    }
    if(v==bst.display()){
        cout<<"Valid Preorder Sequence"<<endl;
    }
    else{
        cout<<"Invalid Preorder Sequence"<<endl;
    }

    return 0;
}


void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}