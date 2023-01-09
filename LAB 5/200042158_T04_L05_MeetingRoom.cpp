#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>> q; //MinHeap
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        q.push({a,true});
        q.push({b,false});
    }

    int room=0,maximum=0;
    while(!q.empty())
    {
        pair<int,bool>top=q.top();
        if(top.second)
        {
            room++;
        }
        else if(!top.second)
        {
            room--;
        }
        maximum=max(maximum,room); 
        q.pop();
    }
    cout<<maximum<<endl;

    return 0;
}

