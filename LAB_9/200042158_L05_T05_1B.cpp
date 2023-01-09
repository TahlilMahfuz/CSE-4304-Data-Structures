#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef long long int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()

using namespace std;

int rabinKarp(string &t,string &p){
    int m=p.size();
    int n=t.size();
    int q=128;
    int x=11;
    int xpowerm=1;
    int hash_p=0;
    int hash_t=0;

    xpowerm=(xpowerm*m)%q;

    for(int i=0;i<m;i++){
        hash_p=(hash_p*x+p[i])%q;
        hash_t=(hash_t*x+t[i])%q;
    }

    for(int i=0;i<n-m+1;i++){
        if(hash_p==hash_t)
        {
            return i;

        }
        if(i<n-m){
            hash_t=((hash_t-t[i]*xpowerm)*x+t[m+i])%q;
            if(hash_t<0){
                hash_t+=q;
            }
        }
    }
    return -1;
}

void solve(){
    vector<string>v;
    string s;
    while(1){
        cin>>s;
        if(s=="-1"){break;}
        v.push_back(s);
    }

    set<char>set;
    for(auto e:v.back()){
        set.insert(e);
    }
    string VectorLastString="";
    for(auto e:set){
        VectorLastString+=e;
    }

    v.pop_back();
    //sort(all(VectorLastString));
    for(auto e:v){
        string s=e;
        sort(all(s));
        set.clear();
        for(auto x:e){
            set.insert(x);
        }
        string str="";
        for(auto p:set){
            str+=p;
        }
        sort(all(str));
        // cout<<VectorLastString<<" "<<str<<endl;
        // cout<<rabinKarp(VectorLastString,str)<<endl<<endl;
        if(rabinKarp(VectorLastString,str)==0){
            cout<<e<<endl;
        }
    }
}

signed main(){
    fio;
    solve();

    return 0;
}