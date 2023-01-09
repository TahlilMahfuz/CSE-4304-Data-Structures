#include<bits/stdc++.h>
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
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
    // void preorder(node* t){
    //     if(t==NULL){return;}
    //     tree.push_back(t->data);
    //     preorder(t->left);
    //     preorder(t->right);
    // }
    // void inorder(node* t){
    //     if(t==NULL){return;}
    //     inorder(t->left);
    //     tree.push_back(t->data);
    //     inorder(t->right);
    // }
    // void postorder(node* t){
    //     if(t==NULL){return;}
    //     postorder(t->left);
    //     postorder(t->right);
    //     tree.push_back(t->data);
    // }
    void iterativepreordertraversal(node* t){
        if(t==NULL){return;}
        stack<node*>stack;
        stack.push(t);

        while(!stack.empty()){
            node* node = stack.top();
            tree.push_back(node->data);
            stack.pop();

            if(node->right){
                stack.push(node->right);
            }
            if(node->left){
                stack.push(node->left);
            }
        }
    }
    void iterativepreordertraversal(node* t){
        if(t==NULL){return;}
        stack<node*>stack;
        stack.push(t);

        while(!stack.empty()){
            node* node = stack.top();
            if(node->right){
                stack.push(node->right);
            }
            tree.push_back(node->data);
            stack.pop();
            if(node->left){
                stack.push(node->left);
            }
        }
    }
    
public:
    BST(){
        root=NULL;
    }
    void insert(int x){
        root=insert(x, root);
    }
    vector<int> preorderdisplay(){
        tree.clear();
        iterativepreordertraversal(root);
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
    if(v==bst.preorderdisplay()){
        cout<<"Valid Preorder Sequence"<<endl;
    }
    else{
        cout<<"Invalid Preorder Sequence"<<endl;
    }

    return 0;
}

