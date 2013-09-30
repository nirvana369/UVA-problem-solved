/*
                                                    Hoang Linh
                                                    
                                            Problem: HAY POINTS - 10295 (10295.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10295.inp"
#define fo "10295.out"
/**/
using namespace std;
/**/
struct dictionary{
                    char ten[1000];
                    long gt;
                    };
dictionary dic[1100];
int n,m;
/**/
long tim(char s[])
{
    int i;
    for(i=0;i<n;i++)
        if(strcmp(s,dic[i].ten) == 0)
            return dic[i].gt;
    return 0;
}
/**/
void input()
{
    int i,id;
    char temp[10000];
    long long value;
    
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s %ld",&dic[i].ten,&dic[i].gt);
    
    id = 0;
    value = 0;
    while(id != m)
    {
        scanf("%s",&temp);
        if(temp[0] == '.')
        {
            printf("%lld\n",value);
            value = 0;
            id++;
        }
        else
            value += tim(temp);
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
