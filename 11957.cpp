/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11957.inp"
#define fo "11957.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[2] = {-1,-1,
                -1,1};
long long d[110][110];
bool go[110][110];
int n;
/**/
long long dq(int hang,int cot)
{
    int i;
    int x,y;
    
    if(hang == 0 && go[hang][cot])
        return 1;
    if(d[hang][cot])
        return d[hang][cot] % 1000007;
    
    for(i=0;i<2;i++)
    {
        x = hang + h[i].x;
        y = cot + h[i].y;
        if(!go[x][y])
        {
            x += h[i].x;
            y += h[i].y;
        }
        if(x >= 0 && x < n && y >= 0 && y < n)
            if(go[x][y])
                d[hang][cot] += dq(x,y);
    }
    return d[hang][cot] % 1000007;
}
/**/
void input()
{
    int i,j;
    int x,y;
    char s[1000];
    long long kq;
    int ntest,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%s",&s);
            for(j=0;j<n;j++)
            {
                d[i][j] = 0;
                if(s[j] == 'B')
                    go[i][j] = false;
                else
                {
                    go[i][j] = true;
                    if(s[j] == 'W')
                    {
                        x = i;
                        y = j;
                    }
                }
            }
        }
        kq = dq(x,y) % 1000007;
        printf("Case %d: %lld\n",id++,kq);
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
