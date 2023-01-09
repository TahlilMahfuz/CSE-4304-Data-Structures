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

int rabinKarp(string &t,string &p){
    int m=p.size();
    int n=t.size();
    unsigned int q=100000000;
    int x=11;
    int xpowerm=1;
    int hash_p=0;
    int hash_t=0;

    for(int i=0;i<m-1;i++){
        xpowerm=(xpowerm*m)%q;
    }

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

signed main(){
    string t,p;
    cin>>t>>p;
    cout<<rabinKarp(t,p)<<endl;;


    return 0;
}

