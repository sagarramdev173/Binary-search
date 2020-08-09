/*
    https://www.includehelp.com/icp/maximum-value-in-a-bitonic-array.aspx
    Maximum value in a bitonic array
    Input:
    1 4 8 3 2
    Output:
    8
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
int FindPeak(int a[],int start,int end,int size)
{
    int mid=start+(end-start)/2;
    if(mid>0 && a[mid]>a[mid-1] && a[mid]>size-1 && a[mid]>a[mid+1])
        return a[mid];
    else if(a[mid]>0 &&a[mid+1]>a[mid])
     return FindPeak(a,start,mid-1,size);
    else
    {
        return FindPeak(a,mid+1,end,size);
    }
    
}
int FindMax(int a[],int end)
{
    int res=FindPeak(a,0,end,end+1);
    return res;
}
int main(int argc, char const *argv[])
{
    int a[]={1,4,8,3,2};
    int size=arr(a);
    int res=FindMax(a,size-1);
    cout<<res<<endl;
    return 0;
}