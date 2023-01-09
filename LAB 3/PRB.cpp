#include<bits/stdc++.h>
using namespace std;


struct node
{
    int val;
    node * next;
};

class Singly_linked_list{
public:
    node *head, *tail;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PushBack(int n)
    {
        if(head==nullptr)
        {
            node *new_node=new node();
            new_node->val=n;
            new_node->next=head;
            head=new_node;
            tail=new_node;
        }
        else 
        {
            // node * new_node=new node();
            // new_node->val=n;
            // new_node->next=nullptr;
            // node *cur=head;
            // node *prev; 
            // while(cur!=nullptr)
            // {
            //     prev=cur;
            //     cur=cur->next;
            // }
            // prev->next=new_node;

            node * new_node = new node();
            new_node->val=n;
            new_node->next=nullptr;
            tail->next=new_node;
            tail=new_node;
        }
    }

    void PopBack()
    {
        node *second_next;
        second_next=head;
        while(second_next->next->next !=nullptr)
        {
            second_next=second_next->next;
        }
        delete(second_next->next);
        second_next->next=nullptr;
    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {
        node* prev = nullptr;
        node* curr = head;
        while (curr) {
            node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        tail = head;
        head = prev;

    }
};

void solve1()
{
    Singly_linked_list a;
    for(int i =1 ; i < 10; i++)
        a.PushBack(i);

    a.display();
    a.Reverse();
    a.PushBack(100);
    a.display();
    a.PopBack();
    a.display();
}

Singly_linked_list ReturnSecondHalf(Singly_linked_list a)
{
    int n=0;
    node *c=a.head;
    while(c!=nullptr)
    {
        n++;
        c=c->next;
    }
    Singly_linked_list arr;
    node *cur=a.head;
    int count=0;
    while(cur!=nullptr)
    {
        if(count>=(n/2))
        {
            arr.PushBack(cur->val);
            cur=cur->next;
            count++;
        }
        else 
        {
            cur=cur->next;
            count++;
        }
    }
    return arr;
}

void solve2()
{
    int n;cin>>n;
    Singly_linked_list a;
    for(int i=0;i<n;i++)
    {
        int ele;cin>>ele;
        a.PushBack(ele);
    }
    Singly_linked_list arr;
    arr=ReturnSecondHalf(a);
    arr.display();
}    

node* ReturnSecondHalf1(Singly_linked_list a)
{
    node *slow=a.head,*fast=a.head;
    node *cur=a.head;
    Singly_linked_list arr;
    while(fast!=nullptr && fast->next!=nullptr)//even odd
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void solve3()
{
    int n;cin>>n;
    Singly_linked_list a,arr;
    for(int i=0;i<n;i++)
    {
        int ele;cin>>ele;
        a.PushBack(ele);
    }
    node *slow=ReturnSecondHalf1(a);
    while(slow!=nullptr)
    {
        arr.PushBack(slow->val);
        slow=slow->next;
    }
    arr.display();
}

int main()
{
    //solve1();
    //solve2();
    solve3();
}
