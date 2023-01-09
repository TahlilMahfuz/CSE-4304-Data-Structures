#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()
 
using namespace std;

class BIT{
    vector<int>v,tree;
    public : 
    BIT(int size){
        v.resize(size);
        tree.resize(size);
    }

    void insert(vector<int>vec){
        v=vec;
        for(int i=1;i<=v.size();i++){
            update(i,v[i]);
        }
    }

    void update(int index,int val){
            while(index<=v.size()){
                tree[index]+=val;
                index+=(index & (-index));
            }
    }

    int rsq(int from,int to){
        return getSum(to)-getSum(from-1);
    }

    int getSum(int index){
        int sum=0;
        while(index>0){
            sum+=tree[index];
            index-=index & -index;
        }
        return sum;
    }

    void print(){
        for(auto e:tree){
            cout<<e<<" ";
        }
        cout<<endl;
    }

};


signed main()
{
    fio;


    return 0;
}