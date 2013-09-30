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

#define fi "10925.inp"
#define fo "10925.out"
/**/
using namespace std;
/**/
char s[110];
int kq[110],a[110];
int len,n,k;
/**/
void khoitao()
{
    int i;
    for(i=0;i<=100;i++)
        a[i] = 0;
}
/**/
void daochuoi()
{
    int i,j;
    char temp;
    i = 0;
    j = len - 1;
    while(i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
/**/
void cong()
{
    int i;
    for(i=0;i<=50;i++)
    {
        if(i < len)
            a[i] += s[i] - 48;
        if(a[i] > 9)
        {
            a[i] %= 10;
            a[i+1]++;
        }
    }
}
/**/
void chia()
{
    int i,j;
    int temp;
    int dem;
    dem = 0;
    for(i=50;i>=0;i--)
    {
        if(a[i] != 0)
        {
            j = i;
            temp = a[j];
            while(true)
            {
                printf("%d",a[j]); 
                if(temp / k != 0)
                {
                    kq[dem++] = temp / k;
                    temp %= k;
                }
                else
                    kq[dem++] = 0;
                if(!j)
                    break;
                j--;
                temp *= 10;
                temp += a[j];
            }
            break;
        }
    }
    printf(": each friend should pay ");
    for(i=0;i<dem;i++)
        if(kq[i] != 0)
        {
            for(j=i;j<dem;j++)
                printf("%d",kq[j]);
            return;
        }
    printf("0");
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(scanf("%d %d",&n,&k) == 2)
    {
        if(!n && !k)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s",&s);
            len = strlen(s);
            daochuoi();
            cong();
        }
        printf("Bill #%d costs ",id++);
        chia();
        printf("\n\n");
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
