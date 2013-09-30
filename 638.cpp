/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iostream>

#define fi "638.inp"
#define fo "638.out"
/**/
using namespace std;
/**/
struct toado{
                int h,c;
            };
toado vt[30];
priority_queue<string, vector<string>, greater<string> > pq;
vector<int > x[52],y[52];
bool d[30];
char kt[60][60];
int n;
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=26;i++)
        d[i] = false;
    for(i=0;i<=51;i++)
    {
        for(j=0;j<=51;j++)
            kt[i][j] = 0;
        x[i].clear();
        y[i].clear();
    }
}
/**/
bool khac(char s[])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
            if(s[i] == s[j] || vt[s[j]-65].h > vt[s[i]-65].h)
                return false;
    if(vt[s[1]-65].c < vt[s[0]-65].c || vt[s[2]-65].c < vt[s[3]-65].c)
        return false;
        
    return true;
}
/**/
void solve(int id)
{
    int i,j,k;
    int hang,cot,row,col;
    char tmp[5];
    int dem;
    
    while(!pq.empty())
        pq.pop();
        
    for(i=0;i<=26;i++)
        if(d[i])
        {
            hang = vt[i].h;
            cot = vt[i].c;
            for(j=0;j<x[hang].size();j++)
                for(k=0;k<y[cot].size();k++)
                {
                    col = vt[x[hang][j]].c;
                    row = vt[y[cot][k]].h;
                    if(kt[row][col] != 0)
                    {
                        dem = 0;
                        tmp[dem++] = i+65;
                        tmp[dem++] = x[hang][j]+65;
                        tmp[dem++] = kt[row][col];
                        tmp[dem++] = y[cot][k]+65;
                        tmp[dem] = 0;
                        if(khac(tmp))
                            pq.push(tmp);
                    }
                }
        }
    if(pq.empty())
        printf("Point set %d: No rectangles\n",id);
    else
    {
        printf("Point set %d:\n",id);
        i = 0;
        while(!pq.empty())
        {
            if(i == 10)
            {
                cout << endl;
                i = 0;
            }
            cout << " " << pq.top();
            pq.pop();
            i++;
        }
        printf("\n");
    }
}
/**/
void input()
{
    int i;
    char s[3];
    int hang,cot;
    int id;
    
    id = 1;
    while(scanf("%d",&n) && n)
    {
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d",&s,&cot,&hang);
            d[s[0]-65] = true; // ton tai chu cai do
            vt[s[0]-65].h = hang; // luu toa do chu cai
            vt[s[0]-65].c = cot;    
            kt[hang][cot] = s[0]; // vi tri do co ky tu s;
            x[hang].push_back(s[0]-65); // luu ky tu hang
            y[cot].push_back(s[0]-65); // luu ky tu cot
        }
        solve(id++);
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
