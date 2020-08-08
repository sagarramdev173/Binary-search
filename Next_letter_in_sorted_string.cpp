/*
    Given an array of letters sorted in ascending order, 
    find the smallest letter in the the array which is greater than a given key letter.
*/
#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
char KeyGreater(char a[],int start,int end,char key)
{
    char res;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==key)
            start=mid+1;
        if(a[mid]>key)
        {
            res=a[mid];
            end=mid-1;
        }
        else if(a[mid]<key)
        {
            start=mid+1;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    char a[]={'a','b','d','e','f','g','h'};
    char key='a';
    int size=arr(a);
    char res=KeyGreater(a,0,size-1,key);
    cout<<res<<endl;
    return 0;
}