#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
using namespace std;
int Binary_search(int a[],int item,int start,int end)
{
    if(end>=start)   
    {
        int mid=start+(end-start)/2; // to stop the over flow of int
        if(a[mid]==item)
        return mid;
        if(a[mid]>item)
            return Binary_search(a,item,start,mid-1);           
         return Binary_search(a,item,mid+1,end);              
    }
     return -1;
}

int main(int argc, char const *argv[])
{
    int arr[]={2,3,4,5,6,7,8,9,10,11,12,13,14,19,20,25,33};    
    int n=sizeof(arr)/sizeof(arr[0]);
    int item=31;    
    cout<<Binary_search(arr,item,0,n-1);
    return 0;
}