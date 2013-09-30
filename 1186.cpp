/*
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

#define fi "1186.inp"
#define fo "1186.out"
/**/
using namespace std;
/**/
int vowel[100000];
char a[100000][400];
long n;
/**/
bool isvw(char kt)
{
    if(kt == 'a' || kt == 'e' || kt == 'i' || kt == 'o' || kt == 'u')
        return false;
    if(kt == 'A' || kt == 'E' || kt == 'I' || kt == 'O' || kt == 'U')
        return false;
        
    if(isalpha(kt))
        return true;

    return false;
}
/**/
int countvw(char s[])
{
    int i;
    int dem,vw;
    
    i = 0;
    dem = 0;
    vw = 0;
    while(s[i])
    {
        if(isvw(s[i]))
            dem++;
        else
        {
            vw = max(vw,dem);
            dem = 0;
        }
        i++;
    }
    
    vw = max(vw,dem);
    return vw;
}
/**/
bool chk(int id)
{
    int m,dem,csame;
    long i,j;
    
    if(vowel[id] > 5)
        return true;
    
    dem = j = 0;

    if(vowel[id] > 4)
        for(i=id-1;i >= 0;i--)
        {
            if(vowel[i] > 4)
            {
                dem++;
                if(dem == 3)
                    return true;
            } 
            j++;
            if(j == 10)
                break;   
        }
        
    dem = j = 0;
    for(i=id-1;i >= 0;i--)
    {
        if(strcmp(a[i],a[id]) == 0)
        {
            dem++;
            if(dem == 2)
                return true;
        }
        j++;
        if(j == 10)
            break;
    }
    return false;
}
/**/
void input()
{
    long i;
    scanf("%ld",&n);
    gets(a[0]);
    
    for(i=0;i<n;i++)
    {
        gets(a[i]);
        vowel[i] = countvw(a[i]);
        
        if(chk(i))
            printf("n\n");
        else
            printf("y\n");
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
