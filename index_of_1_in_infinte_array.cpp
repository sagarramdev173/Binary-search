/*
    https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/
    Input : arr[] = {0, 0, 1, 1, 1, 1} 
    Output : 2
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
// find the first occurence 
int FirstOcurence(int a[],int start,int end,int item)
{
    int res=-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==item)
        {
            res=mid;
            end=mid-1;
        }
        else if(a[mid]>=item)
            end=mid-1;
        else if (a[mid]<=item)
        {
            start=mid+1;
        }        
    }
    return res;
}
// finding the start and end ,to get the first occurence of 1's in array
int FirstOcuurenceInInfiniteArray(int a[],int item)
{
    int start=0;
    int end=1;
    while(a[end]==0)    // looping till end is equal to zero
    {
        start=end;
        end=end*2;
    }
    cout<<start<<endl;
    cout<<end<<endl;
    int res=FirstOcurence(a,start,end,item);
    return res;
}
int main(int argc, char const *argv[])
{
    int a[]= {0, 0, 1, 1, 1, 1} ;
    int key=1;
    int res=FirstOcuurenceInInfiniteArray(a,key);
    cout<<res<<endl;
    return 0;
}