/*
    https://www.geeksforgeeks.org/search-almost-sorted-array/
    Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
    Output: 2 
    Output is index of 40 in given array
*/

#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
using namespace std;
// C++ program to find an element 
// in an almost sorted array 
int BinarySearch(int a[],int start,int end,int item)
{
    while(end>=start)
    {      
        int mid=start+(end-start)/2;
        if( a[mid] == item )
            return mid;
        else if( mid>start && a[mid-1]== item)
            return mid-1;        
        else if(mid<end && a[mid+1]== item)
            return mid+1;
        else if(a[mid]<item)
           return BinarySearch(a,mid+2,end,item);
         return BinarySearch(a,start,mid-2,item);
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[]={10, 3, 40, 20, 50, 80, 70};
    int key=70;
    int size=sizeof(arr)/sizeof(arr[0]);
    int res=BinarySearch(arr,0,size-1,key);
    cout<<res<<endl;
    return 0;
}