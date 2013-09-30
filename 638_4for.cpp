/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "638.inp"
#define fo "638.out"
/**/
using namespace std;
/**/
priority_queue<string, vector<string>, greater<string> > pq;
int n;
char a[60][60];
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=51;i++)
    {
        for(j=0;j<=51;j++)
            a[i][j] = 0;
    }
    
    while(!pq.empty())
        pq.pop();
}
/**/
void solve(int id)
{
    int i,j;
    int h,c;
    char tmp[5];
    int dem;
    
    for(i=51;i>=0;i--)
    {
        for(j=0;j<=51;j++)
            if(a[i][j] != 0)
            {
                for(c=j+1;c<=51;c++)
                    for(h=i-1;h>=0;h--)
                        if(a[i][c] != 0 && a[h][j] != 0 && a[h][c] != 0)
                        {
                            dem = 0;
                            tmp[dem++] = a[i][j];
                            tmp[dem++] = a[i][c];
                            tmp[dem++] = a[h][c];
                            tmp[dem++] = a[h][j];
                            tmp[dem] = 0;
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
            a[hang][cot] = s[0];
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
