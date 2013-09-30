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
#include <vector>

#define fi "10171.inp"
#define fo "10171.out"
#define inf 1000000000
/**/
using namespace std;
/**/
long y[30][30],o[30][30];
int n;
char xp[3],kt[3],dir[3];
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<27;i++)
    {
        for(j=i+1;j<27;j++)
            y[i][j] = y[j][i] = o[i][j] = o[j][i] = inf;    
        y[i][i] = o[i][i] = 0;         
    }
}
/**/
void solve()
{
    int i,j,k;
    long ans;
    char kq[30];
    
    for(k='A'-65;k<='Z'-65;k++)
        for(i='A'-65;i<='Z'-65;i++)
            for(j='A'-65;j<='Z'-65;j++)
            {
                if(y[i][k] + y[k][j] < y[i][j])
                    y[i][j] = y[i][k] + y[k][j];
                    
                if(o[i][k] + o[k][j] < o[i][j])
                    o[i][j] = o[i][k] + o[k][j];
            }
    scanf("%s %s",&xp,&kt);
    ans = inf;
    dir[0] = 100;
    k = 0;
    for(i='A';i<='Z';i++)
        if(y[xp[0]-65][i-65] + o[kt[0]-65][i-65] <= ans)
        {
            if(y[xp[0]-65][i-65] + o[kt[0]-65][i-65] == ans)
                kq[k++] = i;
            else
            {
                k = 0;
                ans = y[xp[0]-65][i-65] + o[kt[0]-65][i-65];
                kq[k++] = i;
            }
        }
    if(ans != inf)
    {
        printf("%ld",ans);
        for(i=0;i<k;i++)
            printf(" %c",kq[i]);
        printf("\n");
    }
    else
        printf("You will never meet.\n");
}
/**/
void input()
{
    int i;
    char gen[3];
    int val;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s %s %s %s %d",&gen,&dir,&xp,&kt,&val);
            if(gen[0] == 'Y')
            {
                y[xp[0] - 65][kt[0] - 65] = val < y[xp[0] - 65][kt[0] - 65] ? val : y[xp[0] - 65][kt[0] - 65];
                if(dir[0] == 'B')
                    y[kt[0] - 65][xp[0] - 65] = y[xp[0] - 65][kt[0] - 65];
            }
            else
            {
                o[xp[0] - 65][kt[0] - 65] = val < o[xp[0] - 65][kt[0] - 65] ? val : o[xp[0] - 65][kt[0] - 65];
                if(dir[0] == 'B')
                    o[kt[0] - 65][xp[0] - 65] = o[xp[0] - 65][kt[0] - 65];
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
