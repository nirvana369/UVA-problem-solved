/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "11221.inp"
#define fo "11221.out"
/**/
using namespace std;
/**/
int xuly(char s[])
{
    int i;
    int l,l1,temp,dau,cuoi;
    char s1[11000];
    
    l = strlen(s);
    l1 = 0;
    for(i=0;i<l;i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            s1[l1++] = s[i];
    temp = (int)sqrt(l1);
    if(temp * temp != l1)
        return -1;
    else
    {
        dau = 0;
        cuoi = l1 - 1;
        while(dau < cuoi)
        {
            if(s1[dau] != s1[cuoi])
                return -1;
            dau++;
            cuoi--;
        }
    }
    return temp;
}
/**/
void input()
{
    int ntest;
    char temp[11000];
    int id,kq;
    
    scanf("%d",&ntest);
    gets(temp);
    id = 1;
    while(ntest--)
    {
        gets(temp);
        kq = xuly(temp);
        printf("Case #%d:\n",id++);
        if(kq != -1)
            printf("%d\n",kq);
        else   
            printf("No magic :(\n");
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
