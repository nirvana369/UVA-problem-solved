/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <map>

#define fi "11917.inp"
#define fo "11917.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest,id,ns;
    map<string, int > mmap;
    char s[100];
    int d,day,tmp;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&ns);
        mmap.clear();
        while(ns--)
        {
            scanf("%s %d",&s,&d);
            mmap[s] = d;
        }
        scanf("%d",&day);
        printf("Case %d: ",id++);
        scanf("%s",&s);
        tmp = mmap[s];
        if(!tmp)
            printf("Do your own homework!\n");
        else
        {
            if(tmp <= day)
                printf("Yesss\n");
            else if(tmp <= day + 5)
                printf("Late\n");     
            else
                printf("Do your own homework!\n");           
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
