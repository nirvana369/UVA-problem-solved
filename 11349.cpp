/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11349.inp"
#define fo "11349.out"
/**/
using namespace std;
/**/
long a[110][110];
int n;
/**/
bool solve()
{
    int hh,lh;
    int i,j;
    lh = 0;
    hh = n-1;
    while(lh <= hh)
    {
        for(i=0,j=n-1;i<n;i++,j--)
            if(a[lh][i] != a[hh][j])
                return false;
        lh++;
        hh--;
    }
    return true;
}
/**/
void input()
{
    char s[100];
    int ntest,id;
    int i,j;
    bool right;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%s",&s);
        scanf("%s %d",&s,&n);
        right = true;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%ld",&a[i][j]);
                if(a[i][j] < 0)
                    right = false;
            }
        if(right)
            right = solve();
        if(right)
            printf("Test #%d: Symmetric.\n",id++);
        else
            printf("Test #%d: Non-symmetric.\n",id++);
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
