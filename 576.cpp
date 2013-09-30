/*
                                            Hoang Linh
                                        
                                    Problem: HAIKU REVIEW - 576 (576.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "576.inp"
#define fo "576.out"
/**/
using namespace std;
/**/
int hk[5];
/**/
void solve(char s[])
{
    int i;
    int l,dem,chk;
    
    l = strlen(s);
    dem = 1;
    chk = 0;
    for(i=0;i<l;i++)
        if(s[i] == '/')
        {
            if(chk != hk[dem])
                break;
            dem++;
            chk = 0;
        }
        else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'y' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
        {
            if(s[i-1] != 'a' && s[i-1] != 'e' && s[i-1] != 'y' && s[i-1] != 'o' && s[i-1] != 'u' && s[i-1] != 'i')
                chk++;
        }
            
    if(dem == 3 && chk == hk[dem])
        printf("Y\n");
    else
        printf("%d\n",dem);
}
/**/
void input()
{
    char temp[10000],quit[100];
    strcpy(quit,"e/o/i");
    hk[1] = 5;
    hk[2] = 7;
    hk[3] = 5;
    while(true)
    {
        gets(temp);
        if(strcmp(temp,quit) == 0)
            return;
        solve(temp);
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
