/*
                                                    Hoang Linh
                                                    
                                        Problem: ALL IN ALL - 10340 (10340.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10340.inp"
#define fo "10340.out"
/**/
using namespace std;
/**/
char temp[1000000],s[1000000],t[1000000];
/**/
void solve()
{
    long ls,lt;
    long i,j;
    bool find;
    ls = strlen(s);
    lt = strlen(t);
    i = 0;
    find = false;
    for(j=0;j<lt;j++)
        if(s[i] == t[j])
        {
            i++;
            if(i == ls)
                find = true;
        }
    if(find)
        printf("Yes\n");
    else
        printf("No\n");
}
/**/
void input()
{
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        sscanf(temp,"%s %s",&s,&t);
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
