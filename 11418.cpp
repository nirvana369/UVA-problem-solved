/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11418.inp"
#define fo "11418.out"
/**/
using namespace std;
/**/
struct str{
                char s[100];
            };
str ten[35][35];
int a[35][35],d[35],trai[35],phai[35],q[35],truoc[35],m[35];
int ntrai,nphai,last;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=ntrai;i++)
        for(j=1;j<=nphai;j++)
            a[i][j] = 0;
    for(i=1;i<=nphai;i++)
        phai[i] = 0;
}
/**/
void noi(int xp)
{
    int i;
    int dau,cuoi;
    int tmp;
    
    for(i=1;i<=nphai;i++)
        d[i] = 0;
        
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        tmp = q[dau];
        for(i=1;i<=nphai;i++)
            if(a[tmp][i] && !d[i])
            {
                truoc[i] = tmp;
                d[i] = 1;
                if(!phai[i])
                {
                    last = i;
                    return;
                }
                else
                {
                    cuoi++;
                    q[cuoi] = phai[i];
                }
            }
    }
}
/**/
void doimau(int xp)
{
    int i,j;
    i = 0;
    
    while(i != xp)
    {
        i = truoc[last];
        j = trai[i];
        trai[i] = last;
        phai[last] = i;
        last = j;
    }
}
/**/
void solve()
{
    int i,j;
    
    for(i=1;i<=ntrai;i++)
    {
        last = 0;
        noi(i);
        if(last != 0)
            doimau(i);
    }
    
    for(i=1;i<=nphai && i <= ntrai ;i++)
    {
        for(j=1;j<=m[phai[i]];j++)
            if(ten[phai[i]][j].s[0] == i + 64)
            {
                cout << ten[phai[i]][j].s << endl;
                break;
            }
    }
        
}
/**/
void xuly(char ch[])
{
    int i;
    if(ch[0] > 90)
        ch[0] -= 32;
    i = 1;
    while(ch[i])
    {
        if(ch[i] < 90)
            ch[i] += 32;
        i++;
    }
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    int tmp;
    
    id = 1;
    scanf("%d",&ntest);
    nphai = 26;
    while(ntest--)
    {
        scanf("%d",&ntrai);
        khoitao();
        for(i=1;i<=ntrai;i++)
        {
            scanf("%d",&m[i]);
            for(j=1;j<=m[i];j++)
            {
                scanf("%s",ten[i][j].s);
                xuly(ten[i][j].s);
                tmp = ten[i][j].s[0];
                a[i][tmp-64] = 1;
            }
            trai[i] = 0;
        }
        printf("Case #%d:\n",id++);
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
