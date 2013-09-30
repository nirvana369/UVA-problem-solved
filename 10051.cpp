/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "10051.inp"
#define fo "10051.out"
/**/
using namespace std;
/**/
struct toado{
                int h,c;
            };
toado trc[510][7],kq[510];
int a[510][7],nhan[510][7],doi[8];
int n;
/**/
void dir(int val)
{
    if(val == 0)
        printf("front");
    else if(val == 1)
        printf("back");
    else if(val == 2)
        printf("left");
    else if(val == 3)
        printf("right");
    else if(val == 4)
        printf("top");
    else if(val == 5)
        printf("bottom");
}
/**/
void solve()
{
    int i,j,k,k1;
    toado t,vt;
    int len;
    
    len = 0;
    t.h = 0;
    
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            for(k=0;k<6;k++)
                for(k1=0;k1<6;k1++)
                    if(a[i][k] == a[j][k1] && nhan[i][k] < nhan[j][doi[k1]] + 1)
                    {
                        nhan[i][k] = nhan[j][doi[k1]] + 1;
                        if(nhan[i][k] > len)
                        {
                            len = nhan[i][k];
                            vt.h = i;
                            vt.c = k;
                        }
                        t.h = j;
                        t.c = doi[k1];
                        trc[i][k] = t;
                    }
        }
    }
    i = 0;
    while(vt.h != -1)
    {
        kq[i++] = vt;
        vt = trc[vt.h][vt.c];
    }
    printf("%d\n",len+1);
    for(j=i-1;j>=0;j--)
    {
        printf("%d ",kq[j].h+1);
        dir(kq[j].c);
        printf("\n");
    }
}
/**/
void input()
{
    int i,j;
    toado t;
    int id;
    
    doi[0] = 1;
    doi[1] = 0;
    doi[2] = 3;
    doi[3] = 2;
    doi[4] = 5;
    doi[5] = 4;
    ////
    id = 0;
    while(scanf("%d",&n) && n)
    {
        if(id++)
            printf("\n");
        printf("Case #%d\n",id);
        t.h = -1;
        t.c = -1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<6;j++)
            {
                scanf("%d",&a[i][j]);
                nhan[i][j] = 0;
                trc[i][j] = t;
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
