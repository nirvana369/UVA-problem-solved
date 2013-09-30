/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10978.inp"
#define fo "10978.out"
/**/
using namespace std;
/**/
char a[55][10];
int d[55],l[55];
int ncard;
/**/
void solve()
{
    int i,id,dem;
    
    i = 1;
    dem = 0;
    id = 1;
    while(id <= ncard)
    {
        if(d[i] == 0)
        {
            dem++;
            if(dem == l[id])
            {
                dem = 0;
                d[i] = id;    
                id++;
            }
        }
        i++;
        if(i > ncard)
            i = 1;
    }
    for(i=1;i<=ncard;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%s",a[d[i]]);
    }
    printf("\n");
}
/**/
void input()
{
    char temp[1000],s2[100];
    int i;
    while(true)
    {
        scanf("%d",&ncard);
        if(!ncard)
            break;
        gets(temp);
        for(i=1;i<=ncard;i++)
        {
            gets(temp);
            sscanf(temp,"%s %s",&a[i],&s2);
            l[i] = strlen(s2);
            d[i] = 0;
        }
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
