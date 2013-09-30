/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "451.inp"
#define fo "451.out"
/**/
using namespace std;
/**/
struct card{
                int rank,suit;
            };
card c[6];
char a[26][4],s[200],r[200];
int val[11],pairc[6],xh[15];
/**/
bool straight(card b[])
{
    int i,j;
    int dem;
    int d[26];
    
    for(i=0;i<=20;i++)
        d[i] = 0;
    
    for(i=0;i<5;i++)
        if(b[i].rank < 6)
            d[b[i].rank + 13] = d[b[i].rank] = 1;
        else
            d[b[i].rank] = 1;
    
    dem = 0;
    
    for(i=0;i<=20;i++)
    {
        if(d[i])
            dem++;
        else
            dem = 0;
        if(dem == 5)
            return true;
    }
    return false;
}
/**/
bool cflush(card b[])
{
    int i;
    
    for(i=0;i<4;i++)
        if(b[i].suit != b[i+1].suit)
            return false;

    return true;
}
/**/
void sapxep()
{
    int i,j;
    card tmp;
    
    for(i=1;i<14;i++)
        xh[i] = 0;
    
    for(i=0;i<5;i++)
        pairc[i] = 0;
        
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
            if(c[i].rank > c[j].rank)
            {
                tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
            }
        xh[c[i].rank]++;
    }
    
    for(i=1;i<14;i++)
        pairc[xh[i]]++;
}
/**/
void solve()
{
    bool circle;
    
    sapxep();
    
    circle = false;
    
    if(straight(c))
        circle = true;
        
    if(circle && cflush(c))
        val[9]++;
    else if(pairc[4])
        val[8]++;
    else if(pairc[3] && pairc[2])
        val[7]++;
    else if(cflush(c))
        val[6]++;
    else if(circle)
        val[5]++;
    else if(pairc[3])
        val[4]++;
    else if(pairc[2] == 2)
        val[3]++;
    else if(pairc[2])
        val[2]++;
    else
        val[1]++;
}
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<10;i++)
        val[i] = 0;
}
/**/
void _init()
{
    int i,j;
    
    s['C'] = 0;
    s['D'] = 1;
    s['S'] = 2;
    s['H'] = 3;
    
    r['A'] = 1;
    for(i='2';i<='9';i++)
        r[i] = i - 48;
    r['X'] = 10;
    r['J'] = 11;
    r['Q'] = 12;
    r['K'] = 13;
}
/**/
void output()
{
    int i;
    printf("%d",val[1]);
    for(i=2;i<10;i++)
        printf(", %d",val[i]);
    printf("\n");
}
/**/
void xuly()
{
    int i,j,k;
    
    khoitao();
    
    for(i=0,j=0;i<25;i++)
    {
        c[j].rank = r[a[i][0]];
        c[j].suit = s[a[i][1]];
        j++;
        if(j == 5)
        {
            solve();
            j = 0;
        }
    }
        
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            c[j].rank = r[a[5*j+i][0]];
            c[j].suit = s[a[5*j+i][1]];
        }
        solve();
    }
    output();
}
/**/
void input()
{
    int i,j,k;
    int ntest;
    char line[1000];
    
    _init();
    scanf("%d",&ntest);
    gets(line);
    gets(line);
    while(ntest--)
    {
        while(1)
        {
            line[0] = 0;
            gets(line);
            if(!line[0])
                break;
            i = 0;
            sscanf(line,"%s %s %s %s %s",a[i],a[i+1],a[i+2],a[i+3],a[i+4]);
            i += 5;
            for(j=0;j<4;j++)
            {
                gets(line);
                sscanf(line,"%s %s %s %s %s",a[i],a[i+1],a[i+2],a[i+3],a[i+4]);
                i += 5;
            }
            xuly();
        }
        if(ntest)
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
