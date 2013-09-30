/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10085.inp"
#define fo "10085.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
struct state{
                char str[10];
                int vt;
            };
            
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
queue<state > q;
state s;
int kc[400000],trc[400000],mov[400000]; // 9 !
map<string, int > mmap;
/**/
void cmov(int val)
{
    if(val == 0)
        printf("U");
    else if(val == 1)
        printf("R");
    else if(val == 2)
        printf("D");
    else
        printf("L");
}
/**/
void out(long id)
{
    int i;
    
    if(!id)
        return;
    
    i = trc[id];
    
    out(i);
    
    cmov(mov[id]);
}
/**/
void solve()
{
    int i,j;
    int x,y;
    int lastvt;
    long dau,cuoi;
    state tmp;
    long maxkc,id;
    
    maxkc = 0;
    mmap.clear();
    mmap[s.str] = 1;
    
    q.push(s);
    
    kc[0] = 0;
    
    dau = -1;
    cuoi = 0;
    
    while(!q.empty())
    {
        dau++;
        tmp = q.front();
        q.pop();
        
        for(i=0;i<4;i++)
        {
            x = tmp.vt / 3 + h[i].x;
            y = tmp.vt % 3 + h[i].y;
            if(x >= 0 && y >= 0 && x < 3 && y < 3)
            {
                lastvt = tmp.vt;
                tmp.vt = x * 3 + y;
                swap(tmp.str[lastvt],tmp.str[tmp.vt]);
                
                if(!mmap[tmp.str])
                {
                    cuoi++;
                    mmap[tmp.str] = 1;
                    mov[cuoi] = i;
                    kc[cuoi] = kc[dau] + 1;
                    if(kc[cuoi] > maxkc)
                    {
                        maxkc = kc[cuoi];
                        s = tmp;
                        id = cuoi;
                    }
                    trc[cuoi] = dau;
                    q.push(tmp);
                }
                swap(tmp.str[lastvt],tmp.str[tmp.vt]);
                tmp.vt = lastvt;
            }
        }
    }
    
    // output
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j)
                printf(" ");
            printf("%c",s.str[i*3+j]);
        }
        printf("\n");
    }
    out(id);
    printf("\n");
}
/**/
void input()
{
    int ntest,id;
    int i;
    int val;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        for(i=0;i<9;i++)
        {
            scanf("%d",&val);
            s.str[i] = (val + 48);
            if(!val)
                s.vt = i;
        }
        s.str[9] = 0;
        printf("Puzzle #%d\n",id++);
        
        solve();
        
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
