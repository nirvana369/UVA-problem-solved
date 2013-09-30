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

#define fi "12337.inp"
#define fo "12337.out"
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
char s[110],a[60][60];
/**/
void phubi(int hang,int cot)
{
    int i, j;
    for(i=0;i<=hang;i++)
        for(j=0;j<=cot;j++)
            if(i == 0 || i == hang || j == 0 || j == cot)
                a[i][j] = '!';
            else
                a[i][j] = ' ';      
}
/**/
bool kiemtra(int hang,int cot)
{
    int i,j;
    
    for(i=1;i<=cot;i++)
        for(j=2;j<=hang;j++)
            if(a[1][i] != a[j][i])
                return false;
    return true;
}
/**/
void solve()
{
    int i;
    int hang,cot,x,y,dir;
    bool btf;
    int l,dem,kq;
    int row[60];
    
    l = strlen(s);
    kq = l;
    btf = false;
    for(i=l/2;i>=2;i--)
    {
        if(i == 18)
        {
            i = 18;
        }
        if(l % i == 0)
        {
            hang = l / i;
            cot = i;
            dem = 0;
            dir = 1;
            phubi(hang+1,cot+1);
            x = 1;
            y = 1;
            while(dem < l)
            {
                a[x][y] = s[dem++];
                if(a[x + h[dir].x][y + h[dir].y] != ' ') 
                {
                    dir++;
                    if(dir == 4)
                        dir = 0;
                }
                x += h[dir].x;
                y += h[dir].y;
            }
            if(kiemtra(hang,cot))
            {
                btf = true;
                if(hang + cot < kq)
                    kq = hang + cot;
            }
        }
    }
    
    if(btf)
        printf("%d\n",kq);
    else
        printf("-1\n");
}
/**/
void input()
{
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%s",&s);
        printf("Case %d: ",id++);
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
