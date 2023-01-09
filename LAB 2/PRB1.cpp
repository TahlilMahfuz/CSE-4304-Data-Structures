#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {

        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }
    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }
    void Reverse()
    {
        // implement this method
        int *temparr=new int[Size];
        for(int i=Size-1,j=0;i>=0;i--)
        {
            temparr[j++]=arr[i];
        }
        delete[] arr;
        arr=temparr;
    }
    void PushBack(int val)
    {
        // implement this method
        if(Capacity<=Size)
        {
            Capacity*=2;
            int *temparr=new int[Capacity];
            for(int i=0;i<Size;i++)
            {
                temparr[i]=arr[i];
            }
            delete[] arr;
            arr=temparr;
            for(int i=Size;i<Capacity;i++)
            {
                arr[i]=0;
            }
        }   
        arr[Size++]=val;
    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
};

void solve1()
{
    Dynamic_Array arr;
    for(int i =0;i<16;i++)
    {
        arr.PushBack(100 + i);
    }
    arr.Reverse();
    for(int i = 0; i < arr.Get_Size();i++)
    {
        cout << arr.Get(i)<<endl;
    }
}

int* ReturnAfterRemoveArr(Dynamic_Array numsArray,int val)
{
    int count=0;
    for(int i=0;i<numsArray.Size;i++)
    {
        if(val==numsArray.arr[i])
        {
            count++;
        }
    }
    int *temparr=new int[(numsArray.Size)-count];
    for(int i=0,j=0;i<numsArray.Size;i++)
    {
        if(numsArray.arr[i]==val)
        {
            continue;
        }
        temparr[j++]=numsArray.arr[i];
    }
    return temparr;
}

void solve2()
{
    int c;cin>>c;
    Dynamic_Array dyno1;
    dyno1.Size=c;
    for(int i=0;i<c;i++)
    {
        int a;cin>>a;
        dyno1.arr[i]=a;
    }
    int val;cin>>val;
    int count=0;
    for(int i=0;i<dyno1.Size;i++)
    {
        if(val==dyno1.arr[i])
        {
            count++;
        }
    }
    int *temparr=ReturnAfterRemoveArr(dyno1,val);
    for(int i=0;i<c-count;i++)
    {
        cout<<temparr[i]<<" ";
    }
}

int* ReturnAfterRemoveArr1(Dynamic_Array dyno1,int val)
{
    int c=dyno1.Size;
    for(int i=1;i<c-2;i++)
    {
        if(val==dyno1.arr[i])
        {
            for(int j=c-1;j>=0;j--)
            {
                if(dyno1.arr[i]!=val)
                {
                    swap(dyno1.arr[j],dyno1.arr[i]);
                }
            }
        }
    }
    return dyno1.arr;
}

void solve3()
{
    int c;cin>>c;
    Dynamic_Array dyno1;
    dyno1.Size=c;
    for(int i=0;i<c;i++)
    {
        int a;cin>>a;
        dyno1.arr[i]=a;
    }
    int val;cin>>val;
    int count=0;
    for(int i=0;i<c;i++)
    {
        if(dyno1.arr[i]==val)
        {
            count++;
        }
    }
    int *printarr=new int[c-count];
    printarr=ReturnAfterRemoveArr(dyno1,val);
    for(int i=0;i<c-count;i++)
    {
        if(printarr[i]==val)
        {
            continue;
        }
        cout<<printarr[i]<<" ";
    }
}

int main()
{
    //solve1();
    //solve2();
    //solve3();
}
