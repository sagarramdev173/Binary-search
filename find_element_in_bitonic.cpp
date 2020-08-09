/*
    https://www.geeksforgeeks.org/find-element-bitonic-array/
    Find an element in Bitonic array
    Input :  arr[] = {-3, 9, 8, 20, 17, 5, 1};
    key = 20
    Output : Found at index 3
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
int FindPeak(int a[],int start,int end,int size)
{   
    int mid=start+(end-start)/2;
    if(mid>0 && a[mid]>a[mid+1] && mid<size-1 && a[mid]>=a[mid+1])
        return mid;
    else if(mid>0 && a[mid]<a[mid-1])
        return FindPeak(a,start,mid-1,size);
    else 
    {
        return FindPeak(a,mid+1,end,size);
    }    
}
int BianryOnAssecnding(int a[],int start,int end,int item)
{
    if(end<start)
        return -1;
    int mid=start+(end-start)/2;
    if(a[mid]==item)
        return mid;
    if(a[mid]>=item)
    return BianryOnAssecnding(a,start,mid-1,item);
    else  
    return BianryOnAssecnding(a,mid+1,end,item);    
}
int BinaryOnDessending(int a[],int start,int end,int item)
{
    if (end<start)
     return -1;
    int mid=start+(end-start)/2;
    if(a[mid]==item)
        return mid;
    if(a[mid]<=item)
    return BinaryOnDessending(a,start,mid-1,item);
    else
    return BinaryOnDessending(a,mid+1,end,item);    
}
int FindElementInBitonic(int a[],int start,int end,int size,int item)
{
    int peak=FindPeak(a,start,end,size);
    int F1=BianryOnAssecnding(a,0,peak-1,item);
    int F2=BinaryOnDessending(a,peak,end,item);
    return F1>=F2? (F1!=-1)?a[F1]:F1:a[F2];
}

int main(int argc, char const *argv[])
{
    int a[]={-3, 9, 8, 20, 17, 5, 1};
    int size=arr(a);
    int key=1;
    int res=FindElementInBitonic(a,0,size-1,size,key);
    cout<<res<<endl;
    return 0;
}