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

#define fi "762.inp"
#define fo "762.out"
/**/
using namespace std;
/**/
struct ketnoi{
                int x,y;
            };
ketnoi noi[30000];
map <string, int> mmap;
map <int, string> nmap;
int d[20000],a[20000][20000],q[20000],truoc[20000];
int ncity,n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<ncity;i++)
    {
        for(j=1;j<ncity;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        a[noi[i].x][noi[i].y] = 1;
        a[noi[i].y][noi[i].x] = 1;
    }
}
/**/
void output(int cuoi)
{
    int i;
    int r[20000];
    int dem;
    dem = 0;
    while(cuoi != 0)
    {
        r[dem++] = q[cuoi];
        cuoi = truoc[cuoi];
    }
    r[dem] = q[0];
    for(i=dem;i>0;i--)
        cout << nmap[r[i]] << " " << nmap[r[i-
        1]] << endl ;
}
/**/
void loang(int s,int e)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    d[s] = 1;
    q[0] = s;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<ncity;i++)
            if(d[i] == 0 && a[q[dau]][i] == 1)
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
                truoc[cuoi] = dau;
                if(i == e)            
                {
                    output(cuoi);
                    return;
                }
            }
    }
    printf("No route\n");
}
/**/
void input()
{
    int i,id;
    char s1[100],s2[100];
    int x,y;
    id = 0;
    while(true)
    {
        n = -1;
        scanf("%d",&n);
        if(n < 0)
            break;
        if(id)
            printf("\n");
        mmap.clear();
        nmap.clear();
        ncity = 1;
        for(i=0;i<n;i++)
        {
            scanf("%s %s",&s1,&s2);
            if(mmap[s1] == 0)
            {
                x = ncity;
                nmap[ncity] = s1;
                mmap[s1] = ncity++;
            }
            else
                x = mmap[s1];
                
            if(mmap[s2] == 0)
            {
                y = ncity;
                nmap[ncity] = s2;
                mmap[s2] = ncity++;
            }
            else
                y = mmap[s2];
            noi[i].x = x;
            noi[i].y = y;
        }
        scanf("%s %s",&s1,&s2);
        x = mmap[s1];
        y = mmap[s2];
        khoitao();
        loang(x,y);
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
