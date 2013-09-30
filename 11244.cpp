/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11244.inp"
#define fo "11244.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8]={-1,0,
            -1,1,
            0,1,
            1,1,
            1,0,
            1,-1,
            0,-1,
            -1,-1};
char a[110][110];
int dstar,nhang,ncot;
/**/
bool kiemtra(int hang,int cot)
{
    int i;
    int x,y;
    for(i=0;i<8;i++)
    {
        x = hang + h[i].x;
        y = cot + h[i].y;
        if(x >= 0 && y >= 0 && x < nhang && y < ncot)
            if(a[x][y] == '*')
                return false;
    }
    return true;
}
/**/
void xuly(int id)
{
    int i;
    for(i=0;i<ncot;i++)
        if(a[id][i] == '*')
        {
            if(kiemtra(id,i))
                dstar++;
        }
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d %d",&nhang,&ncot);
        if(!nhang && !ncot)
            break;
        gets(a[0]);
        dstar = 0;
        for(i=0;i<nhang;i++)
        {
            gets(a[i]);
            if(i)
                xuly(i-1);
        }
        xuly(nhang-1);
        printf("%d\n",dstar);
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
