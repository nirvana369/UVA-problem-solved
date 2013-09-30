/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "380.inp"
#define fo "380.out"
/**/
using namespace std;
/**/
struct cfw{
            int target,t,dur,s;
            };
            
cfw cal[10005];
vector<int > call;
int ncal,ex,tg;
/**/
void solve()
{
    int i;
    int pos;
    
    call.clear();
    call.push_back(ex);
    
    while(1)
    {
        pos = -1;
        
        for(i=0;i<ncal;i++)
            if(cal[i].s == ex && tg >= cal[i].target && tg <= cal[i].target + cal[i].t)
            {
                pos = i;
                break;
            }
        
        if(pos == -1)
        {
            printf("%04d\n",ex);
            return;
        }
        
        ex = cal[pos].dur;

        for(i=0;i<call.size();i++)
            if(call[i] == ex)
            {
                printf("9999\n");
                return;
            }
            
        call.push_back(ex);
    }
}
/**/
void input()
{
    int ntest,id;
    
    printf("CALL FORWARDING OUTPUT\n");
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        ncal = 0;
        while(scanf("%d",&cal[ncal].s) && cal[ncal].s)
        {
            scanf("%d %d %d",&cal[ncal].target,&cal[ncal].t,&cal[ncal].dur);
            ncal++;
        }
        
        printf("SYSTEM %d\n",id++);
        
        while(scanf("%d",&tg) && tg != 9000)
        {
            scanf("%d",&ex);
            
            printf("AT %04d CALL TO %04d RINGS ",tg,ex);
            solve();
        }
    }
    printf("END OF OUTPUT\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
