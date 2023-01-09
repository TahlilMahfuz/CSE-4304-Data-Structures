#include <bits/stdc++.h>
#define print(v) for(auto e:v){cout<<e<<" ";}cout<<endl;
 
using namespace std;

void Maxheapify(vector<int>&v,int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(v[largest]<v[left] && left<n)
    {
        largest=left;
    }
    if(v[largest]<v[right] && right<n)
    {
        largest=right;
    }
    
    if(largest!=i)
    {
        swap(v[i],v[largest]);
        Maxheapify(v,n,largest);
    }
}

void Build_Max_heap(vector<int>&v,int n)
{
    int lastNonLeafNode=(n/2)-1;
    for(int i=lastNonLeafNode;i>=0;i--)
    {
        Maxheapify(v,n,i);
    }
}

void MaxHeapSort(vector<int>&v,int n)
{
    int lastNonLeafNode=(n/2)-1;
    for(int i=lastNonLeafNode;i>=0;i--)
    {
        Maxheapify(v,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        Maxheapify(v,i,0);
    }
}


void Minheapify(vector<int>&v,int n,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(v[smallest]>v[left] && left<n)
    {
        smallest=left;
    }
    if(v[smallest]>v[right] && right<n)
    {
        smallest=right;
    }
    
    if(smallest!=i)
    {
        swap(v[i],v[smallest]);
        Minheapify(v,n,smallest);
    }
}

void MinHeapSort(vector<int>&v,int n)
{
    int lastNonLeafNode=(n/2)-1;
    for(int i=lastNonLeafNode;i>=0;i--)
    {
        Minheapify(v,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        Minheapify(v,i,0);
    }
}

void Build_Min_heap(vector<int>&v,int n)
{
    int lastNonLeafNode=(n/2)-1;
    for(int i=lastNonLeafNode;i>=0;i--)
    {
        Minheapify(v,n,i);
    }
}

int Heap_Minimum(vector<int>v)
{
    MinHeapSort(v,v.size());
    return v.back();
}

int Heap_Extract_Min(vector<int>&v)
{
    Build_Min_heap(v,v.size());
    int first=v[0];
    for(int i=1;i<v.size();i++){
        v[i-1]=v[i];
    }
    v.pop_back();
    Build_Min_heap(v,v.size());
    return first;
}

void Min_Heap_Insert(int val,vector<int>&v)
{
    v.push_back(val);
    Build_Min_heap(v,v.size());
}

signed main()
{
    vector<int>v;
    for(;;)
    {
        int a;cin>>a;
        if(a==-1)
        {
            break;
        }
        v.push_back(a);
    }
    // Build_Max_heap(v,v.size());
    // MaxHeapSort(v,v.size());
    // MinHeapSort(v,v.size());
    // print(v);

    //cout<<Heap_Minimum(v);
    // Min_Heap_Insert(10,v);
    // print(v);

    //Build_Min_heap(v,v.size());
    //print(v);


    int i;
    while(1){
        cin>>i;
        if(i==-1){break;}
        else if(i==1){
            cout<<Heap_Minimum(v)<<endl;
            print(v);
        }
        else if(i==2){
            cout<<Heap_Extract_Min(v)<<endl;
            print(v);
        }
        else if(i==3){
            int x;
            cin>>x;
            Min_Heap_Insert(x,v);
            print(v);
        }
        else break;
    }

    
    return 0;
}