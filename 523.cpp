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

#define fi "523.inp"
#define fo "523.out"
#define maxgt 9000000
/**/
using namespace std;
/**/
int a[10000][10000],d[10000],b[10000],truoc[10000];
long nhan[10000];
int n,xp,kt;
/**/
void xuly(char s[])
{
    int i,id;
    int l,dem;
    char tmp[1000];
    
    l = strlen(s);
    s[l] = ' ';
    n = 0;
    dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] != ' ')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            sscanf(tmp,"%d",&a[1][++n]);
            dem = 0;
        }
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
    {
        nhan[i] = maxgt;
        d[i] = 0;
    }
    nhan[xp] = 0;
}
/**/
int timnhan()
{
    int vt,i;
    long gt;
    
    vt = -1;
    gt = maxgt;
    
    for(i=1;i<=n;i++)
        if(!d[i] && nhan[i] < gt)
        {
            gt = nhan[i];
            vt = i;
        }
        
    return vt;
}
/**/
void gannhan(int s)
{
    int i;
    for(i=1;i<=n;i++)
        if(a[s][i] != -1 && nhan[s] + a[s][i] + b[i] < nhan[i])
        {
            nhan[i] = nhan[s] + a[s][i] + b[i];
            truoc[i] = s;
        }
}
/**/
void solve()
{
    int i,dem;
    int io;
    int kq[10000];
    
    khoitao();
    
    do
    {
        io = timnhan();

        if(io == kt || io == -1)    
            break;

        d[io] = 1;
        
        gannhan(io);
        
    }while(true);
    
    printf("From %d to %d :\n",xp,kt);
    printf("Path: ");
    
    i = kt;
    dem = 0;
    while(i != xp)
    {
        kq[dem++] = i;
        i = truoc[i];
    }
    kq[dem] = xp;
    for(i=dem;i>=0;i--)
    {
        printf("%d",kq[i]);
        if(i)
            printf("-->");
    }
    printf("\nTotal cost : ");
    if(io != -1)
    {
        if(xp != kt)
            printf("%ld",nhan[kt]-b[kt]);
        else
            printf("0");
    }
    else
        printf("0");
    printf("\n");
}
/**/
void input()
{
    char s[10000];
    int i,j;
    int ntest,id,id1;
    scanf("%d",&ntest);
    gets(s);
    gets(s);
    id = 0;
    while(ntest--)
    {
        gets(s);
        xuly(s);
        for(i=2;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        gets(s);
        
        if(id)
            printf("\n");
        id1 = 0;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            if(id1)
                printf("\n");
            sscanf(s,"%d %d",&xp,&kt);
            solve();
            id1++;
        }
        id++;
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
