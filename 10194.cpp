/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10194.inp"
#define fo "10194.out"
/**/
using namespace std;
/**/
struct data{
            int p,play,w,l,t,ga,gs;
            };
            
data team[40];
char tname[40][100],dname[40][100];
char name[200];
int nteam;
/**/
int getname(char s[])
{
    int i;
    for(i=1;i<=nteam;i++)
        if(strcmp(s,tname[i]) == 0)
            return i;
}
/**/
void output()
{
    int i;
    printf("%s\n",name);
    for(i=1;i<=nteam;i++)
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,tname[i],team[i].p,team[i].play,team[i].w,team[i].t,team[i].l,team[i].gs-team[i].ga,team[i].gs,team[i].ga);
}
void xuly(char s[])
{
    int n1,n2,id1,id2;
    char temp[100];
    int i;
    int l,dem;
    l = strlen(s);
    
    i = 0;
    
    dem = 0;
    while(s[i] != '#')
        temp[dem++] = s[i++];
    temp[dem] = 0;
    id1 = getname(temp);
    
    dem = 0;
    i++;
    while(s[i] != '@')
        temp[dem++] = s[i++];
    temp[dem] = 0;
    sscanf(temp,"%d",&n1);
    
    i++;
    dem = 0;
    while(s[i] != '#')
        temp[dem++] = s[i++];
    temp[dem] = 0;
    sscanf(temp,"%d",&n2);
    
    i++;
    dem = 0;
    while(i<l)
        temp[dem++] = s[i++];
    temp[dem] = 0;
    id2 = getname(temp);
    
    team[id1].play++;
    team[id2].play++;
    if(n1 > n2)
    {
        team[id1].p += 3;
        team[id1].w++;
        team[id2].l++;
    }
    else if(n2 > n1)
    {
        team[id2].p += 3;
        team[id2].w++;
        team[id1].l++;
    }
    else
    {
        team[id1].p++;
        team[id2].p++;
        team[id1].t++;
        team[id2].t++;
    }
    team[id1].gs+=n1;
    team[id1].ga+=n2;
    team[id2].gs+=n2;
    team[id2].ga+=n1;
}
/**/
void swapteam(int i,int j)
{
    char temp[1000];
    data tg;
    strcpy(temp,tname[i]);
    strcpy(tname[i],tname[j]);
    strcpy(tname[j],temp);
    
    strcpy(temp,dname[i]);
    strcpy(dname[i],dname[j]);
    strcpy(dname[j],temp);

    tg = team[i];
    team[i] = team[j];
    team[j] = tg;
}
/**/
void sapxep()
{
    int i,j;
    for(i=1;i<nteam;i++)
        for(j=i+1;j<=nteam;j++)
            if(team[i].p < team[j].p)
                swapteam(i,j);
            else if(team[i].p == team[j].p)
            {
                if(team[i].w < team[j].w)
                    swapteam(i,j);                    
                else if(team[i].w == team[j].w)
                {
                    if(team[i].gs-team[i].ga < team[j].gs-team[j].ga)
                        swapteam(i,j);
                    else if(team[i].gs-team[i].ga == team[j].gs-team[j].ga)
                    {
                        if(team[i].gs < team[j].gs)
                            swapteam(i,j);
                        else if(team[i].gs == team[j].gs)
                        {
                            if(team[i].play > team[j].play)
                                swapteam(i,j);                                
                            else if(team[i].play == team[j].play)
                            {
                                if(strcmp(dname[i],dname[j]) > 0)
                                    swapteam(i,j);
                            }
                        }
                    }
                }
            }
}
/**/
void doi(int id)
{
    int i;
    int l;
    l = strlen(tname[id]);

    for(i=0;i<l;i++)
        if(tname[id][i] >= 'A' && tname[id][i] <= 'Z')
            dname[id][i] = tname[id][i] + 32;
        else
            dname[id][i] = tname[id][i];
    dname[id][l] = 0;
}
/**/
void input()
{
    int i;
    char s[1000];
    int ntest;
    int nmath;
    scanf("%d",&ntest);
    gets(name);
    while(ntest--)
    {
        gets(name);
        scanf("%d",&nteam);
        gets(tname[1]);
        for(i=1;i<=nteam;i++)
        {
            gets(tname[i]);
            doi(i);
            team[i].p = 0;
            team[i].play = 0;
            team[i].w = 0;
            team[i].t = 0;
            team[i].l = 0;
            team[i].gs = 0;
            team[i].ga = 0;
        }
        scanf("%d",&nmath);
        gets(s);
        for(i=0;i<nmath;i++)
        {
            gets(s);
            xuly(s);
        }
        sapxep();
        output();
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
