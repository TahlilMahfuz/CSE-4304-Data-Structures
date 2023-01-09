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
    map<int,bool> map;
    lli n;
    while(1){
        cin>>n;
        if(n==-1){break;}
        map.insert({n,1});
    }
    lli a,var;cin>>a;
    var=a;
    if((map.size()/2)%2==0)
    {
        for(int i=0;i<var/2+1;i++){
            //cout<<a<<" "<< abs(a-var)<<endl<<endl;
            if(map[a] && map[abs(a-var)]){
                cout<<"("<<a<<","<<abs(a-var)<<")"<<endl;
            }
            else if(map[a*a]){
                cout<<"("<<a<<","<<a<<")"<<endl;
            }
            --a;
            //cout<<a<<"HI"<<endl;
        }
    }
    else{
        for(int i=0;i<var/2+1;i++){
            //cout<<a<<" "<< abs(a-var)<<endl<<endl;
            if(map[a] && map[abs(a-var)]){
                cout<<"("<<a<<","<<abs(a-var)<<")"<<endl;
            }
            else if(map[a*a]){
                cout<<"("<<a<<","<<a<<")"<<endl;
            }
            --a;
            //cout<<a<<"HI"<<endl;
        }
    }
    return;
    
}

signed main(){

    solve();

    return 0;
}