/*
                                                        Hoang Linh
                                                        
                                        Problem: FIBONACCI FREEZE - 495 (495.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "495.inp"
#define fo "495.out"
/**/
using namespace std;
/**/
int l[6000];
char f[6000][10000];
/**/
void cong(int id,char s1[],char s2[],int l1,int l2)
{
    int i,j;
    int arr[10000];
    int templ;
    templ = l1 + l2;
    for(i=0;i<=templ;i++)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        if(i < l2)
        {
            arr[i] = arr[i] + s1[i]-48 + s2[i]-48;
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] = arr[i] % 10;
            }
        }
        else
        {
            arr[i] = arr[i] + s1[i]-48;
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] = arr[i] % 10;
            }
        }
        
    for(i=templ;i>=0;i--)
        if(arr[i] != 0)
        {
            l[id] = i+1;
            for(j=0;j<=i;j++)
                f[id][j] = arr[j] + 48;
            return;
        }
}
/**/
void precal()
{
    int i;
    
    f[0][0] = '0';
    f[1][0] = '1';
    
    l[0] = 1;
    l[1] = 1;    
    
    for(i=2;i<=5000;i++)
        cong(i,f[i-1],f[i-2],l[i-1],l[i-2]);
}
/**/
void input()
{
    int i;
    int n;
    precal();
    while(true)
    {
        n = -1;
        scanf("%d",&n);
        if(n == -1)
            break;
        printf("The Fibonacci number for %d is ",n);
        for(i=l[n]-1;i>=0;i--)
            printf("%c",f[n][i]);
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
