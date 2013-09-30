/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11356.inp"
#define fo "11356.out"
/**/
using namespace std;
/**/
map<string, int > mmap;
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
void output()
{
    printf("%ld-",y);
    if(m == 1)
        printf("January");
    else if(m == 2)
        printf("February");
    else if(m == 3)
        printf("March");
    else if(m == 4)
        printf("April");
    else if(m == 5)
        printf("May");
    else if(m == 6)
        printf("June");
    else if(m == 7)
        printf("July");
    else if(m == 8)
        printf("August");
    else if(m == 9)
        printf("September");
    else if(m == 10)
        printf("October");
    else if(m == 11)
        printf("November");
    else if(m == 12)
        printf("December");
        
    printf("-%02ld\n",d);
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

    output();
}
/**/
void _init()
{
    mmap.clear();
    mmap["January"] = 1;
    mmap["February"] = 2;
    mmap["March"] = 3;
    mmap["April"] = 4;
    mmap["May"] = 5;
    mmap["June"] = 6;
    mmap["July"] = 7;
    mmap["August"] = 8;
    mmap["September"] = 9;
    mmap["October"] = 10;
    mmap["November"] = 11;
    mmap["December"] = 12;
}
/**/
void xuly(char s[])
{
    int i;
    char tmp[100];
    int dem;
    i = 0;
    dem = 0;
    while(s[i])
    {
        if(s[i] == '-')
            break;
        tmp[dem++] = s[i];
        i++;
    }
    i++;
    tmp[dem] = 0;
    sscanf(tmp,"%ld",&y);
    dem = 0;
    
    while(s[i])
    {
        if(s[i] == '-')
            break;
        tmp[dem++] = s[i];
        i++;
    }
    i++;
    tmp[dem] = 0;
    m = mmap[tmp];
    dem = 0;
    
    while(s[i])
    {
        tmp[dem++] = s[i];
        i++;
    }
    tmp[dem] = 0;
    sscanf(tmp,"%ld",&d);
}
/**/
void input()
{
    char s[1000];
    int ntest,id;
    
    _init();
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%s %ld",&s,&add);
        xuly(s);
        printf("Case %d: ",id++);
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
