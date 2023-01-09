#include<iostream>
#include<queue>

using namespace std;

int ReturnWinner(int n,int k)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(q.size()!=1)
    {
        int x=k-1;
        while(x--)
        {
            int top=q.front();
            q.pop();
            q.push(top);
        }
        q.pop();
    }
    return q.front();
}

signed main()
{
    int n,k;
    cin>>n>>k;
    cout<<ReturnWinner(n,k)<<endl;

    return 0;
}
