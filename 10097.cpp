/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10097.inp"
#define fo "10097.out"
/**/
struct toado{
                int x,y;
            };
toado xp;
toado q[10010];
int kt,n;
bool d[105][105];
int a[105][105],kc[10010];
/**/
int solve()
{
    int dau,cuoi;
    int i;
    int r,c;
    
    dau = -1;
    cuoi = 0;
    d[xp.x][xp.y] = false;
    q[0] = xp;
    kc[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        xp = q[dau];
            
        if(a[xp.x][xp.y] > 0)
        {
            r = a[xp.x][xp.y];
            c = xp.y;
            if(d[r][c])
            {
                cuoi++;
                q[cuoi].x = r;
                q[cuoi].y = c;
                kc[cuoi] = kc[dau] + 1;
                if(r == kt || c == kt)
                    return kc[cuoi];
                d[r][c] = false;
            }
        }
        
        if(a[xp.y][xp.x] > 0)
        {
            r = xp.x;
            c = a[xp.y][xp.x];
            if(d[r][c])
            {
                cuoi++;
                q[cuoi].x = r;
                q[cuoi].y = c;
                kc[cuoi] = kc[dau] + 1;
                if(r == kt || c == kt)
                    return kc[cuoi];
                d[r][c] = false;
            }
        }
    }
    return -1;
}
/**/
void input()
{
    int kq,id;
    int i,j;
    id = 1;
    while(scanf("%d",&n) && n)    
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                d[i][j] = true;
            }
        scanf("%d %d %d",&xp.x,&xp.y,&kt);
        kq = solve();
        printf("Game #%d\n",id++);
        if(kq == -1)
            printf("Destination is Not Reachable !\n");
        else
            printf("Minimum Number of Moves = %d\n",kq);
        printf("\n");
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
