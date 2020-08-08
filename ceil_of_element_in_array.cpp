/*
    https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
    For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
    For x = 0:    floor doesn't exist in array,  ceil  = 1
    For x = 1:    floor  = 1,  ceil  = 1
    For x = 5:    floor  = 2,  ceil  = 8
    For x = 20:   floor  = 19,  ceil doesn't exist in array
*/

#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
int CeilSearch(int a[],int start,int end,int item)
{
    int res=-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==item)
         return a[mid];
        if (a[mid]<=item)
        {        
            start=mid+1;
        }
        else if(a[mid]>=item)
        {
            res=a[mid]; 
            end=mid-1;           
        }   
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    int a[]={1, 2, 8, 10, 10, 12, 19};
    int size=arr(a);
    int item=1;
    int ceil=CeilSearch(a,0,size-1,item);
    cout<<ceil<<endl;
    return 0;
}