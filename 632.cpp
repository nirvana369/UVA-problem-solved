/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "632.inp"
#define fo "632.out"
/**/
using namespace std;
/**/
priority_queue<string, vector<string>, greater<string> > pq;
char a[2000][2000];
int len,l;
/**/
void xuly()
{
    int i,j;
    string str,kq,scmp;
    
    for(i=1;i<len;i++)
    {
        for(j=0;j<len-1;j++)
            a[i][j] = a[i-1][j+1];
        a[i][j] = a[i-1][0];
        a[i][len] = 0;
        if(i == 1)
            scmp = a[i];
    }
    
    while(!pq.empty())
        pq.pop();
    
    for(i=0;i<len;i++)
        pq.push(a[i]);
    
    kq = "";
    i = 0;
    j = -1;
    while(!pq.empty())
    {
        str = pq.top();
        pq.pop();
        kq += str[str.size()-1];        
        if(j == -1)
            if(str.compare(scmp) == 0)
                j = i;
        i++;
    }
    if(j == -1)
        j = 0;
        
    cout << j << endl;
    
    i = 0;
    while(i < l)
    {
        j = 0;
        while(j < 50 && i < l)
        {
            cout << kq[i++];
            j++;
        }
        printf("\n");
    }
}
/**/
void noichuoi(char s[])
{
    int i;
    i = 0;
    while(l < len && s[i])
        a[0][l++] = s[i++];
}
/**/
void input()
{
    char s[100];
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&len);
        gets(s);
        l = 0;
        while(l < len)
        {
            gets(s);
            noichuoi(s);
        }
        a[0][l] = 0;
        xuly();
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
