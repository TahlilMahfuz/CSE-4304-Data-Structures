#include<bits/stdc++.h> 
using namespace std;

class node
{
    public:

    int data;
    node* right;
    node* left;

    node()
    {
        right=NULL;
        left=NULL;
    }
    node(int x)
    {
        right=NULL;
        left=NULL;
        data=x;
    }
};

class SplayTree{
    public:
    node* root=NULL;

    node* rightRotate(node* x){
        node* y =x->left;
        x->left=y->right;
        y->right=x;
        return y;
    }
    node* leftRotate(node* x){
        node* y =x->right;
        x->right=y->left;
        y->left=x;
        return y;
    }

    node* splay(node *r,int key) 
    { 
        if(r==NULL || r->data==key) return r; 
        if (r->data>key) 
        { 
            if(r->left == NULL) return r;  
            if(r->left->data > key) 
            { 
                r->left->left=splay(r->left->left, key); 
                r=rightRotate(r); 
            } 
            else if(r->left->data < key) 
            { 
                r->left->right=splay(r->left->right,key); 
                if(r->left->right!=NULL)r->left=leftRotate(r->left); 
            } 
            if(r->left==NULL){
                return r;
            }
            else return rightRotate(r);
        } 
        else  
        { 
            if(r->right==NULL) return r; 
            if(r->right->data>key) 
            { 
                r->right->left=splay(r->right->left,key); 
                if (r->right->left!=NULL)r->right=rightRotate(r->right); 
            } 
            else if(r->right->data<key) 
            {  
                r->right->right=splay(r->right->right,key); 
                r=leftRotate(r); 
            }
            if(r->right==NULL){
                return r;
            }
            else return leftRotate(r);
        }
    } 

    node* insert(node *r,int k)
    {   
        if (r == NULL)return new node(k); 
        r = splay(r, k);    
        if (r->data == k) return r;    
        node *newnode = new node(k);  
        if (r->data > k)  
        {  
            newnode->right = r;  
            newnode->left = r->left;  
            r->left = NULL;  
        }  
        else
        {  
            newnode->left = r;  
            newnode->right = r->right;  
            r->right = NULL;  
        }  
        return newnode;  
    }

    string search(node* r,int key)
    {
        node* t=splay(r,key);
        root=t;
        if(t->data==key){return "True";}
        else return "False";
    }

    node* delete_key(node* r,int key)
    {
        node *temp; 
        if (!r) return NULL;      
        r = splay(r, key); 
        if (key != r->data) return r;   
        if (!r->left) 
        { 
            temp = r; 
            r = r->right; 
        } 
        else
        { 
            temp = r; 
            r = splay(r->left, key); 
            r->right = temp->right; 
        } 
        delete temp; 
        return r;
    }
    void preorder(node *t)
    {
        if(t == NULL)return;
        cout<<" "<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
    void inorder(node *t)
    {
        if(t == NULL)return;
        preorder(t->left);
        cout<<" "<<t->data<<" ";
        preorder(t->right);
    }
    void postorder(node *t)
    {
        if(t == NULL)return;
        preorder(t->left);
        preorder(t->right);
        cout<<" "<<t->data<<" ";
    }
};


signed main()
{
    SplayTree st;
    int n;cin>>n;
    vector<int>v(n);
    for(auto &e:v){
        cin>>e;
        st.root=st.insert(st.root,e);
    }
    st.preorder(st.root);
    st.root=st.delete_key(st.root,2);
    st.preorder(st.root);
    cout<<st.search(st.root,2)<<endl; //False
    cout<<st.search(st.root,10)<<endl;//True
    cout<<st.search(st.root,122)<<endl;//False
    
    return 0;
}

