/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "540.inp"
#define fo "540.out"
/**/
using namespace std;
/**/
queue<long > qgr,q[1002];
int team[1000010];
bool d[1002];
int nteam;
/**/
void en(long val)
{
    int group;
    
    group = team[val];
    q[group].push(val);
    
    if(d[group])
    {
        d[group] = false; //
        qgr.push(group);
    }
}
/**/
void de()
{
    int group;
    
    group = qgr.front();
    
    cout << q[group].front() << endl;
    q[group].pop();
    
    if(q[group].empty())
    {
        qgr.pop();
        d[group] = true;
    }
}
/**/
void input()
{
    int i,j;
    int m;
    char s[100];
    long val;
    int id;
    id = 1;
    while(scanf("%d",&nteam) && nteam)
    {
        printf("Scenario #%d\n",id++);
        while(!qgr.empty())
            qgr.pop();
        for(i=1;i<=nteam;i++)
        {
            while(!q[i].empty())
                q[i].pop();
            scanf("%d",&m);
            d[i] = true;
            for(j=0;j<m;j++)
            {
                scanf("%ld",&val);
                team[val] = i;
            }
        }
        while(true)
        {
            scanf("%s",&s);
            if(s[0] == 'S')
                break;
            else if(s[0] == 'E')
            {
                scanf("%ld",&val);
                en(val);
            }
            else if(s[0] == 'D')
                de();
        }
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
