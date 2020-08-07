#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
using namespace std;
// program to find the first occurence of an element 
int Binary_search(int a[],int item,int start,int end)
{
    int res=-1;
    while(end>=start)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==item)
            {
                res=mid;
                start=mid+1; // for last occurence of element
                // end=mid-1;   // for first occurence of element 
            }
        else if(a[mid]>item)
                end=mid-1;
        else
        {
            start=mid+1;
        }        
    }
     return res;
}

int main(int argc, char const *argv[])
{
    int arr[]={2,3,4,5,6,7,8,9,10,10,10,11,12,13,14,19,20,25,33};    
    int n=sizeof(arr)/sizeof(arr[0]);
    int item=10;    
    cout<<Binary_search(arr,item,0,n-1);
    return 0;
}