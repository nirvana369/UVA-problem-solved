/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10908.inp"
#define fo "10908.out"
/**/
using namespace std;
/**/
char a[110][110];
int nhang,ncot;
/**/
int solve(int hang,int cot)
{
    int i,j,kc,dd;
    int x,x1,y,y1;
    
    kc = 1;
    dd = 1;
    while(true)
    {
        if(hang-kc >=0 && hang + kc < nhang && cot-kc >= 0 && cot + kc < ncot)
        {
            x = hang - kc;
            x1 = hang + kc;
            y = cot - kc;
            y1 = cot + kc;
            for(i=x;i<=x1;i++)
                if(a[hang][cot] != a[i][y] || a[hang][cot] != a[i][y1])
                    return dd;
            for(i=y;i<=y1;i++)
                if(a[hang][cot] != a[x][i] || a[hang][cot] != a[x1][i])
                    return dd;
        }
        else
            return dd;
        kc++;
        dd+=2;
    }
}
/**/
void input()
{
    int ntest;
    int i;
    int kq,h,c,q;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&nhang,&ncot,&q);
        gets(a[0]);
        for(i=0;i<nhang;i++)
            gets(a[i]);
        printf("%d %d %d\n",nhang,ncot,q);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&h,&c);
            kq = solve(h,c);
            printf("%d\n",kq);
        }
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
