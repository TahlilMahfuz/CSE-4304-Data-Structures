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
    map<int,int>map;
    lli n;
    while(1){
        cin>>n;
        if(n==-1){break;}
        if(map.count(n)){
            map[n]++;
        }
        else{
            map.insert({n,1});
        }
    }
    //testfs(map);

    int size=map.size();
    //cout<<size<<endl;
    int t;
    cin>>t;
    int var=t;
    bool flag=true;
    if(size%2==0){
        for(int i=0;i<var/2+1;i++){
            if(map[t] && map[abs(t-var)]){
                //for(int i=0;i<max(map[t],abs(t-var));i++)
                    cout<<"("<<t<<","<<abs(t-var)<<")"<<endl;!flag;
            }
            else if(map[t*t]){
                //for(int i=0;i<map[t];i++)
                    cout<<"("<<t<<","<<t<<")"<<endl;!flag;
            }
            t--;
        }
    }
    else{
        for(int i=0;i<var/2+1;i++){
            if(map[t] && map[abs(t-var)]){
                //for(int i=0;i<max(map[t],abs(t-var));i++)
                    cout<<"("<<t<<","<<abs(t-var)<<")"<<endl;!flag;
            }
            else if(map[t*t]){
                //for(int i=0;i<map[t];i++)
                    cout<<"("<<t<<","<<t<<")"<<endl;!flag;
            }
            t--;
        }
    }
    if(flag){
        cout<<"No pairs found"<<endl;
    }
}


signed main(){
    solve();

    return 0;
}




























































// void printpair(vector<int>v,int sum){
//     for(int i=0;i<v.size();i++){
//         for(int j=i+1;j<v.size();j++){
//             if(v[i]+v[j]==sum){
//                 cout<<v[i]<<" "<<v[j]<<endl;
//             }
//         }
//     }

// }

// void solve(){
//     vector<int>v;
//     int n;
//     while(1){
//         cin>>n;
//         if(n==-1){break;}
//         v.push_back(n);
//     }
//     int sum;cin>>sum;
//     printpair(v,sum);
// }