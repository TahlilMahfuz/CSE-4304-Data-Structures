#include "bits/stdc++.h"
using namespace std;

class Trie {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Trie() {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
    }
   
    void insert(string word) {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;
       cout<<"Word Inserted"<<endl;
    }
   
    bool search(string word) {
        int row = 1;
        for(int i = 0; i < word.size();i++){
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];
        }
        return (endmark[row] == 1);
    }

   
    bool startsWith(string prefix) {
        int row = 1;
        for(int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (pre[row] >= 1);
    }
};

signed main(){
    Trie* wordDictionary = new Trie;
    wordDictionary->insert("bad");
    wordDictionary->insert("dad");
    wordDictionary->insert("mad");
    cout<<wordDictionary->search("pad")<<endl; 
    cout<<wordDictionary->search("bad")<<endl; 
    cout<<wordDictionary->search(".ad")<<endl; 
    cout<<wordDictionary->search("b..")<<endl; 
}