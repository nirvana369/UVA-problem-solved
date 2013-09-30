/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "537.inp"
#define fo "537.out"
/**/
using namespace std;
/**/
void xuly(char s[])
{
    int i,j;
    int l,dem;
    char temp[10000];
    bool bp,bu,bi;
    double vu,vp,vi;
    
    l = strlen(s);
    s[l] = ' ';
    bp = bu = bi = false;
    
    for(i=0;i<=l;i++)
    {
        if(s[i] == '=')
        {
            if(s[i-1] == 'P')
            {
                bp = true;
                dem = 0;
                for(j=i+1;j<l;j++)
                    if((s[j] >= '0' && s[j] <= '9') || s[j] == '.')
                        temp[dem++] = s[j];
                    else
                        break;
                temp[dem] = 0;
                dem = 0;
                sscanf(temp,"%lf",&vp);
                while(s[j] != ' ')
                {
                    temp[dem++] = s[j];
                    j++;    
                }
                if(dem > 1)
                {
                    if(temp[0] == 'm')
                        vp = vp / 1000;
                    else if(temp[0] == 'k')
                        vp = vp * 1000;
                    else if(temp[0] == 'M')
                        vp = vp * 1000000;
                }
                dem = 0;
                i = j;
            }
            else if(s[i-1] == 'U')
            {
                bu = true;
                dem = 0;
                for(j=i+1;j<l;j++)
                    if((s[j] >= '0' && s[j] <= '9') || s[j] == '.')
                        temp[dem++] = s[j];
                    else
                        break;
                temp[dem] = 0;
                dem = 0;
                sscanf(temp,"%lf",&vu);
                while(s[j] != ' ')
                {
                    temp[dem++] = s[j];
                    j++;    
                }
                if(dem > 1)
                {
                    if(temp[0] == 'm')
                        vu = vu / 1000;
                    else if(temp[0] == 'k')
                        vu = vu * 1000;
                    else if(temp[0] == 'M')
                        vu = vu * 1000000;
                }
                dem = 0;
                i = j;
            }
            else if(s[i-1] == 'I')
            {
                bi = true;
                dem = 0;
                for(j=i+1;j<l;j++)
                    if((s[j] >= '0' && s[j] <= '9') || s[j] == '.')
                        temp[dem++] = s[j];
                    else
                        break;
                temp[dem] = 0;
                dem = 0;
                sscanf(temp,"%lf",&vi);
                while(s[j] != ' ')
                {
                    temp[dem++] = s[j];
                    j++;    
                }
                if(dem > 1)
                {
                    if(temp[0] == 'm')
                        vi = vi / 1000;
                    else if(temp[0] == 'k')
                        vi = vi * 1000;
                    else if(temp[0] == 'M')
                        vi = vi * 1000000;
                }
                dem = 0;
                i = j;
            }
        }
    }
    
    if(!bp)
    {
        vp = vu * vi;
        printf("P=%0.2lfW\n",vp);
    }
    else if(!bu)
    {
        vu = vp / vi;
        printf("U=%0.2lfV\n",vu);
    }
    else
    {
        vi = vp / vu;
        printf("I=%0.2lfA\n",vi);
    }
}
/**/
void input()
{
    char temp[10000];
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        printf("Problem #%d\n",id);
        xuly(temp);
        printf("\n");
        id++;
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
