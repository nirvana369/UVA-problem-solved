/*
                                                        Hoang Linh


initialize temp to a guess of sqrt(Y)
while(1) {
  X = (temp + (Y / temp)) / 2;
  if(temp == X)
    break;
  temp = X;
}

*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10023.inp"
#define fo "10023.out"
/**/
using namespace std;
/**/
int lenx,leny,lenz,lenk;
char x[1100],y[1100],z[1100],k[1100];
bool match;
/**/
int add(char s1[],char s2[],int l1,int l2,char s[])
{
    int i,j;
    int arr[4000];
    int val;
    int len;
    // add
    len = l1 + l2;
    for(i=0;i<=len;i++)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] += (s1[i] - 48) + (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] %= 10;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] %= 10;
            }
        }
    }
    for(i=len;i>=0;i--)
        if(arr[i] != 0)
            break;
    // div 2
    j = 0;
    val = 0;
    while(i >= 0)
    {
        val *= 10;
        val += arr[i];
        if(val >= 2)
        {
            s[j++] = (val / 2) + 48;
            val = val % 2;
        }
        else if(j)
            s[j++] = '0';
        i--;
    }
    
    if(!j)
        s[j++] = '0';
        
    s[j] = 0;
    return j;
}
/**/
bool mul(char s1[],char s2[],int l1,int l2)
{
    int i,j;
    int len;
    int arr[4000];
    
    len = l1 + l2 + 10;
    for(i=0;i<=len;i++)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] += (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    
    for(i=len;i>=0;i--)
        if(arr[i] != 0)
        {
            if(i+1 > lenk)
                return true;
            if(i+1 < lenk)
                return false;
            if(i+1 == lenk)
            {
                for(j=i;j>=0;j--)
                {
                    if(arr[j] > (k[j] - 48))
                        return true;
                    if(arr[j] < (k[j] - 48))
                        return false;
                }
                match = true;
                return true;
            }
        }
}
/**/
void daochuoi(char s[],int len)
{
    int i,j;
    char tmp;
    
    i = 0;
    j = len - 1;
    while(i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
/**/
bool chk()
{
    int i;
    
    if(lenx < leny)
        return true;
    if(lenx > leny)
        return false;
    if(lenx == leny)
    {
        for(i=lenx-1;i>=0;i--)
            if(y[i] > x[i])
                return true;

        if(i < lenx-1)
            return true;
        if(y[lenx-1] - x[lenx-1] <= 1)
            return false;
        return true;
    }
    return false;
}
/**/
void solve()
{
    int i,j;   
    int kq[1000];
    
    match = false;
    leny = strlen(y);
    
    if(leny == 1)
        if(y[0] == '1' || y[0] == '0')
        {
            printf("%c\n",y[0]);
            return;
        }
    daochuoi(y,leny);
    lenk = leny;
    strcpy(k,y);
    
    x[0] = '0';
    x[1] = 0;
    lenx = 1;
    
    leny = add(y,x,leny,lenx,y);
    daochuoi(y,leny);
    
    while(chk())
    {
        lenz = add(y,x,leny,lenx,z);
        daochuoi(z,lenz);
        if(mul(z,z,lenz,lenz))
        {
            strcpy(y,z);
            leny = lenz;
        }
        else
        {
            strcpy(x,z);
            lenx = lenz;
        }
        if(match)
            break;
    }
    
    if(match)
    {
        daochuoi(z,lenz);
        printf("%s\n",z);
        return;
    }
    lenz = add(y,x,leny,lenx,z);
    daochuoi(z,lenz);
    for(i=0;i<=lenz;i++)
        kq[i] = 0;
    j = 0;
    kq[0] = 1;
    for(i=0;i<lenz;i++)
    {
        kq[j] += (z[i] - 48);
        if(kq[j] > 9)
        {
            kq[j+1]++;
            kq[j] %= 10;
        }
        j++;
    }
    for(i=lenz;i>=0;i--)
        if(kq[i] != 0)
        {
            for(j=i;j>=0;j--)
                printf("%d",kq[j]);
            break;
        }
    printf("\n");
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&y);
        solve();
        if(ntest)
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
