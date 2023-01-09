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
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* remove(int x, node* t) { 
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }
    int maxheight(node *node){
        if(node == NULL)
            return 0;
        else{
            int left_side=0;
            int right_side=0;
            left_side = maxheight(node -> left);
            right_side = maxheight(node -> right);
            if(left_side > right_side){
                return left_side + 1;
            }
            else{
                return right_side + 1;
            }
        }
    }
    vector<int>s;
    void search(int val){
        node* temp=root;
        while(true){
            if(temp==NULL){break;}
            if(val==temp->data){
                s.push_back(temp->data);
                break;
            }
            else if(val>temp->data){
                s.push_back(temp->data);
                temp=temp->right;
            }
            else if(val<temp->data){
                s.push_back(temp->data);
                temp=temp->left;
            }
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
    void remove(int x) {
        root = remove(x, root);
    }
    vector<int> display() {
        tree.clear();
        LevelOrder(root);
        return tree;
    }
    vector<int> returntree() {
        return tree;
    }
    int returnMaxheight(){
        return maxheight(root);
    }
    void searchsubtree(int x){
        search(x);
    }
    vector<int> returnvec(){
        return s;
    }
    void freeset(){
        s.clear();
    }
    node* returnroot(){
        return root;
    }
};

signed main(){
    BST bst;
    while(true){
        int n,count=0;cin>>n;
        if(n==-1){break;}
        bst.insert(n);
    }
    //test(bst.display());
    int t;cin>>t;
    while(t--){
        int x;
        cin>>x;
        bst.remove(x);
        test(bst.display());
    }
    return 0;
}

