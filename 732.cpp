/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "732.inp"
#define fo "732.out"
/**/
using namespace std;
/**/
char s1[100],s2[100],s[100],kq[100];
int d,len1,len2;
/**/
void dq(int id,int d1,int d2)
{
    int i;
    if(d2 == len2)
    {
        for(i=0;i<id;i++)
        {
            if(i)
                printf(" ");
            printf("%c",kq[i]);
        }
        printf("\n");
        return;
    }
    
    if(d1 < len1)
    {
        s[d++] = s1[d1];
        kq[id] = 'i';
        dq(id+1,d1+1,d2);
        d--;
    }
    
    if((d-1) >= 0)
    {
        if(s[d-1] == s2[d2])
        {
            d--;
            kq[id] = 'o';
            dq(id+1,d1,d2+1);
            s[d] = s2[d2];
            d++;
        }
    }
}
/**/
void input()
{
    while(gets(s1))
    {
        gets(s2);
        printf("[\n");
        len2 = strlen(s2);
        len1 = strlen(s1);
        if(len1 == len2)
            dq(0,0,0);
        printf("]\n");
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
