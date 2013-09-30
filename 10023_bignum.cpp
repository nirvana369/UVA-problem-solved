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
int lenx,leny,lenz,len;
char x[4100],y[4100],z[4100];
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
        
    /*if(arr[0] % 2 != 0)        
    {
        val = s[j-1] - 48;
        val++;
        s[j-1] = (val%10 + 48);
    }*/
    
    s[j] = 0;
    return j;
}
/**/
bool chk(char s1[],char s2[],int l1,int l2,int flg)
{
    // flg = 0 thuan chieu
    // flg = 1 dao chieu
    int i;
    
    if(l1 < l2)
        return false;
    
    if(l1 > l2)    
        return true;
    
    if(!flg)
    {
        i = 0;
        while(i < l1)
        {
            if(s1[i] > s2[i])
                return true;
            if(s2[i] > s1[i])
                return false;
            i++;
        }
        return true;
    }
    else
    {
        i = l1-1;
        while(i >= 0)
        {
            if(s1[i] > s2[i])
                return true;
            if(s2[i] > s1[i])
                return false;
            i--;
        }
        return true;
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
int sub(char s1[],char s2[],int l1,int l2,char s[])
{
    int i,j;
    int arr[4000];
    
    for(i=0;i<=l1;i++)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] += (s1[i] - 48) - (s2[i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
    }
    for(i=l1;i>=0;i--)
        if(arr[i] > 0)
        {
            for(j=0;j<=i;j++)
                s[j] = arr[j] + 48;
            return i+1;
        }
    return 0;
}
/**/
int div_str(char s1[],char s2[],int l1,int l2,char s[])
{
    int i,j,k;
    int len,dem;
    char tmp[4000],str[4000];
    
    if(l2 == 1 && s2[0] == '1')
    {
        strcpy(s,s1);
        return l1;
    }
    j = 0;
    len = 0;
    for(i=0;i<l1;i++)
    {
        tmp[j++] = s1[i];
        if(chk(tmp,s2,j,l2,0))
        {
            tmp[j] = 0;
            dem = 0;
            daochuoi(tmp,j);
            daochuoi(s2,l2);
            while(chk(tmp,s2,j,l2,1))
            {
                j = sub(tmp,s2,j,l2,tmp);
                dem++;
            }
            
            sprintf(str,"%d",dem);
            k = 0;
            while(str[k])
                s[len++] = str[k++];
            daochuoi(tmp,j);
            daochuoi(s2,l2);
        }
        else if(len)
            s[len++] = '0';
    }
    
    s[len] = 0;
    return len;
}

/**/
void solve()
{
    int i,j;   
    
    x[0] = '1';
    x[1] = 0;
    lenx = 1;
    
    leny = strlen(y);
    strcpy(z,x);
    lenz = 1;

    while(true)
    {
        lenx = div_str(y,z,leny,lenz,x); // y / z (1)
        daochuoi(x,lenx);
        daochuoi(z,lenz);
        if(!chk(x,z,lenx,lenz,1))
            lenx = add(z,x,lenz,lenx,x);
        else
            lenx = add(x,z,lenx,lenz,x); // (z + (1) )/ 2
        daochuoi(z,lenz);
        if(strcmp(x,z) == 0) // if x == z - > break
            break;
        strcpy(z,x);    // z = x
        lenz = lenx;
    }
    
    printf("%s\n",x);
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
