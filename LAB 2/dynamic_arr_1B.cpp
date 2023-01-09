
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
    }
    void PushBack(int val)
    {
        // implement this method
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

int main()
{
    Dynamic_Array arr;
    for(int i =0;i<16;i++)
    {
        arr.PushBack(100 + i);
    }

    for(int i = 0; i < arr.Get_Size();i++)
    {
        cout << arr.Get(i)<<endl;
    }


}
