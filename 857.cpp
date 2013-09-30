/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "857.inp"
#define fo "857.out"
/**/
using namespace std;
/**/
struct music{
                int sw,name,ms,tick,beat;
            };
music m[30000];
bool d[30000];
int n;
/**/
bool chk(int id1,int id2)
{
    if(m[id1].name != m[id2].name)
        return false;
    if(m[id1].beat != m[id2].beat)
        return false;
    if(m[id1].tick != m[id2].tick)
        return false;
    if(m[id1].ms != m[id2].ms)
        return false;
    return true;
}
/**/
void solve()
{
    int i,j;
    int dem;
    
    dem = n;
    for(i=0;i<n;i++)
        if(d[i])
            for(j=i+1;j<n;j++)
                if(d[j])
                {
                    if(m[i].sw && !m[j].sw && chk(i,j))
                    {
                        d[i] = false;
                        d[j] = false;
                        dem -= 2;
                        break;
                    }
                }
    printf("%d\n",dem);
    for(i=0;i<n;i++)
        if(d[i])
            printf("%d %d %d %d %d\n",m[i].sw,m[i].name,m[i].ms,m[i].beat,m[i].tick);
}
/**/
void input()
{
    int i;
    while(scanf("%d",&n))
    {
        if(n < 0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d %d",&m[i].sw,&m[i].name,&m[i].ms,&m[i].beat,&m[i].tick);
            m[i].tick = ((m[i].tick + 30) / 60) * 60;
			if(m[i].tick == 480) 
            {
				m[i].tick = 0;
				m[i].beat++;
				if(m[i].beat == 5) 
                {
					m[i].beat = 1;
					m[i].ms++;
				}
			}
			d[i] = true;
        }
        solve();
    }
    printf("-1\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
