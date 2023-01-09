#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int>q; //MaxHeeap
    for(;;)
    {
        int a;cin>>a;
        if(a==-1){break;}
        q.push(a);
    }

    while(q.size()>1)
    {
        int x=q.top();q.pop();
        int y=q.top();q.pop();

        if(x!=y)
        {
            q.push(x-y);
        }

        if(q.size()==0)
        {
            cout<<0<<endl;return 0;
        }
    }
    cout<<q.top()<<endl;
}