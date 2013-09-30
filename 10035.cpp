/*
                                                        Hoang Linh
                                                        
                                            Problem: PRIMARY ARITHMETIC - 10035 (10035.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10035.inp"
#define fo "10035.out"
/**/
using namespace std;
/**/
long long a,b;
/**/
void daochuoi(char s[],int len)
{
    int i;
    char temp;
    i = 0;
    while(i < len)
    {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        i++;
        len--;
    }
}
/**/
void solve()
{
    int i;
    long long mingt,maxgt;
    char tempa[100],tempb[100];
    int dem,la,lb;
    int value,nho;
    if(a > b)
    {
        mingt = b;
        maxgt = a;
    }
    else
    {
        mingt = a;
        maxgt = b;
    }
    
    sprintf(tempa,"%lld",mingt);
    sprintf(tempb,"%lld",maxgt);
    
    lb = strlen(tempb);
    la = strlen(tempa);
    daochuoi(tempa,la-1);
    daochuoi(tempb,lb-1);
    nho = 0;
    dem = 0;
    for(i=0;i<lb;i++)
    {
        if(i < la)
        {
            value = tempb[i]-48 + tempa[i]-48 + nho;
            nho = 0;
            if(value > 9)
            {
                nho = 1;
                dem++;
            }
        }
        else
        {
            value = tempb[i]-48 + nho;
            nho = 0;
            if(value > 9)
            {
                nho = 1;
                dem++;
            }
        }
    }
    
    if(dem == 0)
        printf("No carry operation.\n");
    else if(dem == 1)
        printf("1 carry operation.\n");
    else
        printf("%d carry operations.\n",dem);
}
/**/
void input()
{
    while(true)
    {
        scanf("%lld %lld",&a,&b);
        if(!a && !b)
            break;
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
