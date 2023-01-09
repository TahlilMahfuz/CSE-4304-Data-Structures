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
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }
    int maxheight(node *node){
        if(node == NULL)
            return 0;
        else
        {
            int left_side=0;
            int right_side=0;
            left_side = maxheight(node -> left);
            right_side = maxheight(node -> right);
            if(left_side > right_side){
                return left_side + 1;
            }
            else
                return right_side + 1;
        }
    }

    vector<int>tree;
    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        tree.push_back(t->data);
        inorder(t->right);
    }
public:
    BST() {
        root = NULL;
    }
    void insert(int x) {
        root = insert(x, root);
    }
    vector<int> display() {
        tree.clear();
        inorder(root);
        return tree;
    }
    vector<int> returntree() {
        return tree;
    }
    int returnMaxheight(){
        return maxheight(root);
    }

};

signed main(){
    BST bst;
    while(true){
        int n,count=0;cin>>n;
        if(n==-1){break;}
        bst.insert(n);
    }
    cout<<bst.returnMaxheight()-1<<endl;
    return 0;
}

