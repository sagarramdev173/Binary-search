/*
    https://leetcode.com/problems/find-peak-element/
    Find Peak Element
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.
*/

#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
int FindPeak(int a[],int start,int end,int size)
{
   int mid=start+(end-start)/2;
    
    if((mid==0 ||(a[mid-1]<=a[mid]) && 
        mid==size-1 || a[mid+1]<=a[mid]))
        return mid;
    else if( mid>0 && a[mid-1]>a[mid])
     return FindPeak(a,start,mid-1,size);
    else
       return FindPeak(a,mid+1,end,size);    
    return -1;
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,1};
    int size=arr(a);
    int res=FindPeak(a,0,size-1,size);
    cout<<res<<endl;
    return 0;
}