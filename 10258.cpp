/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10258.inp"
#define fo "10258.out"
/**/
using namespace std;
/**/
int d[110][20],timec[110],solve[110],cp[110];
int demc;
/**/
bool kiemtra(int p)
{
    int i;
    for(i=0;i<demc;i++)
        if(p == cp[i])
            return false;
    cp[demc] = p;
    demc++;
    return true;
}
/**/
void khoitao(int p)
{
    int i;
    for(i=0;i<10;i++)
        d[p][i] = 0;
    timec[p] = 0;
    solve[p] = 0;
}
/**/
void sapxep()
{
    int i,j;
    int temp;
    for(i=0;i<demc-1;i++)
        for(j=i+1;j<demc;j++)
            if(solve[cp[i]] < solve[cp[j]])
            {
                temp = cp[i];
                cp[i] = cp[j];
                cp[j] = temp;
            }
            else if(solve[cp[i]] == solve[cp[j]])
            {
                if(timec[cp[i]] > timec[cp[j]])
                {
                    temp = cp[i];
                    cp[i] = cp[j];
                    cp[j] = temp;    
                }
                else if(timec[cp[i]] == timec[cp[j]])
                {
                    if(cp[i] > cp[j])
                    {
                        temp = cp[i];
                        cp[i] = cp[j];
                        cp[j] = temp;    
                    }
                }
            }
}
/**/
void input()
{
    char temp[10000];
    int i;
    int p,pb,timep,stt;
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    
    while(ntest--)
    {
        demc = 0;
        while(true)    
        {
            temp[0] = 0;
            gets(temp);
            sscanf(temp,"%d %d %d %c",&p,&pb,&timep,&stt);
            if(kiemtra(p))
                khoitao(p);
                
            if(d[p][pb] != -1)
            {
                if(stt == 'C')
                {
                    timec[p] += timep + d[p][pb] * 20;
                    d[p][pb] = -1;
                    solve[p]++;
                }
                else if(stt == 'I')
                    d[p][pb]++;
            }
            
            if(temp[0] == 0)
                break;
        }
        sapxep();
        for(i=0;i<demc;i++)
            printf("%d %d %d\n",cp[i],solve[cp[i]],timec[cp[i]]);
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
