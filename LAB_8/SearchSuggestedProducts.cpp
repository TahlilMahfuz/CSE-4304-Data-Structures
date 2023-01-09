#include "bits/stdc++.h"
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
struct TrieNode {
    TrieNode *children[26] = {NULL};
    bool endOfWord = false;
};
class Solution {
public:
    void insertWord(TrieNode *trie, string &word) {
        for (char &c : word) {
            int index = c - 'a';
            if (!trie->children[index])
                trie->children[index] = new TrieNode;
            trie = trie->children[index];
        }
        trie->endOfWord = true;
    }
    vector<string> searchWord(TrieNode *trie, string &prefix) {
        vector<string> result;
        for (char &c : prefix) {
            int index = c - 'a';
            if (!trie->children[index])
                return {};
            trie = trie->children[index];
        }
        gototheend(trie, prefix, result);
        return result;
    }
    void gototheend(TrieNode *trie, string pre, vector<string> &result) {
        if (result.size() == 3)
            return;
        if (trie->endOfWord)
            result.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i])
                gototheend(trie->children[i], pre + (char)(i + 'a'), result);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        TrieNode *trie = new TrieNode;
        for (string &prod : products)
            insertWord(trie, prod);
        vector<vector<string>> result;
        string prefix;
        for (char &c : search) {
            prefix += c;
            result.push_back(searchWord(trie, prefix));
        }
        return result;
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
    Solution dictionary;
    TrieNode *trie=new TrieNode();
    for(auto e:products){
        dictionary.insertWord(trie,e);
    }
    string search,prefix;
    cin>>search;
    vector<vector<string>>result;
    for(auto e:search){
        prefix+=e;
        result.push_back(dictionary.searchWord(trie,prefix));
    }
    for(auto e:result){
        int i=0;
        for(auto x:result[i]){
            cout<<x;
        }
        i++;
        cout<<endl;
    }
}