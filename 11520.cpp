/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11520.inp"
#define fo "11520.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
char a[12][12];
int d[12][12];
int n;
bool fil;
/**/
void dq(int hang,int cot)
{
    int i,j;
    int x,y;
    
    if(cot == (n - 1) && hang == n)
    {
        fil = true;
        for(i=0;i<n;i++)
            printf("%s\n",a[i]);
        return;
    }
    
    if(hang == n)
    {
        cot++;
        hang = 0;
    }
        
    if(d[hang][cot] == 2)
    {
        dq(hang+1,cot);
        return;
    }
    
    for(i='A';i<='Z';i++)
    {
        for(j=0;j<4;j++)
        {
            x = hang + h[j].x;
            y = cot + h[j].y;
            if(x >= 0 && x < n && y >= 0 && y < n)
                if(a[x][y] == i)
                    break;
        }
        if(j == 4)
        {
            a[hang][cot] = i;
            dq(hang+1,cot);
            a[hang][cot] = '.';
        }
        if(fil)
            return;
    }
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            for(j=0;j<n;j++)
                if(a[i][j] == '.')
                    d[i][j] = 0;
                else
                    d[i][j] = 2;
        }
        fil = false;
        printf("Case %d:\n",id++);
        dq(0,0);
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
