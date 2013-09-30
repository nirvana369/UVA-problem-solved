/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10142.inp"
#define fo "10142.out"
/**/
using namespace std;
/**/
char name[25][100];
int b[1100][25],vote[25];
bool d[25];
int n,m;
/**/
void xuly(char s[],int id)
{
    int dem,gt;
    int i,j;
    char tmp[1000];
    
    i = j = dem = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            tmp[dem++]  = s[i];
        else if(dem)
        {
            tmp[dem] = 0;
            dem = 0;
            sscanf(tmp,"%d",&gt);
            b[id][j++] = gt;
        }
        i++;
    }
    
    if(dem)
    {
        tmp[dem] = 0;
        sscanf(tmp,"%d",&gt);
        b[id][j++] = gt;
    }
}
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<=n;i++)
        d[i] = true;
}
/**/
void rsvote()
{
    int i;
    
    for(i=1;i<=n;i++)
        vote[i] = 0;
}
/**/
void solve()
{
    int i,j;
    int end,p;
    int sumvote,minvote,maxvote;
    
    end = n;
    
    while(end != 1)
    {
        rsvote();
        sumvote = 0;
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                p = b[i][j];
                if(d[p])
                {
                    vote[p]++;
                    sumvote++;
                    break;            
                }
            }
        
        sumvote /= 2;
        
        for(i=1;i<=n;i++)
            if(vote[i] > sumvote)
            {
                printf("%s\n",name[i]);
                return;
            }
        maxvote = 0;
        minvote = 32000;
        for(i=1;i<=n;i++)
            if(d[i])
            {
                maxvote = maxvote < vote[i] ? vote[i] : maxvote;
                minvote = minvote > vote[i] ? vote[i] : minvote;
            }
        
        if(minvote == maxvote)
            break;
        
        for(i=1;i<=n;i++)
            if(vote[i] == minvote)
            {
                d[i] = false;
                end--;
            }
    }
    
    for(i=1;i<=n;i++)
        if(d[i])
            printf("%s\n",name[i]);
}
/**/
void input()
{
    int i;
    char s[1000];
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        gets(s);
        khoitao();
        for(i=1;i<=n;i++)
            gets(name[i]);
        m = 0;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            xuly(s,m++);
        }
        solve();
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
