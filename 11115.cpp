/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11115.inp"
#define fo "11115.out"
/**/
using namespace std;
/**/
int mul(char s1[],int l1,char s2[],int l2)
{
    int i,j;
    int arr[100];
    
    int len;
    len = l1 + l2;
    for(i=0;i<=len;i++)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] = arr[i+j] + (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9);
            {
                arr[i+j+1] = arr[i+j+1] + arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    
    for(i=len;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
            s1[j] = 0;
            return i+1;
        }
}
/**/
void daochuoi(char s[],int len)
{
    int i;
    char tmp;
    
    i = 0;
    
    while(i < len)
    {
        tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
        i++;
        len--;
    }
}
/**/

/**/
void input()
{
    int i;
    char sn[100],sm[100];
    int ln,lm;
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        if(n == 1)
        {
            printf("%d\n",n);
            continue;
        }
        if(!m)
        {
            printf("1\n");
            continue;
        }
        sprintf(sn,"%d",n);
        ln = strlen(sn);
        daochuoi(sn,ln-1);
        strcpy(sm,sn);
        lm = ln;
        m--;
        while(m--)
            ln = mul(sn,ln,sm,lm);
        for(i=ln-1;i>=0;i--)
            printf("%c",sn[i]);
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
