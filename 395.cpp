/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "395.inp"
#define fo "395.out"
/**/
using namespace std;
/**/
struct vt{
            int r1,c1,r2,c2;
            };
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
class sosanh{
public:
    bool operator()(vt t1,vt t2)    
    {
        if(t1.r1 > t2.r1)
            return true;
        if(t1.r1 == t2.r1)
        {
            if(t1.c1 > t2.c1)
                return true;
            if(t1.c1 == t2.c1)
            {
                if(t1.r2 > t2.r2)
                    return true;
                if(t1.r2 == t2.r2)
                    if(t1.c2 > t2.c2)
                        return true;
            }
        }
        return false;
    }
};
priority_queue<vt, vector<vt> , sosanh > pq;
char a[10][10];
/**/
bool chk(int r,int c)
{
    if(r < 0 || c < 0 || r > 7 || c > 7)
        return false;
    return true;
}
/**/
void solve(int r,int c)
{
    int i,j;
    int x,y;
    vt t;
    int dem;
    
    t.r1 = r;
    t.c1 = c;
    if(r == 4 && c == 1)
    {
        r = 4;
    }
    for(i=0;i<8;i++)
    {
        dem = 1;
        
        x = r + h[i].x;    
        y = c + h[i].y;
        
        while(chk(x,y))
        {
            if(a[x][y] != '.')
                dem++;
            x += h[i].x;    
            y += h[i].y;
        }
        
        x = r - h[i].x;    
        y = c - h[i].y;
        
        while(chk(x,y))
        {
            if(a[x][y] != '.')
                dem++;
            x -= h[i].x;    
            y -= h[i].y;
        }
        
        x = r + dem * h[i].x;
        y = c + dem * h[i].y;
        
        if(chk(x,y) && a[x][y] != a[r][c])
        {
            x = r;
            y = c;
            for(j=0;j<dem;j++)
            {
                x += h[i].x;
                y += h[i].y;

                if(a[x][y] != '.' && a[x][y] != a[r][c])
                {
                    j++;
                    break;
                }
            }
            if(j == dem)
            {
                t.r2 = x;
                t.c2 = y;
                pq.push(t);          
            }
        }
    }
}
/**/
void output()
{
    vt t;
    
    if(pq.empty())
        printf("No moves are possible\n");
    else
    {
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();
            printf("%c%d-%c%d\n",t.r1+65,t.c1+1,t.r2+65,t.c2+1);
        }
    }
}
/**/
void input()
{
    char s[3];
    int i,j;
    int id;
    
    id = 0;
    while(true)
    {
        i = 0;
        while(scanf("%s",&a[i]) == 1)
        {
            i++;
            if(i == 8)
                break;
        }
            
        if(i != 8)
            break;
            
        if(id++)
            printf("\n");
            
        scanf("%s",&s);
        
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                if(a[i][j] == s[0])
                    solve(i,j);
        }
        output();
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
