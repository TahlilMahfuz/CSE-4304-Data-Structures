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

priority_queue<int,vector<int>,greater<int>>minHeap;
priority_queue<int>maxHeap;
int cnt=0;

void addNum(int num) {
    if(cnt%2==0){
        maxHeap.push
    }
        cnt % 2 == 0 ? maxHeap.push(num) : minHeap.push(num);
        cnt++;
        
        int left = maxHeap.empty() ? -1e9 : maxHeap.top();
        int right = minHeap.empty() ? 1e9 : minHeap.top();
        if(left > right) { // wrong sorting
            maxHeap.pop(); maxHeap.push(right);
            minHeap.pop(); minHeap.push(left);
        }
    }
    
    double findMedian() {
        int left = maxHeap.empty() ? 0 : maxHeap.top();
        int right = minHeap.empty() ? 0 : minHeap.top();
        // cout << left << ", " << right<< endl;
        if(cnt %2 == 0) return (double)(left + right) / 2;
        else return left;
    }

signed main()
{
    fio;
    addNum(10);
    addNum(12);
    addNum(9);
    cout<<findMedian()<<endl;
    addNum(8);
    cout<<findMedian()<<endl;


    return 0;
}