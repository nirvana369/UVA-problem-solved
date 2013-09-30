/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10776.inp"
#define fo "10776.out"
/**/
using namespace std;
/**/
char s[40],kq[40];
int len,n;
/**/
void sapxep()
{
    int i,j;
    char temp;
    
    for(i=0;i<len-1;i++)    
        for(j=i+1;j<len;j++)
            if(s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}
/**/
void solve(int xp,int id)
{
    int i;
    int d[200];
    if(id == n)
    {
        kq[id] = 0;
        printf("%s\n",kq);
        return;
    }
    for(i='a';i<='z';i++)
        d[i] = 0;
    for(i=xp;i<len;i++)
        if(!d[s[i]])
        {
            kq[id] = s[i];
            d[s[i]] = 1;
            solve(i+1,id+1);
        }
}
/**/
void input()
{
    while(scanf("%s %d",&s,&n) == 2)
    {
        len = strlen(s);
        sapxep();
        solve(0,0);
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
