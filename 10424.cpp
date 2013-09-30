/*
                                                    Hoang Linh

                                   Problem: LOVE CALCULATOR - 10424 (10424.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10424.inp"
#define fo "10424.out"
/**/
using namespace std;
/**/
int kt[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
/**/
int convert(char c)
{
    if(c >= 'a' && c <= 'z')
        return kt[c-97];
    if(c >= 'A' && c <= 'Z')
        return kt[c-65];
}
/**/
int xuly(char s[])
{
    int i;
    int l;
    int value,temp;
    value = 0;
    l = strlen(s); 
    for(i=0;i<l;i++)
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
            value = value + convert(s[i]);
            
    while(value > 9)
    {
        temp = value;
        value = 0;
        while(temp != 0)
        {
            value = value + temp % 10;
            temp = temp / 10;
        }
    }
    return value;
}
/**/
void input()
{
    char temp[10000];
    int a,b,gt;
    float kq;
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        a = xuly(temp);
        gets(temp);
        b = xuly(temp);
        if(a > b)
        {
            gt = a;
            a = b;
            b = gt;
        }
        kq = a * 100;
        kq = kq / b;
        if(kq > 100)
            printf("100.00 %%\n");
        else
            printf("%0.2f %%\n",kq);
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
