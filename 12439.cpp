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

#define fi "12439.inp"
#define fo "12439.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
/**/
void khoitao()
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
long xuly(int month,int day,long year,int flg)
{
    if(flg)
    {
        if(month < 2 || month == 2 && day < 29)
            return year-1;
        return year;    
    }
    if(month > 2)
        return year;
    return year-1;
}
/**/
void input()
{
    long leap,y1,y2,y;
    char m[20];
    int d;
    int ntest,id;
    khoitao();
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s %d, %ld",&m,&d,&y);
        y1 = xuly(mmap[m],d,y,0);

        scanf("%s %d, %ld",&m,&d,&y);
        y2 = xuly(mmap[m],d,y,1);

        leap = y2/4 - y1/4;
        leap -= (y2/100 - y1/100);
        leap += (y2/400 - y1/400);
        printf("Case %d: %ld\n",id++,leap);
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
