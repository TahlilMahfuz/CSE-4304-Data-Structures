#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<" occurs: "<<e.second<<" times"<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()

using namespace std;

int BinarySearch(vector<int>v,int left,int right,int item)
{
    while(left<=right)
    {
        lli mid=(left+right)/2;
        if(item==v[mid])
        {
            return mid;
        }
        else if(v[mid]<item)
        {
            left=mid+1;
        }
        else if(v[mid]>item)
        {
            right=mid-1;
        }
    }
    return 1;
}

int RecursiveBinarySearch(vector<int>v,int left,int right,int item)
{
    lli mid=(left+right)/2;
    if(item==v[mid])
    {
        return mid;
    }
    else if(v[mid]<item)
    {
        return RecursiveBinarySearch(v,mid+1,right,item);
    }
    else if(v[mid]<item)
    {
        return RecursiveBinarySearch(v,left,mid-1,item);
    }
    return 1;
}

signed main()
{
    fio;
    vector<lli>v;
    for(;;)
    {
        lli a;cin>>a;
        if(a<0){break;}
        v.push_back(a);
    }
    lli s;cin>>s;
    if(find(v.begin(),v.end(),s)!=v.end())
    {
        cout<<BinarySearch(v,0,v.size()-1,s)<<endl;
        cout<<RecursiveBinarySearch(v,0,v.size()-1,s);
    }
    else 
    {
        cout<<-1<<endl;
    }
    

    return 0;
}