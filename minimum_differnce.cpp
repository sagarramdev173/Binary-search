/*
    Given a sorted array, find the element in the array which has minimum difference with the given number.
    a[]={4,6,10} key=7
    o/p=1 or index of 6
*/
#include<iostream>
#include<math.h>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
int MinDiff(int a[],int start,int end,int item)
{
    while(start<=end)
    {        
        int mid=start+(end-start)/2;      
        if(a[mid]==item)
            return mid;
        if(a[mid]>=item)
             end=mid-1;
        else if (a[mid]<=item)
        {
           start=mid+1;
        }        
    } 
    // start and end will be poiniting to the nearest neighbour to the key
    // i.e start will be poiniting to the 10 and  end =6
    int F1=abs(a[end]-item);
    int F2=abs(a[start]-item);
    return (F1>F2)? a[start]:a[end];
}
int main(int argc, char const *argv[])
{
    int a[]={4,6,10};
    int key=7;
    int size=arr(a);
    int res=MinDiff(a,0,size-1,key);
    cout<<res<<endl;
    return 0;
}