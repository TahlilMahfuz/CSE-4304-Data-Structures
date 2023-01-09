#include<bits/stdc++.h> 
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
    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){cin>>v[i];}
    BIT bittree= BIT(v.size());
    bittree.insert(v);
    bittree.print();

    cout<<bittree.getSum(10)<<endl;  //19
    cout<<bittree.rsq(1,3);          //3

    return 0;
}

// input: 
// 16
// 1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
