/*
                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10474.inp"
#define fo "10474.out"
/**/
using namespace std;
/**/
int a[11000];
int n;
/**/
void sapxep()
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void input()
{
    int i,j;
    int id;
    int temp,q;
    bool find;
    id = 1;
    while(true)
    {
        scanf("%d %d",&n,&q);
        if(!n && !q)
            break;
        printf("CASE# %d:\n",id);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sapxep();
        for(i=0;i<q;i++)
        {
            scanf("%d",&temp);
            find  = false;
            for(j=1;j<=n;j++)
            {
                if(temp == a[j])
                {
                    find = true;
                    break;
                }
                if(a[j] > temp)
                    break;
            }
            if(find)
                printf("%d found at %d\n",temp,j);
            else
                printf("%d not found\n",temp);
        }
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
