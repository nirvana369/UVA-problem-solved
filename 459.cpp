/*
                                            Hoang Linh
                                        
                                    Problem: GRAPH CONNECTIVITY - 459 (459.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "459.inp"
#define fo "459.out"
/**/
using namespace std;
/**/
char maxkt;
int d[200],a[200][200];
char q[100];
/**/
void khoitao()
{
    int i,j;
    for(i='A';i<=maxkt;i++)
    {
        for(j='A';j<=maxkt;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
void loang(char kt)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    d[kt] = 1;
    q[0] = kt;
    
    while(dau != cuoi)
    {
        dau++;
        for(i='A';i<=maxkt;i++)
        {
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                d[i] = 1;
                q[cuoi] = i;
            }
        }
    }
}
/**/
void solve()
{
    int i;
    int dem;
    
    dem = 0;
    for(i='A';i<=maxkt;i++)
        if(d[i] == 0)
        {
            loang(i);
            dem++;
        }
    printf("%d\n",dem);
}
/**/
void input()
{
    int ntest;
    char temp[10000];
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        sscanf(temp,"%c",&maxkt);
        khoitao();
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            a[temp[0]][temp[1]] = 1;
            a[temp[1]][temp[0]] = 1;
        }
        solve();
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
