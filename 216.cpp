/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "216.inp"
#define fo "216.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[10];
int d[10],luu[10],kq[10];
double line[10][10];
double lenght;
int n;
/**/
double kc(int i,int j)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
/**/
void khoitao()
{
    int i,j;
    double temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(i != j)
            {
                temp = kc(i,j) + 16;
                line[i][j] = temp;
                line[j][i] = temp;
            }
        d[i] = 0;
    }
    lenght = 100000000;
}
/**/
void dequy(int id,double dodai)
{
    int i;
    if(id == n)
    {
        if(dodai < lenght)
        {
            for(i=0;i<n;i++)
                kq[i] = luu[i];
            lenght = dodai;
        }
        return;
    }
    for(i=0;i<n;i++)
        if(d[i] == 0)
        {
            d[i] = 1;
            luu[id] = i;
            dequy(id+1,dodai+line[luu[id-1]][i]);
            
            d[i] = 0;
        }
}
/**/
void output(int id)
{
    int i;
    printf("**********************************************************\n");
    printf("Network #%d\n",id);
    for(i=0;i<n-1;i++)
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2lf feet.\n",p[kq[i]].x,p[kq[i]].y,p[kq[i+1]].x,p[kq[i+1]].y,line[kq[i]][kq[i+1]]);
    printf("Number of feet of cable required is %0.2f.\n",lenght);
}
void input()
{
    int i;
    int id;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        khoitao();
        for(i=0;i<n;i++)
        {
            luu[0] = i;
            d[i] = 1;
            dequy(1,0);
            d[i] = 0;
        }
        output(id);
        id++;
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
