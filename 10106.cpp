/*
                                                    Hoang Linh
                                                    
                                            Problem: PRODUCT - 10106 (10106.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10106.inp"
#define fo "10106.out"
/**/
using namespace std;
/**/
char s1[10000],s2[10000];
int l1,l2;
/**/
int daochuoi(char s[])
{
    int i;
    int l,templ;
    char temp;
    l = strlen(s);
    templ = l;
    i = 0;
    l--;
    while(i < l)
    {
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
        i++;
        l--;
    }
    return templ;
}
/**/
void mul()
{
    int i,j;
    int arr[10000];
    int l;
    
    l = 1000;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] = arr[i+j] + (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] = arr[i+j+1] + arr[i+j] / 10;
                arr[i+j] = arr[i+j] % 10;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=i;j>=0;j--)
                printf("%d",arr[j]);
            printf("\n");
            return;
        }
    printf("0\n");
}
/**/
void input()
{
    while(true)
    {
        s1[0] = 0;
        scanf("%s %s",&s1,&s2);
        if(s1[0] == 0)
            break;
        l1 = daochuoi(s1);
        l2 = daochuoi(s2);
        mul();
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
