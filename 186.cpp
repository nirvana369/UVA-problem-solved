/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iomanip>
#include <iostream>

#define fi "186.inp"
#define fo "186.out"
/**/
using namespace std;
/**/
struct routing{
                int x,y;
                int gt;
                };
routing noi[30000];
map <string, int> mmap;
map <int, string> nmap;
char route[30000][100];
int a[110][110],name[110][110],d[110],truoc[110];
bool coduong[110][110];
long nhan[110];
int nr,ncity;
/**/
void xuly(char s[])
{
    int l,dem;
    int i;
    int x,y;
    char s1[100],s2[100];
    int val;
    l = strlen(s);

    i = 0;
    dem = 0;
    while(s[i] != ',')
    {
        s1[dem++] = s[i];
        i++;
    }
    i++;
    s1[dem] = 0;
    
    dem = 0;
    while(s[i] != ',')
    {
        s2[dem++] = s[i];
        i++;
    }
    s2[dem] = 0;
    
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
    
    dem = 0;
    i++;
    while(s[i] != ',')
    {
        s1[dem++] = s[i];
        i++;
    }
    i++;
    s1[dem] = 0;
    strcpy(route[nr],s1);
    dem = 0;
    while(i<l)
    {
        s2[dem++] = s[i];
        i++;
    }
    s2[dem] = 0;
    sscanf(s2,"%ld",&val);
    noi[nr].x = x;
    noi[nr].y = y;
    noi[nr].gt = val;
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<ncity;i++)
    {
        for(j=1;j<ncity;j++)
        {
            a[i][j] = -2000000000;
            coduong[i][j] = false;
        }
        d[i] = 0;
        nhan[i] = 2000000000;
    }
    for(i=0;i<nr;i++)
    {
        if(a[noi[i].x][noi[i].y] == -2000000000)
        {
            a[noi[i].x][noi[i].y] = noi[i].gt;
            a[noi[i].y][noi[i].x] = noi[i].gt;
            coduong[noi[i].x][noi[i].y] = true;
            coduong[noi[i].y][noi[i].x] = true;
            name[noi[i].x][noi[i].y] = i;
            name[noi[i].y][noi[i].x] = i;
        }
        else if(noi[i].gt < a[noi[i].x][noi[i].y])
        {
            a[noi[i].x][noi[i].y] = noi[i].gt;
            a[noi[i].y][noi[i].x] = noi[i].gt;
            name[noi[i].x][noi[i].y] = i;
            name[noi[i].y][noi[i].x] = i;
        }
    }
}
/**/
int timcity()
{
    int i;
    int vt;
    long val;
    val = 2000000000;
    vt = -1;
    for(i=1;i<ncity;i++)
        if(d[i] == 0 && nhan[i] < val)
        {
            val = nhan[i];
            vt = i;
        }
    return vt;
}
/**/
void gancity(int xp)
{
    int i;
    for(i=1;i<ncity;i++)
        if(coduong[xp][i] && nhan[xp] + a[xp][i] < nhan[i])
        {
            nhan[i] = nhan[xp] + a[xp][i];
            truoc[i] = xp;
        }
}
/**/
void timduong(int dau,int cuoi)
{
    char s1[100],s2[100];
    int io,i;
    int dem;
    int duong[1000];
    nhan[dau] = 0;
    do
    {
        io = timcity();
        if(io == -1 || io == cuoi)
            break;
        d[io] = 1;
        gancity(io);
    }while(true);
    
    io = cuoi;
    dem = 0;
    while(io != dau)
    {
        duong[dem++] = io;
        io = truoc[io];
    }
    duong[dem] = io;
    printf("From                 To                   Route      Miles\n");
    printf("-------------------- -------------------- ---------- -----\n");
    for(i=dem;i>0;i--)
    {
        std::cout.width(21);
        std::cout << std::left << nmap[duong[i]];
        std::cout.width(21);
        std::cout << std::left << nmap[duong[i-1]];
        std::cout.width(11);
        std::cout << std::left << route[name[duong[i]][duong[i-1]]];
        std::cout.width(5);
        std::cout << std::right << a[duong[i]][duong[i-1]] << endl;
    }
    printf("                                                     -----\n");
    printf("                                          Total%11ld\n",nhan[cuoi]);
}
/**/
void solve(char s[])
{
    int l,dem;
    int x,y;
    int i;
    char s1[100];
    i = 0;
    l = strlen(s);
    dem = 0;
    
    while(s[i] != ',')
        s1[dem++] = s[i++];
    
    i++;
    s1[dem] = 0;
    x = mmap[s1];
    
    dem = 0;
    
    while(i < l)
        s1[dem++] = s[i++];
    
    s1[dem] = 0;
    y = mmap[s1];
    
    timduong(x,y);
}
/**/
void resetnhan()
{
    int i;
    for(i=1;i<ncity;i++)
    {
        d[i] = 0;
        nhan[i] = 2000000000;
    }
}
/**/
void input()
{
    char temp[10000];
    ncity = 1;
    mmap.clear();
    nmap.clear();
    nr = 0;
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        xuly(temp);
        nr++;
    }
    khoitao();
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        printf("\n\n");
        solve(temp);
        resetnhan();
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
