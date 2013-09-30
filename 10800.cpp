/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10800.inp"
#define fo "10800.out"
/**/
using namespace std;
/**/
char g[310][310],kq[310][310];
int mrow[310];
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<200;i++)
    {
        for(j=0;j<200;j++)
        {
            g[i][j] = ' ';
            kq[i][j] = ' ';
        }
        mrow[i] = 0;
    }
}
/**/
void xuly(char s[])
{
    int i,j,i1,j1;
    int l,x,y,h,w;
    int minh,minc,maxh,maxc;
    khoitao();
    l = strlen(s);
    x = 60;
    y = 2;
    for(i=0;i<l;i++)    
    {
        if(s[i] == 'C')
        {
            if(g[x][y] == '/')
            {
                x-=1;
                y+=1;
                g[x][y] = '_';
             //   printf("%c",s[i]);
            }
            else
            {
                y+=1;
                g[x][y] = '_';
               // printf("%c",s[i]);
            }
        }
        else if(s[i] == 'R')
        {
            if(g[x][y] != '/')
            {
                y+=1;
                g[x][y] = '/';
            //    printf("/");
            }
            else
            {
                x-=1;
                y+=1;
                g[x][y] = '/';
              //  printf("/");
            }
        }
        else if(s[i] == 'F')
        {
            if(g[x][y] == '/')
            {
                y+=1;
                g[x][y] = '\\';
               // printf("\\");
            }
            else
            {
                x+=1;
                y+=1;
                g[x][y] = '\\';
               // printf("\\");
            }
        }
    }
    maxh = maxc = 0;
    minh = minc = 100;
    for(i=0;i<130;i++)
    {
        for(j=0;j<130;j++)
            if(g[i][j] != ' ')
            {
                if(i > maxh)
                    maxh = i;
                if(i < minh)
                    minh = i;
                if(j > maxc)
                    maxc = j;
                if(j < minc)
                    minc = j;
            }
    }
    for(i=minh,i1=0;i<=maxh;i++,i1++)
    {
        kq[i1][0] = '|';
        for(j=minc,j1=2;j<=maxc;j++,j1++)
            kq[i1][j1] = g[i][j];
        for(j=j1-1;j>=0;j--)
            if(kq[i1][j] != ' ')
            {
                mrow[i1] = j;
                break;
            }
    }
    for(i=1;i<=maxc;i++)
        kq[i1][i] = '-';
    for(i=0;i<i1;i++)
    {
        for(j=0;j<=mrow[i];j++)
            printf("%c",kq[i][j]);
        printf("\n");
    }
    kq[i1][0] = '+';
    for(i=0;i<=maxc;i++)
        printf("%c",kq[i1][i]);
    printf("\n\n");
}
/**/
void input()
{
    int ntest,id;
    char temp[1000];
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%s",&temp);
        printf("Case #%d:\n",id++);
        xuly(temp);
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
