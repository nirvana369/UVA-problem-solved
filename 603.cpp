/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "603.inp"
#define fo "603.out"
/**/
using namespace std;
/**/
int wait[100],vt[100],car[25];
bool d[25];
int cwait,cvt;
/**/
void khoitao()
{
    int i;
    for(i=0;i<cwait;i++)
    {
        car[i] = wait[i];
        d[i] = true;
    }
}
/**/
void movecar(int val)
{
    int i;
    for(i=0;i<cwait;i++)
    {
        if(d[i])
        {
            car[i] = (car[i] + val) % 20;
            if(!car[i])
                car[i] += 20;
        }
    }
}
/**/
int tim(int val)
{
    int i;
    int mabs,tmp;
    int vt;
    vt = 0;
    mabs = 1000;
    for(i=0;i<cwait;i++)
    {
        if(d[i])
        {
            if (car[i] > val)
                tmp = (val + 20) - car[i];
            else
                tmp = val - car[i];
            if(tmp < mabs)
            {
                mabs = tmp;
                vt = i;
            }
        }
    }   
    
    car[vt] = val;
    d[vt] = false;
    
    return mabs;
}
/**/
void solve()
{
    int i;
    int tmp;    
    
    khoitao();
    
    for(i=0;i<cvt;i++)
    {
        tmp = tim(vt[i]);
        movecar(tmp);
    }
    
    // output
    for(i=0;i<cwait;i++)
        if(!d[i])
            printf("Original position %d parked in %d\n",wait[i],car[i]);
        else
            printf("Original position %d did not park\n", wait[i]);   
}
/**/
void input()
{
    char s[100];
    int ntest;
    scanf("%d",&ntest);
    
    while(ntest--)
    {
        cwait = cvt = 0;
        while(true)
        {
            scanf("%d",&wait[cwait]);
            if(wait[cwait] == 99)
                break;
            cwait++;
        }
        gets(s);
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            sscanf(s,"%d",&vt[cvt++]);
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
