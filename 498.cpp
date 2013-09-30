/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "498.inp"
#define fo "498.out"
/**/
using namespace std;
/**/
void xuly(vector<int> &x,char s[])
{
    int i;
    int dem,val;
    char tmp[100];
    
    x.clear();
    i = dem = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            sscanf(tmp,"%d",&val);
            x.push_back(val);
            dem = 0;
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        sscanf(tmp,"%d",&val);
        x.push_back(val);
        dem = 0;
    }
}
/**/
void input()
{
    char s[10000];
    int i,j;
    int val;
    vector<int > a,b;
    
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(!s[0])
            break;
        xuly(a,s);

        gets(s);
        xuly(b,s);

        for(i=0;i<b.size();i++)
        {
            val = a[0];
            for(j=1;j<a.size();j++)
            {
                val *= b[i];
                val += a[j];
            }
            if(i)
                printf(" ");
            printf("%d",val);
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
