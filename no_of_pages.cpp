/*
    https://www.geeksforgeeks.org/allocate-minimum-number-pages/
    Allocate minimum number of pages
    Input : pages[] = {12, 34, 67, 90}
        m = 2
    Output : 113
    Explanation:
    There are 2 number of students. Books can be distributed 
*/

#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;

//utility function to check wether the case is possible with given no of student or not 
bool isvalid(int a[],int no_of_books,int student,int max)
{
    int sum=0;
    int no_of_student=1;
    for(int i=0;i<no_of_books;i++)
    {
        sum+=a[i];
        if(sum>max)
        {
            no_of_student++;
            sum=a[i]; 
        }
        if(no_of_student>student)
            return false;                   
    }    
    return true;
}

// finding the max no of pages for each student to read
int MaxPages(int pages[],int student,int no_of_books)
{
    if(no_of_books<student)
        return -1;
    int start=0;
    int end;
    for(int i=0;i<no_of_books;i++)
        end+=pages[i];    
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isvalid(pages,no_of_books,student,mid)==true)
            {                
                res=mid;
                end=mid-1;
            }
        else
            start=mid+1;
    }   
    return res;
}
int main(int argc, char const *argv[])
{
    int pages[]={12, 34, 67, 90};
    int MaxStudent=2;
    int no_of_books=arr(pages);
    int res=MaxPages(pages,MaxStudent,no_of_books);
    cout<<res<<endl;
    return 0;
}