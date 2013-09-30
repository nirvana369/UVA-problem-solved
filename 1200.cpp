/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1200.inp"
#define fo "1200.out"
/**/
using namespace std;
/**/
char s[1000];
void solve()
{
    int i,dem,j;
    long trai,phai,val;
    char tmp[1000];
    char dau;
    double kq;
    
    i = j = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            s[j++] = s[i];
        i++;
    }
    s[j] = ' ';
    s[j+1] = 0;
    
    trai = phai = 0;
    i = dem = 0;
    dau = '+';
    while(s[i]) // truoc dau  = 
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == ' ')
        {
            if(dem != 0)
            {
                tmp[dem] = 0;
                sscanf(tmp,"%ld",&val);
                if(dau == '-')
                    val = -val;
                trai += val;
                dem = 0;
            }
            if(s[i] == '=')
            {
                i++;
                break;
            }
                
            dau = s[i];
        }
        else if(s[i] == 'x')
        {
            if(dem != 0)
            { 
                tmp[dem] = 0;
                sscanf(tmp,"%ld",&val);
                dem = 0;
            }
            else
                val = 1;
            if(dau == '+')
                val = -val;
            phai += val;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            tmp[dem++] = s[i];
        i++;
    }
    
    dau = '+';
    while(s[i]) //  sau dau =
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == ' ')
        {
            if(dem != 0)
            {
                tmp[dem] = 0;
                sscanf(tmp,"%ld",&val);
                if(dau == '+')
                    val = -val;
                trai += val;
                dem = 0;
            }
            if(s[i] == '=')
                break;
                
            dau = s[i];
        }
        else if(s[i] == 'x')
        {
            if(dem != 0)
            { 
                tmp[dem] = 0;
                sscanf(tmp,"%ld",&val);
                dem = 0;
            }
            else
                val = 1;
            if(dau == '-')
                val = -val;
            phai += val;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            tmp[dem++] = s[i];
        i++;
    }
    
    if(!trai && !phai)
        printf("IDENTITY\n");
    else if(!phai)
        printf("IMPOSSIBLE\n");
    else
    {
        kq = (double)trai / phai;
        printf("%ld\n",(long)floor(kq));
    }
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
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
