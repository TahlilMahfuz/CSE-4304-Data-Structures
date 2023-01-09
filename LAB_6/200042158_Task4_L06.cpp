#include<bits/stdc++.h>
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
using namespace std;

class BST {
    
    struct node {
        int data,size;
        node* left;
        node* right;
    };
    node* root;
    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data){
            t->left = insert(x, t->left);
        }
        else if(x > t->data){
            t->right = insert(x, t->right);
        }
        t->size = 1;
        if(t->right){t->size += t->right->size;}
        if(t->left){t->size += t->left ->size;}
        return t;
    }
    vector<int>tree;
    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        tree.push_back(t->data);
        inorder(t->right);
    }
    void returnnodecount(node* t){
        if(t->data<root->data){
            while(t!=NULL){
                node* x=root;
                if(t->data<x->data){
                    x=x->left;
                }
            }
        }
    }
    int orderofkey(node* n,int val){
        if(n==NULL){return 0;}
        if(n->data==val){
            if(n->left!=NULL){
                return n->left->size;
            }
            else return 0;
        }

        if(val>n->data){
            if(n->left!=NULL){
                return (n->left->size)+orderofkey(n->right,val)+1;
            }
            else {
                return orderofkey(n->left,val)+1;
            }
        }
        return orderofkey(n->left,val);
    }
public:
    BST() {
        root = NULL;
    }
    void insert(int x) {
        root = insert(x, root);
    }
    void display() {
        tree.clear();
        inorder(root);
    }
    vector<int> returntree() {
        return tree;
    }
    int returnorderofkey(int x){
        return orderofkey(root,x);
    }

};

signed main(){
    BST bst;
    while(true){
        int n;cin>>n;
        if(n==-1){break;}
        bst.insert(n);
    }
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        cout<<bst.returnorderofkey(x)<<endl;
    }
    return 0;
}

