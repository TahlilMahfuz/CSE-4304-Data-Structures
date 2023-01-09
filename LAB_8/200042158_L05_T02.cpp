#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.begin(),v.end()
using namespace std;

class Trie {
public:
    vector<Trie*>children;
    bool end; 
    Trie() {
        children=vector<Trie*>(26,nullptr);
        end=false;
    }
   
    void insert(string word) {
        Trie* curr=this;
        for(auto e:word){
            if(curr->children[e-'a']==nullptr){
                curr->children[e-'a']= new Trie();
            }
            curr=curr->children[e-'a'];
        }
        curr->end=true;
    }
    vector<string> searchWord(Trie *trie,string &prefix) {
        vector<string> result;
        for (auto &e : prefix) {
            int index = e - 'a';
            trie = trie->children[index];
        }
        gototheend(trie, prefix, result);
        return result;
    }
    void gototheend(Trie *trie, string pre, vector<string> &result) {
        if (result.size() == 3)
            return;
        if (trie->end)
            result.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i])
                gototheend(trie->children[i], pre + (char)(i + 'a'), result);
        }
    }
};

signed main(){
    vector<string>products;
    string s;
    cin>>s;
    while(s!="0"){
        products.push_back(s);
        cin>>s;
    }
    sort(all(products));
    // test(products);
    cout<<endl;
    Trie* wordDictionary = new Trie();
    for(auto e:products){
        wordDictionary->insert(e);
    }
    string search,prefix;
    cin>>search;
    vector<vector<string>>result;
    for(auto e:search){
        prefix+=e;
        //cout<<prefix<<endl;
        result.push_back(wordDictionary->searchWord(wordDictionary,prefix));
    }
    for(auto e:result){
        for(auto x:e){
            cout<<x<<endl;
        }
        cout<<endl;
    }
}

