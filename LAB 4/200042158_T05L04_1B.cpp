#include <iostream>
#include <queue>
#include <map>

using namespace std;


void solve()
{
    queue<int>student,sandwitch;
    map<int,int>mp;
    mp[0]=0;
    mp[1]=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        mp[a]++;
        student.push(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        sandwitch.push(a);
    }
    int count=0;
    bool flag=0;
    for(;;)
    {
        if(student.front()==sandwitch.front())
        {
            mp[student.front()]--;
            student.pop();
            sandwitch.pop();
        }
        else 
        {
            int top= student.front();
            student.pop();
            student.push(top);
        }

        if(mp[sandwitch.front()])
        {
            continue;
        }
        else break;
    }
    cout<<student.size()<<endl;
}
signed main()
{
    solve();
    return 0;
}
