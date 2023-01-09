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
};

signed main(){
    BST airlines;
    vector<int>v;
    while(true){
        int n,count=0;cin>>n;
        if(n==-1){break;}
        v=airlines.returntree();
        for(int i=0;i<v.size();i++){
            if(v[i]+3==n || v[i]-3==n){
                count++;
                break;
            }
        }
        if(count>0){
            test(v);
            cout<<" "<<"(Reservation failed)"<<endl;
        }
        else{
            airlines.insert(n);
            v=airlines.display();
            test(v);
        }
    }
    return 0;
}