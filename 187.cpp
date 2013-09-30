/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "187.inp"
#define fo "187.out"
/**/
using namespace std;
/**/
vector<pair<int,long > > a[1100];
long b[1100];
char name[1100][1000];
/**/
int getid(int xp,int kt,char s[])
{
    int val;
    val = 0;
    while(xp < kt)
    {
        val *= 10;
        val += (s[xp] - 48);
        xp++;
    }
    return val;
}
/**/
void input()
{
    int i,j;
    int id,id1;
    char s[1100],tmp[1000];
    long val,tong;
    
    while(true)
    {
        gets(s);
        id = getid(0,3,s);
        if(!id)
            break;
            
        j = 0;
        i = 3;
        while(s[i])
            tmp[j++] = s[i++];
        tmp[j] = 0;
        strcpy(name[id],tmp);
    }
    
    for(i=0;i<1000;i++)
        a[i].clear();
        
    while(true)
    {
        scanf("%s %ld",&s,&val);
        id = getid(0,3,s);
        id1 = getid(3,6,s);
        if(!id && !id1)
            break;
        a[id].push_back(make_pair(id1,val));
    }
    
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
            b[j] = 0;
        tong = 0;
        for(j=0;j<a[i].size();j++)
        {
            b[a[i][j].first] += a[i][j].second;
            tong += a[i][j].second;
        }
        if(tong)
        {
            printf("*** Transaction %03d is out of balance ***\n",i);
            for(j=0;j<1000;j++) 
                if(b[j])
                    printf("%03d %-30s %10.2lf\n", j, name[j], b[j]/100.0);
            printf("999 Out of Balance                 %10.2lf\n\n", -tong/100.0);
        }
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
