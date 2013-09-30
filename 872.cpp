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

#define fi "872.inp"
#define fo "872.out"
/**/
using namespace std;
/**/
char kq[100];
int a[100],kn[100][100],d[100];
int da;
bool tontai;
/**/
void getvar(char s[])
{
    int i,j;
    int l;
    char temp;
    l = strlen(s);
    s[l] = ' ';
    da = 0;
    for(i=0;i<=l;i++)
        if(s[i] != ' ')
            a[da++] = s[i];
    
    for(i=0;i<da-1;i++)
        for(j=i+1;j<da;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void xuly(char s[])
{
    int i;
    int l,dem;
    char temp,kt;
    l = strlen(s);
    s[l] = ' ';
    
    dem = 0;
    
    for(i=0;i<=l;i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(dem == 0)
            {
                kt = s[i];
                dem++;
            }
            else
            {
                if(temp == '<')
                    kn[kt][s[i]] = 1;
                else
                    kn[s[i]][kt] = 1;
                dem = 0;
            }
        }
        else if(s[i] != ' ')
            temp = s[i];
}
/**/
void khoitao()
{
    int i,j;
    for(i='A';i<='Z';i++)
    {
        for(j='A';j<='Z';j++)
            kn[i][j] = 0;
        d[i] = 0;
    }
    tontai = false;
}
/**/
bool kiemtra(int id,char kt)
{
    int i;
    for(i=id;i>=0;i--)
        if(kn[kt][kq[i]] == 1)
            return false;
    return true;
}
/**/
void dq(int id)
{
    int i;
    if(id == da)
    {
        for(i=0;i<da;i++)
        {
            if(i)
                printf(" ");
            printf("%c",kq[i]);
        }
        printf("\n");
        tontai = true;
        return;
    }
    for(i=0;i<da;i++)
        if(d[a[i]] == 0 && kiemtra(id-1,a[i]))
        {
            kq[id] = a[i];
            d[a[i]] = 1;
            dq(id+1);
            d[a[i]] = 0;
        }
}
/**/
void solve()
{
    int i;
    
    for(i=0;i<da;i++)
    {
        kq[0] = a[i];
        d[a[i]] = 1;
        dq(1);
        d[a[i]] = 0;
    }
    if(!tontai)
        printf("NO\n");
}
/**/
void input()
{
    char temp[10000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    while(ntest--)
    {
        khoitao();
        gets(temp);
        getvar(temp);
        gets(temp);
        xuly(temp);
        solve();
        gets(temp);
        if(ntest != 0)
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
