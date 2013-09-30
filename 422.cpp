/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "422.inp"
#define fo "422.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
char a[110][110];
int n;
/**/
void solve(char s[])
{
    int i,j,k;
    int px,py;
    int l,d;
    l = strlen(s)-1;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[0] == a[i][j])
                for(k=1;k<8;k++)
                {
                    px = i + h[k].x * l;
                    py = j + h[k].y * l;
                    if(px >= 0 && px < n && py >= 0 && py < n)
                    {
                        px = i;
                        py = j;
                        d = 0;
                        while(d <= l)
                        {
                            if(s[d] != a[px][py])
                                break;
                            if(d == l)
                                break;
                            d++;
                            px += h[k].x;
                            py += h[k].y; 
                        }
                        if(d == l && s[d] == a[px][py])
                        {
                            printf("%d,%d %d,%d\n",i+1,j+1,px+1,py+1);
                            return;
                        }
                    }
                }
    printf("Not found\n");
}
/**/
void input()
{
    int i;
    char temp[1100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",&a[i]);
    while(true)
    {
        scanf("%s",&temp);
        if(temp[0] == '0')
            break;
        solve(temp);
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
