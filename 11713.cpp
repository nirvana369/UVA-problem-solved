/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11713.inp"
#define fo "11713.out"
/**/
using namespace std;
/**/
int d[200];
/**/
void khoitao()
{
    int i;
    for(i='a';i<='z';i++)
        if(i == 'i' || i == 'o' || i == 'e' || i == 'a' || i == 'u')
            d[i] = 1;
        else
            d[i] = i;
}
/**/
void input()
{
    char a[20],b[20];
    int la,lb;
    int i;
    khoitao();
    int ntest;
    scanf("%d",&ntest);
    gets(a);
    while(ntest--)
    {
        gets(a);
        gets(b);
        la = strlen(a);
        lb = strlen(b);
        if(la != lb)
            printf("No\n");
        else
        {
            for(i=0;i<la;i++)
                if(d[a[i]] != d[b[i]])
                    break;
            if(i == la)
                printf("Yes\n");
            else
                printf("No\n");
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
