/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10305.inp"
#define fo "10305.out"
/**/
using namespace std;
/**/
int n;
int vt[105];
/**/
void khoitao()
{
    int i;
    for(i=0;i<n;i++)
        vt[i] = i+1;
}
/**/
bool timsau(int x,int y)
{
    int i,j;
    for(i=0;i<n;i++)
        if(vt[i] == x)
        {
            for(j=i+1;j<n;j++)
                if(vt[j] == y)
                    return false;
            return true;
        }
}
/**/
void chen(int x,int y)
{
    int i,j;
    for(i=0;i<n;i++)
        if(vt[i] == x)
            for(j=i;j>=0;j--)
            {
                vt[j] = vt[j-1];
                if(vt[j-1] == y)
                {
                    vt[j-1] = x;
                    return;
                }
            }
}
/**/
void output()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d",vt[i]);
    }
    printf("\n");
}
/**/
void input()
{
    int i;
    int x,y;
    int m;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            if(timsau(x,y))
                chen(x,y);
        }
        output();
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
