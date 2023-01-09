#include<bits/stdc++.h>
using namespace std;



int main()
{
    int Size,val;
    cin>>Size;
    int *arr=new int[Size];
    for(int i=0;i<Size;i++)
    {
        int a;cin>>a;
        arr[i]=a;
    }
    cin>>val;
    int count=0;
    for(int i=0;i<Size;i++)
    {
        if(val==arr[i])
        {
            count++;
        }
    }
    int *temparr=new int[Size-count];
    for(int i=0,j=0;i<Size;i++)
    {
        if(arr[i]==val)
        {
            continue;
        }
        temparr[j++]=arr[i];
    }
    for(int i=0;i<Size-count;i++)
    {
        cout<<temparr[i]<<" ";
    }
}
