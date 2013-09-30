/*
                                                Hoang Linh
                                                
                                                
                                    Problem: PRIME WORDS - 10924 (10924.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10924.inp"
#define fo "10924.out"
/**/
using namespace std;
/**/
char gt[200];
/**/
void khoitao()
{
    int i;
    int dem;
    dem = 1;
    for(i='a';i<='z';i++,dem++)
        gt[i] = dem;
    
    for(i='A';i<='Z';i++,dem++)
        gt[i] = dem;
}
/**/
bool isnt(int value)
{
    int i;
    int add,temp;
    
    if(value == 1 || value == 2 || value == 3)
        return true;
    if(value % 2 == 0 || value % 3 == 0)
        return false;
    temp = (int)sqrt(value);
    add = 2;
    for(i=5;i<=temp;i=i+add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void solve(char s[])
{
    int i;
    int l;
    int tong;
    
    l = strlen(s);
    tong = 0;
    for(i=0;i<l;i++)
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            tong = tong + gt[s[i]];
    if(isnt(tong))
        printf("It is a prime word.\n");
    else
        printf("It is not a prime word.\n");
}
/**/
void input()
{
    char temp[10000];
    khoitao();
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
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
