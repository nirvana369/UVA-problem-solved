/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "263.inp"
#define fo "263.out"
/**/
using namespace std;
/**/
long chain[2000];
int demc;
/**/
long maxn(long value)
{
    int i,j,l;
    long gt;
    char temp[100];
    char tg;
    
    sprintf(temp,"%ld",value);      //  convert value to string
    l = strlen(temp);
    for(i=0;i<l-1;i++)              // sort max
        for(j=i+1;j<l;j++)
            if(temp[i] < temp[j])
            {
                tg = temp[i];
                temp[i] = temp[j];
                temp[j] = tg;
            }
    sscanf(temp,"%ld",&gt);  //  convert string to value
    return gt;
}
/**/
long minn(long value)
{
    int i,j,l;
    long gt;
    char temp[100];
    char tg;
    
    sprintf(temp,"%ld",value);      //  convert value to string
    l = strlen(temp);
    for(i=0;i<l-1;i++)                      // sort min
        for(j=i+1;j<l;j++)
            if(temp[i] > temp[j])
            {
                tg = temp[i];
                temp[i] = temp[j];
                temp[j] = tg;
            }
    sscanf(temp,"%ld",&gt); // convert string to value
    return gt;
}
/**/
void input()
{
    int j;
    long n,n1,n2,temp;
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
            break;
        demc = 0;
        printf("Original number was %ld\n",n);
        while(true)
        {
            n1 = maxn(n);        // sort n max
            n2 = minn(n);          // sort n min
            temp = n1 - n2;     // get subtract
            printf("%ld - %ld = %ld\n",n1,n2,temp);
            for(j=0;j<demc;j++)         // check previous result if == break 
                if(temp == chain[j])
                    break;
            if(j != demc)
                break;
            chain[demc] = temp;     // save result --> chain[] array
            demc++;             // count chain
            n = temp;
        }
        printf("Chain length %d\n\n",demc+1);
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
