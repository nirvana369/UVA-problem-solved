/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10061.inp"
#define fo "10061.out"
#define maxgt 2097154
/**/
using namespace std;
/**/
string num[maxgt+5];
long l[maxgt+5];
/**/
int cvn(long val,char s[])
{
    int i;
    i = 0;
    while(val != 0)
    {
        s[i++] = val % 10 + 48;
        val /= 10;
    }
    return i;
}
/**/
int mul(string s1,char s2[],int l1,int l2,string &s3)
{
    int i,j;
    int len;
    int arr[100000];
    len = l1 + l2 + 5;
    
    for(i=len;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] += (s1[l1-i-1] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    
    for(i=len;i>=0;i--)
        if(arr[i] != 0)
        {
            s3 = "";
            for(j=i;j>=0;j--)
                s3 += arr[j] + 48;
            return i+1;
        }
}
/**/
void _init()
{
    long i;
    long len;
    char tmp[100000];
    
    num[1] = "1";
    num[2] = "2";
    num[3] = "6";
    l[1] = l[2] = l[3] = 1;
    for(i=4;i<=maxgt;i++)
    {
        len = cvn(i,tmp);
        l[i] = mul(num[i-1],tmp,l[i-1],len,num[i]);
        //cout << num[i] << endl;
    }
}
/**/
void input()
{
    _init();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
