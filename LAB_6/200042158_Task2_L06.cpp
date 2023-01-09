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
    void preorder(node* t) {
        if(t == NULL)
            return;
        tree.push_back(t->data);
        preorder(t->left);
        preorder(t->right);
    }
    void postorder(node* t) {
        if(t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        tree.push_back(t->data);
    }
    void LevelOrder(node *root) {
	if(root == NULL) return;
	queue<node*> q;
	q.push(root);  
	while(!q.empty()) {
		node* current = q.front();
		q.pop();
		cout<<current->data<<" ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
	}
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
        LevelOrder(root);
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
        airlines.insert(n);
    }
    test(airlines.display());
    return 0;
}