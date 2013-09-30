/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "619.inp"
#define fo "619.out"
/**/
using namespace std;
/**/
char num[200][5],d[30];
/**/
int cong(char s1[],char s2[],char s3[])
{
    int i,j;
    int l1,l2,l;
    int arr[1000];
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    l = l1 + 5;
    
    for(i=l;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
    {
        if(l2)
        {
            l2--;
            arr[i] += (s1[l1-i-1] - 48) + (s2[l2] - 48);
        }
        else
            arr[i] += (s1[l1-i-1] - 48);
        if(arr[i] > 9)
        {
            arr[i+1] += arr[i] / 10;
            arr[i] %= 10;
        }
    }
    
    for(i=l;i>=0;i--)
        if(arr[i])
        {
            for(j=0;j<=i;j++)
                s3[j] = (char)(arr[i-j] + 48);
            s3[j] = 0;
            return j;
        }
    s1[0] = '0';
    return 1;
}
/**/
int nhan(char s1[],char s2[])
{
    int i,j;
    int l,l1,l2;
    int arr[1000];
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    
    l = l1 + l2 + 2;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] += (s1[l1-i-1] - 48) * (s2[l2-j-1] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i])
        {
            for(j=0;j<=i;j++)
                s1[j] = (char)(arr[i-j] + 48);
            s1[j] = 0;
            return j;
        }
    s1[0] = '0';
    return 1;
}
/**/
void xuly_char(char s[])
{
    int i,j;
    int l;
    
    i = 0;
    char s1[1000],s2[4];
    strcpy(s2,"26");
    
    i = 0;
    l = 1;
    s1[0] = '0';
    s1[1] = 0;
    while(s[i])
    {
        if(strlen(s1) >= 2)
            cong(s1,num[s[i]],s1);
        else
            cong(num[s[i]],s1,s1);
            
        if(s[i+1])
            nhan(s1,s2);
        i++;
    }
    
    l = strlen(s1) - 1;
    i = j = 0;
    while(l >= 0)
    {
        s[i++] = s1[l--];
        j++;
        if(j == 3)
        {
            j = 0;
            s[i++] = ',';
        }
    }
    if(s[i-1] == ',')
        i--;
    for(j=i-1;j>=0;j--)
        printf("%c",s[j]);
    printf("\n");
}
/**/
void xuly_num(char s[])
{
    char tmp[1000];
    int arr[1000];
    int i,j,k;
    int l;
    int val;
    
    strcpy(tmp,s);
    k = 0;
    while(true)
    {
        i = j = 0;
        val = 0;
        while(s[i])    
        {
            val *= 10;
            val += s[i] - 48;
            if(val > 26)
            {
                s[j++] = (val / 26) + 48;
                val %= 26;
            }
            else if(j)
                s[j++] = '0';
            i++;
        }
        
        if(val)
            arr[k++] = val;
            
        if(!j)
            break;
        s[j] = 0;
    }
    for(i=k-1;i>=0;i--)
        printf("%c",d[arr[i]]);
        
    for(j=k;j<22;j++)    
        printf(" ");
        
    l = strlen(tmp)-1;
    i = j = 0;
    while(l >= 0)
    {
        s[i++] = tmp[l--];
        j++;
        if(j == 3)
        {
            j = 0;
            s[i++] = ',';
        }
    }
    if(s[i-1] == ',')
        i--;
        
    for(j=i-1;j>=0;j--)
        printf("%c",s[j]);
    printf("\n");
}
/**/
void input()
{
    int i;
    char s[1000];
    
    for(i='a';i<='z';i++)
    {
        d[i-96] = i;
        sprintf(num[i],"%d",i - 96);
    }
    
    while(true)
    {
        scanf("%s",&s);
        if(s[0] == '*')
            break;
        if(s[0] >= 'a' && s[0] <= 'z')
        {
            printf("%-22s",s);
            xuly_char(s);
        }
        else
            xuly_num(s);
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
