/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
#include <map>

#define fi "613.inp"
#define fo "613.out"
/**/
using namespace std;
/**/
int d[11];
map<string, int > mmap;
/**/
void resetd()
{
    int i;
    for(i=0;i<10;i++)
        d[i] = 0;
}
/**/
void solve(char s[])
{
    int i,j,k;
    int kc,id;
    string self;
    char tmp[100];
    
    mmap.clear();
    resetd();

    i = 0;
    while(s[i])
    {
        d[s[i]-48]++;
        i++;
    }
    
    k = 1;
    kc = 0;
    while(k < 16)
    {
        self = "";
        for(i=0;i<10;i++)
            if(d[i])
            {
                sprintf(tmp,"%d",d[i]);
                self += tmp;
                self += (i + 48);
            }
        
        id = mmap[self];
        if(id)
        {
            kc = k - id;
            break;
        }
        
        mmap[self] = k;
        resetd();        
        i = 0;
        while(self[i])
        {
            d[self[i]-48]++;
            i++;
        }
        k++;        
    }
    
    if(kc)
    {
        if(kc == 1)
            if(k == 2)
                printf("%s is self-inventorying\n",s);
            else
                printf("%s is self-inventorying after %d steps\n",s,id);
        else
            printf("%s enters an inventory loop of length %d\n",s,kc);
    }
    else
        printf("%s can not be classified after 15 iterations\n",s);
}
/**/
void input()
{
    char s[100];
    
    while(1)
    {
        gets(s);
        if(s[0] == '-')
            break;
        solve(s);
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
