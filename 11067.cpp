/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11067.inp"
#define fo "11067.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[2] = {1,0,
                0,1};
long long d[110][110];
bool w[110][110];
int nhang,ncot;
long long cpath;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<=nhang;i++)
        for(j=0;j<=ncot;j++)
        {
            w[i][j] = true;
            d[i][j] = 0;
        }
}
/**/
long long dq(int hang,int cot)
{
    int i;
    int x,y;
    
    if(hang == nhang && cot == ncot)
        return 1;
    if(!d[hang][cot])
        for(i=0;i<2;i++)
        {
            x = hang + h[i].x;
            y = cot + h[i].y;
            if(x >= 0 && x <= nhang && y >= 0 && y <= ncot)
                if(w[x][y])
                    d[hang][cot] += dq(x,y);
        }
    return d[hang][cot];
}
/**/
void output()
{
    if(cpath == 0)
        printf("There is no path.\n");
    else if(cpath == 1)
        printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
    else
        printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",cpath);
}
/**/
void input()
{
    int i;
    int n,x,y;
    while(scanf("%d %d",&ncot,&nhang))
    {
        if(!nhang && !ncot)
            break;
        khoitao();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&y,&x);
            if(x >= 0 && x <= nhang && y >= 0 && y <= ncot)
                w[x][y] = false;
        }
        cpath = dq(0,0);
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
