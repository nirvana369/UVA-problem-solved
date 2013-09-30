/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
#include <map>

#define fi "939.inp"
#define fo "939.out"
/**/
using namespace std;
/**/
map<string, int > nmap;
char name[4][30];
vector<int > a[4000];
int gen[4000];
int n,m;
/**/
int chk(char s[])
{
    if(!strcmp(s,"dominant"))
        return 3;
    if(!strcmp(s,"recessive"))
        return 2;
    if(!strcmp(s,"non-existent"))
        return 1;
    return 0;
}
/**/
void fparent(int con,int cha,int me)
{
    int k;
    int x[3];
    
    if(!cha && !me)
        return;
        
    if(!gen[cha])
    {
        x[0] = x[1] = 0;
        for(k=0;k<a[cha].size();k++)
            x[k] = a[cha][k];
        fparent(cha,x[0],x[1]);
    }   
    if(!gen[me])
    {
        x[0] = x[1] = 0;
        for(k=0;k<a[me].size();k++)
            x[k] = a[me][k];
        fparent(me,x[0],x[1]);
    }
    
    if(gen[cha] != 1 && gen[me] != 1 || (gen[cha] == 3 || gen[me] == 3))
    {
        if((gen[cha] == 3 || gen[me] == 3) && gen[cha] != 1 && gen[me] != 1)
            gen[con] = 3;
        else
            gen[con] = 2;
    }
    else
        gen[con] = 1;
}
/**/
void solve()
{
    int i,k;
    int x[3];
    map<string, int >::iterator j;
    
    for(i=1;i<n;i++)
    {
        x[0] = x[1] = 0;
        for(k=0;k<a[i].size();k++)
            x[k] = a[i][k];
        fparent(i,x[0],x[1]);
    }
    
    for(j=nmap.begin();j!=nmap.end();j++)
    {
        cout << j -> first;
        printf(" %s\n",name[gen[j -> second]]);
    }
}
/**/
void input()
{
    char s[100];
    int x,y;
    int tmp;
    
    strcpy(name[3],"dominant");
    strcpy(name[2],"recessive");
    strcpy(name[1],"non-existent");

    while(scanf("%d",&m) == 1)
    {
        nmap.clear();
        n = 1;
        gen[0] = 1;
        
        while(m--)
        {
            scanf("%s",&s);
            
            x = nmap[s];
            
            if(!x)
            {
                nmap[s] = n;
                gen[n] = 0;
                x = n++;
            }
            
            scanf("%s",&s);
            tmp = chk(s);
            if(tmp)
                gen[x] = tmp;
            else
            {
                y = nmap[s];
                if(!y)
                {
                    nmap[s] = n;
                    gen[n] = 0;
                    y = n++;
                }
                a[y].push_back(x);
            }
        }
        solve();
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
