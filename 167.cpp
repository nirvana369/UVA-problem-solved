/*
                                    Hoang Linh
                            
                    Problem: THE SULTAN'S SUCCESSORS - 167 (sultans.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "167.inp"
#define fo "167.out"
/**/
using namespace std;
/**/
int col[10],cheo1[20],cheo2[20],chess[10][10];
int maxtong;
/**/
void khoitao()
{
    int i;
    for(i=1;i<16;i++)
    {
        cheo1[i] = 0;
        cheo2[i] = 0;
    }
    maxtong = -1;
}
/**/
void dequy(int row,int tong)
{
    int i;
    
    if(row == 9 && tong > maxtong)
    {
        maxtong = tong;
        return;
    }
    
    for(i=1;i<=8;i++)
        if(col[i] == 0 && cheo1[row-i+8] == 0 && cheo2[row+i-1] == 0)
        {
            col[i] = 1;
            cheo1[row-i+8] = 1;
            cheo2[row+i-1] = 1;
            tong = tong + chess[row][i];
            
            dequy(row+1,tong);
            
            tong = tong - chess[row][i];
            col[i] = 0;
            cheo1[row-i+8] = 0;
            cheo2[row+i-1] = 0;
        }
}
/**/
void input()
{
    int itest,i,j;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)
                scanf("%d",&chess[i][j]);
            col[i] = 0;
        }
        khoitao();
        dequy(1,0);
        printf("%5d\n",maxtong);
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
