/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "220.inp"
#define fo "220.out"
/**/
using namespace std;
/**/
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
char a[10][10];
vector<toado > p[3];
char cur;
int cblack,cwhite;
int row,col;
/**/
void changep()
{
    if(cur == 'B')
        cur = 'W';
    else
        cur = 'B';
}
/**/
void pmove()
{
    int i;
    if(cur == 'W')
    {
        if(!p[0].size())
            printf("No legal move.");
            
        for(i=0;i<p[0].size();i++)
        {
            if(i)
                printf(" ");
            printf("(%d,%d)",p[0][i].x+1,p[0][i].y+1);
        }
        printf("\n");
    }
    else
    {
        if(!p[1].size())
            printf("No legal move.");
            
        for(i=0;i<p[1].size();i++)
        {
            if(i)
                printf(" ");
            printf("(%d,%d)",p[1][i].x+1,p[1][i].y+1);
        }
        printf("\n");
    }
}
/**/
int isplayer()
{
    return (cur == 'W' ? 0 : 1);
}
/**/
bool chk(int r,int c)
{
    if(r >= 0 && c >= 0 && r < 8 && c < 8)
        return true;
    return false;
}
/**/
void eat(int dir,int px,int py)
{
    int i;
    int x,y;
    
    x = row + h[dir].x;
    y = col + h[dir].y;
    
    while(1)
    {
        if(a[x][y] == '-' || a[x][y] == cur)
            return;
        x += h[dir].x;
        y += h[dir].y;
        if(x == px && y == py)
            break;
    }
    // change
    x = row + h[dir].x;
    y = col + h[dir].y;
    
    while(1)
    {
        a[x][y] = cur;
        x += h[dir].x;
        y += h[dir].y;
        if(x == px && y == py)
            return;
    }
}
/**/
void change_state()
{
    int x,y;
    int dir;
    
    a[row][col] = cur;
    
    for(dir=0;dir<8;dir++)
    {
        x = row + 2 * h[dir].x;
        y = col + 2 * h[dir].y;
        while(chk(x,y))
        {
            if(a[x][y] == cur)
            {
                eat(dir,x,y);
                break;
            }
            x += h[dir].x;
            y += h[dir].y;
        }
    }
}
/**/
void fmove()
{
    int i,j,dir;
    int x,y;
    toado t;
    int id;
    bool findmove;
    
    id = isplayer();
    
    p[id].clear();
    
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(a[i][j] == '-')
            {
                for(dir=0;dir<8;dir++)
                {
                    findmove = false;
                    t.x = i + 2 * h[dir].x;
                    t.y = j + 2 * h[dir].y;
                    
                    while(chk(t.x,t.y))
                    {
                        if(a[t.x][t.y] == cur)
                        {
                            x = i + h[dir].x;
                            y = j + h[dir].y;
                            while(1)
                            {
                                if(a[x][y] == '-' || a[x][y] == cur)
                                    break;
                                if(x == t.x && y == t.y)
                                    break;
                                x += h[dir].x;
                                y += h[dir].y;
                            }
                            if(x == t.x && y == t.y)
                            {
                                t.x = i;
                                t.y = j;
                                p[id].push_back(t);
                                findmove = true;
                            }
                            break;
                        }
                        t.x += h[dir].x;
                        t.y += h[dir].y;
                    }
                    if(findmove)
                        break;
                }
            }
}
/**/
void solve()
{
    int i,j;
    int id;
    
    
    id = isplayer();
    if(!p[id].size())
        changep();

    change_state();
    
    cblack = cwhite = 0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(a[i][j] == 'B')
                cblack++;
            else if(a[i][j] == 'W')
                cwhite++;
                
    changep();
    
    printf("Black - %2d White - %2d\n",cblack,cwhite);
}
/**/
void input()
{
    int ntest;
    int i;
    char s[10];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        for(i=0;i<8;i++)
            scanf("%s",&a[i]);
        scanf("%s",&s);
        cur = s[0];
        
        while(true)
        {
            scanf("%s",&s);
            if(s[0] == 'Q')
            {
                for(i=0;i<8;i++)
                    printf("%s\n",a[i]);
                break;
            }
            else if(s[0] == 'L')   
            {
                fmove(); 
                pmove();
            }
            else if(s[0] == 'M')
            {
                row = s[1]-49;
                col = s[2]-49;
                solve();
            }
        }
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
