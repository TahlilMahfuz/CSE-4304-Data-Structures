#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    priority_queue<int,vector<int>,greater<int>>q; //MinHeap
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;q.push(a);
    }

    int count=0;
    while(1)
    {
        if(q.top()>=k) //Minimum cookie sweetness must be greater than equal k.Top() is the minimum one
        {
            break;
        }

        int x=q.top();
        q.pop();
        if(q.empty())
        {
            cout<<-1<<endl;
            return 0;
        }
        int y=q.top();
        q.pop();
        int new_cookie=(1*x)+(2*y);
        q.push(new_cookie);
        count++;
    }
    cout<<count<<endl;
}