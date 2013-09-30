/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "893.inp"
#define fo "893.out"
/**/
using namespace std;
/**/
long add,m,d,y;
int fm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
/**/
bool chk(long year)
{
    if(year % 400 == 0)
        return true;
    if(year % 100 == 0)
        return false;
    if(year % 4 == 0)
        return true;
    return false;
}
/**/
void solve()
{
    int i;
    add += d;
    if(chk(y) && m == 12 && d == 31)
        add++;
    i = m;    
    while(true)
    {
        if(chk(y))
            fm[2] = 29;
        else
            fm[2] = 28;
            
        while(i <= 12 && add > fm[i])
        {
            if(add > fm[i])
                add -=fm[i];
            else
                break;
            i++;
        }
        if(i <= 12 && add <= fm[i])
        {
            d = add;
            m = i;
            break;
        }
        i = 1;
        y++;
    }

    printf("%ld %ld %ld\n",d,m,y);
}
/**/
void input()
{
    while(scanf("%ld %ld %ld %ld",&add,&d,&m,&y))
    {
        if(!d && !m && !d && !y)
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
