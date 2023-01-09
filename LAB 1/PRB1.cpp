#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef long long int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<" occurs: "<<e.second<<" times"<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()
 
using namespace std;

int cmp(pair<lli,lli>a,pair<lli,lli>b)
{
    return a.second>b.second;
}

signed main()
{
    fio;
    map<lli,lli>mp;
    for(;;)
    {
        lli a;cin>>a;
        if(a<=0){break;}
        else
        {
            if(mp.count(a)==0)
            {
                mp[a]=1;
            }
            else 
            {
                mp[a]++;
            }
        }
    }
    vector<pair<lli,lli>>v(mp.begin(),mp.end());
    sort(all(v),cmp);
    testfs(v);

    return 0;
}
