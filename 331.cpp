/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "331.inp"
#define fo "331.out"
/**/
using namespace std;
/**/
int n;
int dem;
int a[1000];
/**/
bool kiemtra()
{
    int i;
    for(i=1;i<n;i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}
/**/
void swapmem(int i,int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
/**/
void solve()
{
    int i;
    if(kiemtra())
    {
        dem++;
        return;
    }
    for(i=0;i<n-1;i++)
    {
        if(a[i] > a[i+1])
        {
            swapmem(i,i+1);
            solve();
            swapmem(i,i+1);
        }
    }
}
/**/
void input()
{
    int i;
    int id;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        dem = 0;
        if(!kiemtra())
            solve();
        printf("There are %d swap maps for input data set %d.\n",dem,id);
        id++;
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
