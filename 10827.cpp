/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10827.inp"
#define fo "10827.out"
/**/
using namespace std;
/**/
int a[100][100],ud[100][100];
int n;
/**/
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
void solve()
{
    int tong1,tong2,sum,sumpos;
    int i,j,h,c;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j] += a[i-1][j];
            //ud[i][j] = -10001;
        }
    
    
    sum = 0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if((i-1) || (j-1))    
            {
                if(i == 4 && j == 2)
                {
                    j = 2;
                }
                for(h=1;h<=i;h++)
                    for(c=1;c<=j;c++)
                    {
                        sumpos = a[i][j];
                        if((i - h) || (j - c))
                        {
                            tong1 = a[h-1][j];
                            tong2 = a[i][c-1];
                            tong1 -= a[h-1][c-1];
                            tong2 -= a[h-1][c-1];
                            tong1 += tong2;
                            if(tong1 > 0)
                                sumpos -= tong1 + tong2;
                            else
                                sumpos += tong1 + tong2;
                            if(sumpos > sum)
                                sum = sumpos;
                        }
           //             if(sumpos > ud[i][j])
             //               ud[i][j] = sum;
                    }
            }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout << ud[i][j] << " ";
        cout << endl;
        }*/
    cout << sum << endl;
}
/**/
void input()
{
    int i,j;
    int ntest;
    //scanf("%d",&ntest);
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<=n;i++)
        {
            if(!i)
                for(j=1;j<=n;j++)
                    a[i][j] = 0;
            else
                for(j=0;j<=n;j++)
                {
                    if(j)
                    {
                        scanf("%d",&a[i][j]);
                        if((j-1))
                            a[i][j] += a[i][j-1];
                    }
                    else
                        a[i][j] = 0;
                }
        }
        solve();
    }
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
