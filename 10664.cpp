/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10664.inp"
#define fo "10664.out"
/**/
using namespace std;
/**/
int a[25];
int da;
bool finda;
/**/
void sapxep()
{
    int i,j;
    int temp;
    
    for(i=0;i<da-1;i++)
        for(j=i+1;j<da;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void dequy(int j,int sum)
{
    int i;
    if(sum == 0)
    {
        finda = true;
        return;
    }
    
    for(i=j;i<da;i++)
        if(sum - a[i] >= 0)
        {
            dequy(i+1,sum-a[i]);
            if(finda)
                return;
        }
}
/**/
void xuly(char s[])
{
    int i;
    int l,sum,dem;
    char temp[100];
    
    da = dem = sum = 0;
    l = strlen(s);
    s[l] = ' ';
    for(i=0;i<=l;i++)
    {
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&a[da]);
            sum += a[da];
            da++;
            dem = 0;
        }
        else
            temp[dem++] = s[i];
    }
    finda = false;
    if(sum % 2 != 0)
        finda = false;
    else
    {
        sapxep();
        dequy(0,sum/2);
    }
    
    if(finda)
        printf("YES\n");
    else
        printf("NO\n");
}
/**/
void input()
{
    int i;
    int ntest;
    char temp[10000];
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        xuly(temp);
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
