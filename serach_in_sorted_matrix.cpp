/*
    https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
    Search in a row wise and column wise sorted matrix
    Input: mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
    Output: Found at (2, 1)
*/

#include<iostream>
#define fo(i,n) for(int i=0;i<=n;i++)
#define arr(a) sizeof(a)/sizeof(a[0])
using namespace std;
pair<int,int> MatrixSearch(int a[][4],int item,int row,int colum)
{
    int i=0;
    int j=colum-1;
    pair<int ,int> res;
    while(i>=0 && i<row && j>=0 && j<colum)
    {   
        if(a[i][j]==item)
        {
            res.first=i+1;
            res.second=j+1;
            return res;
        }
        if(a[i][j]>item)
            j--;
        else if(a[i][j]<item)
            i++;
    }   
    return res;
}
int main(int argc, char const *argv[])
{
    int a[4][4]={ {10, 20, 30, 40},
                  {15, 25, 35, 45},
                  {27, 29, 37, 48},
                  {32, 33, 39, 50} 
                };
    int item=31;
    pair<int,int> res=MatrixSearch(a,item,4,4);
    cout<<res.first<<endl;
    cout<<res.second<<endl;
    return 0;
}