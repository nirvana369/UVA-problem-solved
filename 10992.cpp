/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10992.inp"
#define fo "10992.out"
/**/
using namespace std;
/**/
int len,noghost;
char y[100],ghost[6];
/**/
bool divghost(char s[],int num,int l)
{
    int i;
    int val;
    
    i = l-1;
    val = 0;
    while(i >= 0)
    {
        val *= 10;
        val += (s[i] - 48);
        if(val >= num)
            val = val % num;
        i--;
    }
    if(val == 0)
        return true;
    return false;
}
/**/
void daochuoi(char s[])
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
int subt(char s1[],int len1,char s2[],int len2)
{
    int arr[100];
    int i,j;
    
    for(i=len1;i>=0;i--)
        arr[i] = 0;
    
    for(i=0;i<len1;i++)
    {
        if(i < len2)
        {
            arr[i] += (s1[i] - 48) - (s2[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] += 10;
                arr[i+1]--;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] += 10;
                arr[i+1]--;
            }
        }
    }
    
    for(i=len1;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
                
            s1[i+1] = 0;
            return i+1;
        }
    s1[0] = '0';
    s1[1] = 0;
    return 1;
}
/**/
void solve()
{
    bool gcome;
    int lens;
    char s[100];
    
    gcome = false;
    if(noghost >= 2148)
    {
        strcpy(s,y);
        lens = len;
        len = subt(y,len,ghost,4);
        
        if((y[0] - 48) % 2 == 0)
        {
            printf("Ghost of Tanveer Ahsan!!!\n");
            gcome = true;
        }
    
        if(y[0] == '0' || y[0] == '5')
        {
            printf("Ghost of Shahriar Manzoor!!!\n");
            gcome = true;
        }
    
        if(divghost(y,7,len))
        {
            printf("Ghost of Adrian Kugel!!!\n");
            gcome = true;
        }
    
        if(divghost(y,11,len))
        {
            printf("Ghost of Anton Maydell!!!\n");
            gcome = true;
        }
    
        if(divghost(y,15,len))
        {
            printf("Ghost of Derek Kisman!!!\n");
            gcome = true;
        }
    
        if(divghost(y,20,len))
        {
            printf("Ghost of Rezaul Alam Chowdhury!!!\n");
            gcome = true;
        }
    
        if(divghost(y,28,len))
        {
            printf("Ghost of Jimmy Mardell!!!\n");
            gcome = true;
        }
    
        if(divghost(y,36,len))
        {
            printf("Ghost of Monirul Hasan!!!\n");
            gcome = true;
        }
            
        if(divghost(s,400,lens) || noghost == 2148)
        {
            printf("Ghost of K. M. Iftekhar!!!\n");
            gcome = true;
        }
        else if(!(s[0] == '0' && s[1] == '0'))
            if(divghost(s,4,lens))
            {
                printf("Ghost of K. M. Iftekhar!!!\n");
                gcome = true;
            }
    }
    
    if(!gcome)
        printf("No ghost will come in this year\n");
}
/**/
void input()
{
    int id;
    
    id = 0;
    strcpy(ghost,"8412");
    while(true)
    {
        scanf("%s",&y);
        len = strlen(y);
        if(len == 1 && y[0] == '0')
            break;
        if(id++)
            printf("\n");
            
        if(len == 4)
            sscanf(y,"%d",&noghost);
        else if(len < 4)
            noghost = 0;
        else
            noghost = 10000;
            
        printf("%s\n",y);
        daochuoi(y);
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
