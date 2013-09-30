/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12626.inp"
#define fo "12626.out"
/**/
using namespace std;
/**/
int getmin(int val1,int val2)
{
    return (val1 > val2) ? val2 : val1;
}
/**/
void input()
{
    int i;
    int ntest;
    char s[700];
    char pizza[7] = "MARTGI";
    int d[100],c[100];
    int minp;
    
    c['M'] = 1;
    c['A'] = 3;
    c['R'] = 2;
    c['T'] = 1;
    c['G'] = 1;
    c['I'] = 1;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        for(i=0;i<6;i++)
            d[pizza[i]] = 0;
        i = 0;
        while(s[i])
        {
            if(s[i] == 'M' || s[i] == 'A' || s[i] == 'R' || s[i] == 'T' || s[i] == 'G' || s[i] == 'I')
                d[s[i]]++;
            i++;
        }
        minp = 700;
        for(i=0;i<6;i++)
            if(d[pizza[i]] == 0)
            {
                minp = 0;
                break;
            }
            else
                minp = getmin(minp,d[pizza[i]] / c[pizza[i]]);
                
        printf("%d\n",minp);
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
