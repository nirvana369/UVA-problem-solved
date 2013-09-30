/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "455.inp"
#define fo "455.out"
/**/
using namespace std;
/**/
char s[100];
/**/
bool kiemtra(int s1,int s2)
{
    int i;
    for(i=0;i<s1;i++,s2++)
    {
        if(s[i] != s[s2])
            return false;
    }
    return true;
}
/**/
void solve()
{
    int i,j;
    int l,dem;
    bool countf;
    l = strlen(s);
    dem = 0;
    for(i=1;i<=l/2;i++)
        if(l % i == 0)
        {
            countf = true;
            for(j=i;j<l;j+=i)
            {
                if(!kiemtra(i,j))
                {
                    countf = false;
                    break;
                }
            }
            if(countf)
            {
                dem = i;
                break;
            }
        }
    if(dem == 0)
        dem = l;
    printf("%d\n",dem);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    gets(s);
    while(ntest--)
    {
        gets(s);
        solve();
        if(ntest != 0)
            printf("\n");
        gets(s);
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
