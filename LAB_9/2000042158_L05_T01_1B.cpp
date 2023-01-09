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

void solve(){
    unordered_map<int,bool>map;
    int n;
    while(1){
        cin>>n;
        if(n==-1){break;}
        map.insert({n,1});
    }
    int t;
    while(1){
        cin>>t;
        if(t==-1){break;}
        if(map[t]){
            continue;
        }
        else{
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    solve();

    return 0;
}