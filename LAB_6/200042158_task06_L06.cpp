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
    int t;cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        bst.freeset();
        bst.searchsubtree(x);
        bst.searchsubtree(y);
        vector<int>v=bst.returnvec();
        set<int>s;
        for(auto e:v){
            s.insert(e);
        }
        v.clear();
        for(auto e:s){v.push_back(e);}
        if(s.count(bst.returnroot()->data)){
            if(y!=bst.returnroot()->data){
                int x=bst.returnroot()->data;
                for(int i=0;i<v.size();i++){
                    if(v[i]==x){
                        v.erase(v.begin()+i);break;
                    }
                }
            }
        }
        cout<<*max_element(v.begin(),v.end())<<endl;
    }
    return 0;
}

