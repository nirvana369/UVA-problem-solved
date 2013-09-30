/*
                                                        Hoang Linh
                                                    
                                            Problem: PIG-LATIN - 492 (492.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "492.inp"
#define fo "492.out"
/**/
using namespace std;
/**/
void output(char s[],int len)
{
    int i;
    char kt;
    kt = s[0];
    if(s[0] >= 97)
        kt = kt - 32;
    if(kt == 'U' || kt == 'O' || kt == 'E' || kt == 'A' || kt == 'I')
        printf("%s",s);
    else
    {
        for(i=1;i<len;i++)
            printf("%c",s[i]);
    }
}
/**/
void input()
{
    char temp[1000000];
    char kt,tempkt;
    int dem;
    dem = 0;
    
    while(true)
    {
        kt = 0;
        scanf("%c",&kt);
        if(kt == 0)
            break;
        if((kt >= 'a' && kt <='z' || kt >= 'A' && kt <= 'Z'))
        {
            temp[dem] = kt;
            dem++;   
        }
        else
        {
            if(dem > 0)
            {
                temp[dem] = 0;
                if(kt != '\n')
                {
                    output(temp,dem);
                    
                    tempkt = temp[0];
                    if(temp[0] >= 97)
                        tempkt = tempkt - 32;
                        
                    if(!(tempkt == 'U' || tempkt == 'O' || tempkt == 'E' || tempkt == 'A' || tempkt == 'I'))
                        printf("%c",temp[0]);
                    printf("ay");
                }
                else
                    output(temp,dem);
                dem = 0;   
            }
            printf("%c",kt);
        }
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
