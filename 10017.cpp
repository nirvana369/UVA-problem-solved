/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10017.inp"
#define fo "10017.out"
/**/
using namespace std;
/**/
vector<int > p[3];
int n,m,steps;
/**/
void khoitao()
{
    int i;
    
    steps = 0;
    for(i=0;i<3;i++)
        p[i].clear();
        
    for(i=n;i>=1;i--)
        p[0].push_back(i);
}
/**/
void output()
{
    int i,j;
    
    for(i=0;i<3;i++)
    {
        printf("%c=>",i+65);
        if(p[i].size())
        {
            printf("  ");
            for(j=0;j<p[i].size();j++)
                cout << " " << p[i][j];
        }
        printf("\n");
    }
    printf("\n");
    steps++;
}
/**/
void towerhn(int x,int y,int z,int id)
{
    if(!id) // 
        return;
        
    towerhn(x,z,y,id-1);

    p[z].push_back(p[x].back()); // move disk
    p[x].pop_back();
    
    if(steps <= m)
        output();
    else
        return;
    
    towerhn(y,x,z,id-1);
    
}
/**/
void input()
{
    int id;
    
    id = 1;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        khoitao();
        printf("Problem #%d\n\n",id++);
        output();
        towerhn(0,1,2,n);
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
