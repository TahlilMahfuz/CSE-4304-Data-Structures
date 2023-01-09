#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()
 
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int>v(n),sum(n,0);
    for(auto &e:v)
    {
        cin>>e;
    }
    for(int i=0;i<v.size()-1;i++)
    {
        sum[i]= min(v[i],v[i+1])*2;
    }
    cout<<*max_element(all(sum))<<endl;
}

signed main()
{
    fio;
    solve();

    return 0;
}