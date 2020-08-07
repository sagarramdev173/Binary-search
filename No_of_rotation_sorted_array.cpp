#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
using namespace std;
//iterative approach to find the count of roatation
int no_of_rotation(int a[],int start,int end)
{
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        int next=(mid+1)%(end+1); 
        int prev=(mid+end-1)%(end+1);
        if(a[mid]<a[next]&& a[mid]<a[prev])
            return mid+1;
        if(a[start]<=a[mid])
            start=mid+1;
        else if(a[mid]<=a[end])
            end=mid-1;
    }
    return -1;
}
// recursive approach to find out the count of roatation
int no_of_rotation(int a[],int start,int end)
{    
     if(end<start)       
        return 0;
    if(end==start)
        return end;
     int mid=start+(end-start)/2;
     int prev=(mid+end-1)%(end+1);
     int next=(mid+1)%(end+1); 
     if(a[mid]<=a[prev]&& a[mid]<=a[next])
     return mid;
     if(a[start]<=a[mid])
     return no_of_rotation(a,mid+1,end); // going towards unsorted array
     else if (a[mid]<=a[end])         
     return no_of_rotation(a,start,mid-1);  // for going towards unsorted array
     return -1;
}
int main(int argc, char const *argv[])
{
    // int arr[]={15, 18, 2, 3, 6, 12};  
    int arr[]={7, 9, 11, 12, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<no_of_rotation(arr,0,n-1);
    return 0;
}