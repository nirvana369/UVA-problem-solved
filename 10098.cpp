/*
                                                Hoang Linh
                                        
                                    Problem: GENERATING FAST - 10098 (10098.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10098.inp"
#define fo "10098.out"
/**/
using namespace std;
/**/
int d[20];
char s[20],kq[20];
int l;
/**/
void sapxep()
{
    int i,j;
    char temp;
    
    for(i=0;i<l-1;i++)
    {
        for(j=i+1;j<l;j++)
            if(s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        d[i] = 0;
    }
    d[l-1] = 0;
}
/**/
void dequy(int i)
{
    int j;
    int t[200];
    
    if(i == l)
    {
        for(j=0;j<l;j++)
            printf("%c",kq[j]);
        printf("\n");
        return;
    }
    for(j=97;j<123;j++)
        t[j] = 0;
    for(j=0;j<l;j++)
        if(d[j] == 0 && t[s[j]] == 0)
        {
            t[s[j]] = 1;
            kq[i] = s[j];
            d[j] = 1;
            dequy(i+1);
            d[j] = 0;
        }
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
        l = strlen(s);
        sapxep();
        dequy(0);
        printf("\n");
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
