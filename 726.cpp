/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "726.inp"
#define fo "726.out"
/**/
using namespace std;
/**/
char d[200],a[40900][40900],c1[100],c2[100];
long kn[200],de[200];
long cd,da,cd1;
/**/
void sapxep()
{
    long i,j;
    char tmp;
    
    for(i=0;i<26;i++)
        for(j=i+1;j<=26;j++)
            if(kn[c1[i]] < kn[c1[j]])
            {
                tmp = c1[i];
                c1[i] = c1[j];
                c1[j] = tmp;
            }
            else if(kn[c1[i]] == kn[c1[j]])
            {
                if(c1[i] > c1[j])
                {
                    tmp = c1[i];
                    c1[i] = c1[j];
                    c1[j] = tmp;
                }
            }
                        
    for(i=0;i<26;i++)
        for(j=i+1;j<=26;j++)
            if(de[c2[i]] < de[c2[j]])
            {
                tmp = c2[i];
                c2[i] = c2[j];
                c2[j] = tmp;
            }
            else if(de[c2[i]] == de[c2[j]])
            {
                if(c2[i] > c2[j])
                {
                    tmp = c2[i];
                    c2[i] = c2[j];
                    c2[j] = tmp;
                }
            }
}
/**/
void solve()
{
    long i,j;
    sapxep();
    
    for(i=0;i<=26;i++)
        d[c2[i]] = c1[i];
    
    for(i=0;i<da;i++)
    {
        j = 0;
        while(a[i][j])
        {
            if(a[i][j] >= 'A' && a[i][j] <= 'Z')
                printf("%c",d[a[i][j]-'A']+'A');
            else if(a[i][j] >= 'a' && a[i][j] <= 'z')
                printf("%c",d[a[i][j]-'a']+'a');
            else
                printf("%c",a[i][j]);
            j++;
        }
        printf("\n");
    }
}
/**/
void khoitao()
{
    int i,j;
    j = 0;
    for(i=0;i<=26;i++)
    {
        d[i] = i;
        kn[i] = de[i] = 0;
        c1[i] = c2[i] = i;
    }
}
/**/
void input()
{
    long i,j;
    char s[100100];
    
    khoitao();
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(!s[0])
            break;
        i = 0;
        while(s[i])
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                kn[s[i]-'A']++;
            else if(s[i] >= 'a' && s[i] <= 'z')
                kn[s[i]-'a']++;
            i++;
        }
    }
    j = 0;
    while(gets(a[j]))
    {
        i = 0;
        while(a[j][i])
        {
            if(a[j][i] >= 'A' && a[j][i] <= 'Z')
                de[a[j][i]-'A']++;
            else if(a[j][i] >= 'a' && a[j][i] <= 'z')
                de[a[j][i]-'a']++;
            i++;
        }
        j++;

        if(feof(stdin))
            break;
    }
    da = j;
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
