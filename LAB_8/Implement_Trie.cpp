#include "bits/stdc++.h"
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
        cout<<"Word insterted"<<endl;
    }
   
    bool search(string word) {
        Trie* curr = this;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(c=='.'){
                for(auto e: curr->children)
                    if(e && e->search(word.substr(i+1))){
                        return true;
                    }    
                return false;
            }
            if(curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        }
        return curr && curr->end;
    }
};

signed main(){
    Trie* wordDictionary = new Trie();
    wordDictionary->insert("bad");
    wordDictionary->insert("dad");
    wordDictionary->insert("mad");
    cout<<wordDictionary->search("pad")<<endl; 
    cout<<wordDictionary->search("bad")<<endl; 
    cout<<wordDictionary->search(".ad")<<endl; 
    cout<<wordDictionary->search("b..")<<endl; 
}

