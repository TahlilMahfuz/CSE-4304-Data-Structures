#include<bits/stdc++.h>
#define test(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
using namespace std;

signed main(){
    vector<int>v;
    while(1){
        int n;cin>>n;
        if(n==-1){break;}
        v.push_back(n);
    }
    stack<int>stack;
    int count=1;
    stack.push(v[0]);
    int root=1e-10,error=0;
    
    for(int i=0;i<v.size();i++){
        if(v[i]<root){
            cout<<"not valid"<<endl;
            error++;
            break;
        }
        while (!stack.empty()&&stack.top()<v[i]) {
            root=stack.top();
            stack.pop();
        }
        stack.push(v[i]);
    }
    if(error==0){
        cout<<"valid"<<endl;
    }
}