/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "245.inp"
#define fo "245.out"
/**/
using namespace std;
/**/
char a[1000000][60];
long da;
/**/
void cutstr(int vt)
{
    long i;
    char tmp[100];
    strcpy(tmp,a[vt]);
    for(i=vt;i<da-1;i++)
        strcpy(a[i],a[i+1]);
    strcpy(a[da-1],tmp);
}
/**/
void input()
{
    long i,j,k,id;
    int l,dem;
    char s[1000000],num[100],tmp[100];
    
    da = 0;
    while(true)
    {
        gets(s);
        l = strlen(s);
        if(l == 1 && s[0] == '0')
            break;
        
        dem = 0;
        for(i=0;i<l;i++)
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
                tmp[dem++] = s[i];
            else if(s[i] >= '0' && s[i] <= '9')
            {
                j = i;  
                dem = 0;
                while(s[j] >= '0' && s[j] <= '9') 
                    num[dem++] = s[j++];
                num[dem] = 0;
                sscanf(num,"%ld",&id);
                //
                k = da;
                while(id--)         
                    k--;
                printf("%s",a[k]);
                cutstr(k);
                //
                dem = 0;
                i = j-1;
            }
            else
            {
                if(dem != 0)
                {
                    tmp[dem] = 0;
                    printf("%s",tmp);
                    strcpy(a[da++],tmp);
                    dem = 0;
                }
                printf("%c",s[i]);
            }
        if(dem != 0)
        {
            tmp[dem] = 0;
            printf("%s",tmp);
            strcpy(a[da++],tmp);
            dem = 0;
        }
        printf("\n");
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
