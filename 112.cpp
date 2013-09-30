/*
                                        Hoang Linh
                                        
                            Problem: TREE SUMMING 4.5 (treesum.*) 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "112.inp"
#define fo "112.out"
///////////////////////
using namespace std;
/**/
char chuoigoc[5000];
/**/
int arr[5000];
int bac,stop;
long tong;
bool dung,gapngoac;
/**/
void khoitao()
{
    int i;
    for(i=0;i<5000;i++)
        arr[i] = 0;
    chuoigoc[0] = ' ';
    chuoigoc[1] = 0;
    dung = false;
    gapngoac = false;
}
/**/
void output()
{
    if(dung)
        printf("yes\n");
    else
        printf("no\n");
}
/**/
bool kiemtra(int vitri)
{
    if(chuoigoc[vitri+1] == ')' && chuoigoc[vitri+2] == '(' && chuoigoc[vitri+3] == ')')
        return true;
    return false;
}
/**/
void solve(char s[])
{
    int i,j;
    int l,dem;
    int value,sum;
    char temp[5000];
    
    bac = 0;
    dem = 0;
    l = strlen(s);
    temp[dem] = 0;
    for(i=0;i<l;i++)
    {
        if(s[i] == '(')
        {
            bac++;
            
            temp[dem] = 0;
            
            if(temp[0] != 0)
            {
                sscanf(temp,"%d",&value);
                arr[bac] = value;
                
                if(kiemtra(i))
                {
                    sum = 0;
                    for(j=bac;j>1;j--)    
                    {
                        //printf("%d ",arr[j]);
                        sum = sum + arr[j];
                    }
                    //printf("%d\n",sum);
                    if(sum == tong)
                        dung = true;
                }
            }
            dem = 0;
            temp[dem] = 0;
        }
        else if(s[i] == ')')
            bac--;
        else
        {
            temp[dem] = s[i];
            dem++;
        }
    }
    
    output();
    stop = 0;
}
/**/
void noichuoi(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == '(')
        {
            gapngoac = true;
            bac++;
        }
        if(s[i] == ')')
            bac--;
    }
    strcat(chuoigoc,s);
}
/**/
void spacecut()
{
    int i;
    int l,dem;
    char temp[10000];
    l = strlen(chuoigoc);
    dem = 0;
    for(i=0;i<l;i++)
        if(chuoigoc[i] != ' ')
        {
            temp[dem] = chuoigoc[i];
            dem++;
        }
    temp[dem] = 0;
    strcpy(chuoigoc,temp);
}
/**/
void input()
{
    bac = 0;
    char temp[5000];
    while(!feof(stdin))
    {
        if(bac == 0)
        {
            temp[0] = 0;
            scanf("%s",&temp);
            if(temp[0] == 0)
                break;
            sscanf(temp,"%ld",&tong);
            khoitao();
            stop = 1;
        }
        while(stop == 1)
        {
            gets(temp);
            noichuoi(temp);
            if(bac == 0 && gapngoac)
            {
                spacecut();
                solve(chuoigoc);
                //printf("%s\n",chuoigoc);
            }
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
