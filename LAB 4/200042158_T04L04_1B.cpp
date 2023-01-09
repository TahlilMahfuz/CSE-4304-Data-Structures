#include <iostream>
#include <queue>

using namespace std;

void solve()
{
    queue<pair<int,int>>q;//index ele
    for(int i=0;;i++)
    {
        int a;cin>>a;
        if(a==-1)
        {
            break;
        }
        if(a==0)
        {
            continue;
        }
        q.push({i,a});
    }
    int count=0;
    int k;cin>>k;
    for(int i=0;;i++)
    {
        //cout<<q.front().second<<endl;
        if(q.front().second!=0)
        {
            q.front().second--;
            //cout<<q.front().second<<"After"<<endl;
            count++;
            if(q.front().second==0)
            {
                if(q.front().first==k)
                {
                    cout<<endl<<count<<endl;return;
                }
                q.pop();
                continue;
            }
            pair<int,int>p;
            p=q.front();
            q.pop();
            q.push(p);
        }
    }
}

signed main()
{
    solve();
    return 0;
}
