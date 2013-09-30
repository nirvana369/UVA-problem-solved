/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10009.inp"
#define fo "10009.out"
/**/
using namespace std;
/**/
int a[100][100],d[100];
char q[100],truoc[100];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i='A';i<='Z';i++)
    {
        for(j='A';j<='Z';j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
void output(int id)
{
    int i;
    char kq[100];
    int dem;
    char temp;
    temp = q[id];
    dem = 0;
    while(temp != truoc[temp])
    {
        kq[dem++] = temp;
        temp = truoc[temp];
    }
    kq[dem] = temp;
    for(i=dem;i>=0;i--)
        printf("%c",kq[i]);
    printf("\n");
    for(i=0;i<=id;i++)
        d[q[i]] = 0;
}
/**/
void loang(char c1,char c2)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = c1;
    d[c1] = 1;
    truoc[c1] = c1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i='A';i<='Z';i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
                truoc[i] = q[dau];
                if(i == c2)
                {
                    output(cuoi);
                    return;
                }
            }
    }
}
/**/
void input()
{
    int i;
    int m;
    char c1[1000],c2[1000];
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s %s",&c1,&c2);
            a[c1[0]][c2[0]] = 1;
            a[c2[0]][c1[0]] = 1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&c1,&c2);
            loang(c1[0],c2[0]);
        }
        if(ntest != 0)
            printf("\n");
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
