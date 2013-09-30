/*/
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "526.inp"
#define fo "526.out"
#define maxval 2000
/**/
using namespace std;
/**/
char s1[170],s2[85];
int l[100][100];
int l1,l2;
/**/
void khoitao()
{
    int i,j;    
    
    for(i=0;i<=l1;i++)
        for(j=0;j<=l2;j++)
            l[i][j] = 0;
            
    for(i=1;i<l1;i++)
    {
        l[i][0] = maxval;
        l[i][1] = i-1;
    }
        
    for(i=2;i<l2;i++)
    {
        l[1][i] = i-1;
        l[0][i] = maxval;
    }
}
/**/
void chen(char kt,char s[],int vitri)
{
    int i;
    for(i=l1;i>vitri;i--)
        s[i] = s[i-1];
    s[vitri] = kt;
    l1++;
}
/**/
void xoa(char s[],int vitri)
{
    int i;
    for(i=vitri;i<l1-1;i++)
        s[i] = s[i+1];
    l1--;
    s[l1] = 0;
}
/**/
void solve()
{
    int i,j;
    
    khoitao();
    
    for(i=1;i<l1;i++)
        for(j=1;j<l2;j++)
            if(s1[i] == s2[j])
                l[i][j] = l[i-1][j-1];
            else
                l[i][j] = 1 + min(l[i][j-1],min(l[i-1][j-1],l[i-1][j])); // chen , thay , xoa
    
    i = l1 - 1;
    j = l2 - 1;
    
    while(l[i][j])
    {
        if(s1[i] == s2[j])
        {
            i--;
            j--;
        }
        else
        {
            if(l[i][j] - 1 == l[i][j-1]) // insert 
            {
                
                chen(s2[j],s1,i);
                printf("chen vao %d ky tu %c\n",i+1,s2[j]);
            }
            else if(l[i][j] - 1 == l[i-1][j-1]) // replace
            {
                s1[i] = s2[j];
                printf("thay vao %d ky tu %c\n",i+1,s2[j]);
            }
            else
            {
                xoa(s1,i);
                printf("xoa %d\n",i+1);
            }
        }
    }
    printf("\n");
}
/**/
int tests(char s[],int len)
{
    int i;
    for(i=len;i>0;i--)
        s[i] = s[i-1];
    len++;
    s[len] = 0;
    return len;
}
/**/
void input()
{
    while(gets(s1) && gets(s2))
    {
        l1 = tests(s1,strlen(s1));
        l2 = tests(s2,strlen(s2));
        solve();
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
