/*
                                                Hoang Linh
                                                
                                    Problem: ADDING REVERSED NUMBERS - 713 (713.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "713.inp"
#define fo "713.out"
/**/
using namespace std;
/**/
void addn(char s1[],char s2[],int l1,int l2)
{
    int arr[10000];
    int templ;
    int i,j,k;
    
    templ = l1 + l2;
    
    for(i=0;i<=templ;i++)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
        if(i < l2)
        {
            arr[i] = arr[i] + (s1[i] - 48) + (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] = arr[i] % 10;
            }
        }
        else
        {
            arr[i] = arr[i] + (s1[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] = arr[i] % 10;
            }
        }
    for(i=templ;i>=0;i--)
        if(arr[i] != 0)
            break;
    for(j=0;i<=i;j++)
        if(arr[j] != 0)
            break;
    for(k=j;k<=i;k++)
        printf("%d",arr[k]);
    printf("\n");
}
/**/
void input()
{
    int itest,i;
    int ntest;
    int l1,l2;
    char n1[300],n2[300];
    
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++)
    {
        scanf("%s %s",&n1,&n2);
        l1 = strlen(n1);
        l2 = strlen(n2);
        if(l1 > l2)
            addn(n1,n2,l1,l2);
        else
            addn(n2,n1,l2,l1);
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
