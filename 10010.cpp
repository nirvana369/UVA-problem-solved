/*
                                                        Hoang Linh
                                                    
                                        Problem: WHERE'S WALDORF? - 10010 (10010.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10010.inp"
#define fo "10010.out"
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
char a[60][60],word[1000];
int len,nhang,ncot;
/**/
/**/
bool straight(int hang,int cot)
{
    int i;
    int dem;
    toado p;
    
    for(i=0;i<8;i++)
    {
        p.x = hang + h[i].x;
        p.y = cot + h[i].y;
        dem = 1;
        while(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot)
        {
            if(!(a[p.x][p.y] == word[dem] || a[p.x][p.y] + 32 == word[dem] || a[p.x][p.y] - 32 == word[dem]))
                break;
            if(dem == len-1)
                return true;
            p.x = p.x + h[i].x;
            p.y = p.y + h[i].y;
            dem++;
        }
    }
    return false;
}
/**/
void solve()
{
    int i,j;
    
    len = strlen(word);
    
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] == word[0] || a[i][j] + 32 == word[0] || a[i][j] - 32 == word[0])
                if(straight(i,j))
                {
                    printf("%d %d\n",i+1,j+1);
                    return;
                }
}
/**/
void input()
{
    int itest,i;
    int ntest,nw;
    
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d %d",&nhang,&ncot);
        gets(a[0]);
        for(i=0;i<nhang;i++)
            gets(a[i]);
        scanf("%d",&nw);
        for(i=0;i<nw;i++)
        {
            scanf("%s",&word);
            solve();
        }
        if(itest != ntest-1)
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
