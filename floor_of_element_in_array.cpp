/*
    https://www.geeksforgeeks.org/floor-in-a-sorted-array/
    Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
    Output : 2
    2 is the largest element in arr[] smaller than 5.
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0]);
using namespace std;

int FloorSearch(int a[],int start,int end,int item)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==item)
            return mid;
        if(a[mid]<=item)
        {
            res=a[mid];
            start=mid+1;           
        }
        else if(a[mid]>item)
        {
            end=mid-1;            
        }
        
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int  a[] = {1, 2, 8, 10, 10, 12, 19};
    int size=arr(a)
    int item=5;
    int res=FloorSearch(a,0,size-1,item);
    cout<<res<<endl;
    return 0;
}