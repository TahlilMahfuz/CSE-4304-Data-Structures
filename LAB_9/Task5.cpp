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

string HashFunc(string s){
    set<char>set;
    for(auto e:s){
        set.insert(e);
    }
    string str="";
    for(auto e:set){
        str+=e;
    }
    return str;
}

void solve(){
    vector<string>v;
    string s;
    while(1){
        cin>>s;
        if(s=="1"){break;}
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
    unordered_map<string,vector<string>>result;
    for(auto e:v){
        string p;
        p=HashFunc(e);
        result[p].push_back(e);
    }
    sort(all(VectorLastString));
    //cout<<VectorLastString<<endl;
    for(auto e:result[VectorLastString]){
        cout<<e<<" ";
    }
    cout<<endl;
    //testfsv(result);
    
}

signed main(){

    solve();

    return 0;
}








// string getKey(string &str)
// {
//     bool visited[MAX_CHAR] = { false };
 
//     // store all unique characters of current
//     // word in key
//     for (int j = 0; j < str.length(); j++)
//         visited[str[j] - 'a'] = true ;
//     string key = "";
//     for (int j=0; j < MAX_CHAR; j++)
//         if (visited[j])
//             key = key + (char)('a'+j);
//     return key;
// }