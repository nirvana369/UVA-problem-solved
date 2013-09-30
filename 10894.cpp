/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10894.inp"
#define fo "10894.out"
/**/
using namespace std;
/**/
struct banner{
                char s[10];
            };
banner t[12][6];
int n;
/**/
void _init()
{
    strcpy(t[1][1].s,"*****");        strcpy(t[2][1].s,".***.");        strcpy(t[3][1].s,"*...*");
    strcpy(t[1][2].s,"*....");        strcpy(t[2][2].s,"*...*");        strcpy(t[3][2].s,"*...*");
    strcpy(t[1][3].s,"*****");        strcpy(t[2][3].s,"*****");        strcpy(t[3][3].s,"*...*");
    strcpy(t[1][4].s,"....*");        strcpy(t[2][4].s,"*...*");        strcpy(t[3][4].s,".*.*.");
    strcpy(t[1][5].s,"*****");        strcpy(t[2][5].s,"*...*");        strcpy(t[3][5].s,"..*..");
    
    strcpy(t[4][1].s,"*****");        strcpy(t[5][1].s,"*...*");        strcpy(t[6][1].s,"*****");
    strcpy(t[4][2].s,"*....");        strcpy(t[5][2].s,"*...*");        strcpy(t[6][2].s,"*...*");
    strcpy(t[4][3].s,"***..");        strcpy(t[5][3].s,"*****");        strcpy(t[6][3].s,"*****");
    strcpy(t[4][4].s,"*....");        strcpy(t[5][4].s,"*...*");        strcpy(t[6][4].s,"*.*..");
    strcpy(t[4][5].s,"*****");        strcpy(t[5][5].s,"*...*");        strcpy(t[6][5].s,"*..**");
    
    strcpy(t[7][1].s,"*****");        strcpy(t[8][1].s,"***..");        strcpy(t[9][1].s,"*****");
    strcpy(t[7][2].s,"..*..");        strcpy(t[8][2].s,"*..*.");        strcpy(t[9][2].s,"*...*");
    strcpy(t[7][3].s,"..*..");        strcpy(t[8][3].s,"*...*");        strcpy(t[9][3].s,"*...*");
    strcpy(t[7][4].s,"..*..");        strcpy(t[8][4].s,"*..*.");        strcpy(t[9][4].s,"*...*");
    strcpy(t[7][5].s,"*****");        strcpy(t[8][5].s,"***..");        strcpy(t[9][5].s,"*****");
    
    strcpy(t[10][1].s,"*...*");
    strcpy(t[10][2].s,".*.*.");
    strcpy(t[10][3].s,"..*..");
    strcpy(t[10][4].s,"..*..");
    strcpy(t[10][5].s,"..*..");
    
}
/**/
void horizontal()
{
    int i,j,k,y,x;
    
    for(i=1;i<6;i++)
    {
        for(y=0;y<n;y++)
        {
            for(j=1;j<11;j++)
            {
                x = 0;
                while(t[j][i].s[x])
                {
                    for(k=0;k<n;k++)
                        printf("%c",t[j][i].s[x]);
                    x++;
                }
                if(j != 10)
                    for(k=0;k<n;k++)
                        printf(".");
                    
                if(j == 4)
                    for(k=0;k<n*2;k++)
                        printf(".");
            }
            printf("\n");
        }
    }
}
/**/
void vertical()
{
    int i,j,k,c,x,y;
    n = -n;
    
    for(i=1;i<11;i++)
    {
        for(k=1;k<6;k++)
        {
            for(y=0;y<n;y++)
            {
                x = 0;
                while(t[i][k].s[x])
                {
                    for(c=0;c<n;c++)
                        printf("%c",t[i][k].s[x]);
                    x++;
                }
                printf("\n");
            }
        }
            
        if(i != 10)
            for(j=0;j<n;j++)
            {
                for(k=0;k<n*5;k++)
                    printf(".");
                printf("\n");
            }
            
        if(i == 4)
            for(j=0;j<n*2;j++)
            {
                for(k=0;k<n*5;k++)
                    printf(".");
                printf("\n");
            }
    }
}
/**/
void input()
{
    _init();
    while(scanf("%d",&n))
    {
        if(n == 0)
            break;
        if(n < 0)
            vertical();
        else
            horizontal();
        printf("\n\n");
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
