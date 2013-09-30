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

#define fi "11830.inp"
#define fo "11830.out"
/**/
using namespace std;
/**/
int n;
char s[110];
/**/
void solve()
{
    int i;
    int kq[110];
    int dem,temp;
    i = 0;
    dem = 0;
    while(s[i] != 0)
    {
        temp = s[i] - 48;
        if(temp != n)
        {
            if(!dem)
            {
                if(temp != 0)
                    kq[dem++] = temp;        
            }
            else
                kq[dem++] = temp;
        }
        i++;
    }
    
    if(dem == 0)
    {
        kq[0] = 0;
        dem = 1;
    }
    for(i=0;i<dem;i++)
        printf("%d",kq[i]);
    printf("\n");
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %s",&n,&s);
        if(!n && s[0] == '0')
            break;
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
