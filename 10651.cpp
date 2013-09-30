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

#define fi "10651.inp"
#define fo "10651.out"
/**/
using namespace std;
/**/
char s[13];
int d[4100];
int maxp;
/**/
int demp()
{
    int i;
    int dem;
    dem = 0;
    for(i=0;i<12;i++)
        if(s[i] == 'o')
            dem++;
    return dem;
}
/**/
int getval(int bac)
{
    int i;
    int val;
    val = 1;
    for(i=0;i<bac;i++)
        val *= 2;
    return val;
}
/**/
int bitchange() // chuyen chuoi binary sang dec
{
    int i;
    int val;
    val = 0;
    for(i=0;i<12;i++)
        if(s[i] == 'o')
            val += getval(i);
    return val;
}
/**/
int daobit(int dau,int cuoi,int pep) // dao bit
{
    int i;
    for(i=dau;i<=cuoi;i++)
    {
        if(s[i] == '-')
        {
            s[i] = 'o';
            pep++;
        }
        else
        {
            s[i] = '-';
            pep--;
        }
    }    
    return pep;
}
/**/
void dq(int pep)
{
    int i,j;
    int temp;
    if(pep < maxp)
        maxp = pep;
    if(maxp == 1)
        return;
    
    for(i=0;i<12;i++)
        if(s[i] == 'o')
        {
            for(j=0;j<=1;j++)
                if(!j)
                {
                    if(i-2 >= 0 && s[i-1] == 'o' && s[i-2] == '-') // oo-
                    {
                        pep = daobit(i-2,i,pep);
                        temp = bitchange();
                        if(d[temp] == 0)
                        {
                            d[temp] = 1;
                            dq(pep);
                            d[temp] = 0;
                        }
                        pep = daobit(i-2,i,pep);
                    }
                }
                else
                {
                    if(i+2 < 12 && s[i+1] == 'o' && s[i+2] == '-') // -oo
                    {
                        pep = daobit(i,i+2,pep);
                        temp = bitchange();
                        if(d[temp] == 0)
                        {
                            d[temp] = 1;
                            dq(pep);
                            d[temp] = 0;
                        }
                        pep = daobit(i,i+2,pep);
                    }
                }
        }
}
/**/
void khoitao() // reset 000000000000 -- > 111111111111  ~ 0 -- > 4095 
{
    int i;
    for(i=0;i<4096;i++)
        d[i] = 0;
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        maxp = demp();  // dem max pebble hien tai
        d[bitchange()] = 1;
        dq(maxp);
        printf("%d\n",maxp);
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
