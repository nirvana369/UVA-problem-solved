/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11541.inp"
#define fo "11541.out"
/**/
using namespace std;
/**/
char s[10000];
/**/
void solve()
{
    int i,j;
    char temp[10000],num[10000];
    int l,dn,dc;
    int gt;
    
    l = strlen(s);
    s[l] = 'A';
    dc = 0;
    dn = 0;
    for(i=0;i<l;i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            temp[dc++] = s[i];
        else
        {
            num[dn++] = s[i];
            if(s[i+1] >= 'A' && s[i+1] <= 'Z')
            {
                temp[dc] = 0;
                num[dn] = 0;
                sscanf(num,"%d",&gt);
                for(j=0;j<gt;j++)
                    printf("%s",temp);
                dc = dn = 0;
            }
        }
    printf("\n");
}
/**/
void input()
{
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    gets(s);
    while(ntest--)
    {
        gets(s);
        printf("Case %d: ",id);
        solve();
        id++;
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
