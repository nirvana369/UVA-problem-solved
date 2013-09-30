/*
                                                    Hoang Linh
                                                    
                                    Problem: KINDERGARTEN COUNTING GAME - 494 (494.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "494.inp"
#define fo "494.out"
/**/
using namespace std;
/**/
void solve(char s[])
{
    int i;
    int l,dem,word;
    l = strlen(s);
    s[l] = ' ';
    
    dem = 0;
    word = 0;
    for(i=0;i<=l;i++)
        if(!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') && dem > 0)
        {
            dem = 0;
            word++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
            dem++;
    printf("%d\n",word);
}
/**/
void input()
{
    char temp[100000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
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
