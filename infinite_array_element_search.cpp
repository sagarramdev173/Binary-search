/*
    https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
    Find position of an element in a sorted array of infinite numbers
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])

using namespace std;
int BinarySearch(int a[],int start,int end,int item)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==item)
        return mid;
        if(a[mid]<=item)
            return BinarySearch(a,mid+1,end,item);
        return BinarySearch(a,start,mid-1,item);
    }
    return -1;
}
// function to search start end of element to do binary search
int InfiniteArraySearch(int a[],int item)
{
    int res=-1;
    int start=0;
    int end=1;
    while (a[end]<=item)            //till the element doesn't come under start and end keep increasing them
    {
        start=end;
        end=end*2;
    }
    res=BinarySearch(a,start,end,item);
    return res;
}
int main(int argc, char const *argv[])
{
    int a[] = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170}; 
    // int size=arr(a); // as array is infinite we can calucalte array size
    int item=130;
    int res=InfiniteArraySearch(a,item);
    cout<<res<<endl;    
    return 0;
}