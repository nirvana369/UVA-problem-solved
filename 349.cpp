/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "349.inp"
#define fo "349.out"
/**/
using namespace std;
/**/
int b[1100][1100],vote[1100],can[1100];
bool d[1100],bad[1100];
int n,m,cd,cbad;
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<m;i++)
        bad[i] = false;
        
    for(i=1;i<=n;i++)
        d[i] = true;
        
    cbad = cd = 0;
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
    sumvote = (m - cbad) / 2 + 1;
    
    while(end != 1)
    {
        rsvote();
        
        for(i=0;i<m;i++)
            if(!bad[i])
                for(j=0;j<n;j++)
                {
                    p = b[i][j];
                    if(d[p])
                    {
                        vote[p]++;
                        break;            
                    }
                }
        
        
        for(i=1;i<=n;i++)
            if(vote[i] >= sumvote)
            {
                can[cd++] = i;
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
                break;
            }
    }
    
    for(i=1;i<=n;i++)
        if(d[i])
            can[cd++] = i;
}
/**/
void output(int id)
{
    int i;
    printf("Election #%d\n",id);
    if(cbad)
        printf("   %d bad ballot(s)\n",cbad);
    if(cd == 1)
        printf("   Candidate %d is elected.\n",can[0]);
    else
    {
        printf("   The following candidates are tied:");
        for(i=0;i<cd;i++)
            printf(" %d",can[i]);
        printf("\n");
    }
}
/**/
void input()
{
    int i,j,k;
    char s[1000];
    int ntest,id;
    
    id = 1;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
            
        khoitao();

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&b[i][j]);
                
                if(!bad[i])
                {
                    if(b[i][j] > n || b[i][j] < 1) //  fucking test number out ranger 1 to n !!! 
                    {
                        bad[i] = true;    
                        cbad++;
                    }
                    
                    for(k=j-1;k>=0;k--)
                        if(b[i][j] == b[i][k])
                        {
                            bad[i] = true;
                            cbad++;
                        }
                }
            }
        }

        solve();

        output(id++);
        
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
