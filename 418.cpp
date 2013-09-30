/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "418.inp"
#define fo "418.out"
#define nhang 4
#define ncot 11
/**/
using namespace std;
/**/
char str[5][13];
int k[5];
bool d[5];
int kq;
/**/
bool chk(int len)
{
    if(len < ncot)
        return true;
    return false;
}
/**/
void cal(int a,int b,int c,int d)
{
    int q,r,s,u,v,w,x,y,z;
    for(u=1;u<ncot-2;u++)
        for(v=1;v<ncot-2;v++)
            if(str[a][u] == str[c][v])
            {
                for(w=u+2;w<ncot;w++)
                    for(x=1;x<ncot-2;x++)
                        if(str[a][w] == str[d][x])
                        {
                            for(y=1;y<ncot-2;y++)
                                for(z=v+2;z<ncot;z++)
                                {
                                    q = y + w - u;
                                    r = x + z - v;
                                    if(str[b][y] == str[c][z] && chk(q) && chk(r) && str[b][q] == str[d][r])
                                        kq = max(kq,(w - u - 1) * (z - v - 1));
                                }
                        }
            }
}

/**/
void permu(int id)
{
    int i;
    if(id == nhang)
    {
        cal(k[0],k[1],k[2],k[3]);
        return;
    }
    
    for(i=0;i<nhang;i++)
        if(d[i])
        {
            d[i] = false;
            k[id] = i;
            
            permu(id+1);
            
            d[i] = true;
        }
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%s",&str[0]);
        if(str[0][0] == 'Q')
            break;
        d[0] = true;
        for(i=1;i<4;i++)
        {
            d[i] = true;
            scanf("%s",&str[i]);
        }
        kq = 0;
        permu(0);
        printf("%d\n",kq);
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
