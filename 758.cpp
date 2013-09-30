/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "758.inp"
#define fo "758.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
struct sgame{
                int r,c;
                char t;
                int sl;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
toado q[200];
char a[11][20];
bool d[11][20];
sgame m[200];
int maxmove,minball,maxpoint;
/**/
void dropdown(char fst[11][20],char snd[11][20])
{
    int row,col,i,j;
    j = 0;
    for(col=0;col<15;col++)
    {
        i = 9;
        for(row=9;row>=0;row--)
            if(fst[row][col] != '_')
                snd[i--][j] = fst[row][col];
        
        if(i != 9)
        {
            while(i>=0)
            {
                snd[i][j] = '_';
                i--;
            }
            j++;
        }
    }
    
    for(col=j;col<15;col++)
        for(row=9;row>=0;row--)
            snd[row][col] = '_';
}
/**/
void resetd()
{
    int i,j;
    for(j=0;j<15;j++)
        for(i=9;i>=0;i--)
        {
            if(a[i][j] == '_')
                break;
            d[i][j] = true;
        }
}
/**/
int loang(int row,int col)
{
    int i;
    int dau,cuoi;
    int x,y;
    
    dau = -1;
    cuoi = 0;
    q[0].x = row;
    q[0].y = col;
    d[row][col] = false;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            x = q[dau].x + h[i].x;
            y = q[dau].y + h[i].y;
            if(x >= 0 && y >= 0 && x < 10 && y < 15)
                if(a[x][y] == a[row][col] && d[x][y])
                {
                    cuoi++;
                    q[cuoi].x = x;
                    q[cuoi].y = y;
                    d[x][y] = false;
                }
        }
    }
    return cuoi+1;
}
/**/
void clearball(int r,int c)
{
    int i;
    int dau,cuoi;
    char kt;    
    int x,y;
    
    dau = -1;
    cuoi = 0;
    q[0].x = r;
    q[0].y = c;
    kt = a[r][c];
    a[r][c] = '_';
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            x = q[dau].x + h[i].x;
            y = q[dau].y + h[i].y;
            if(x >= 0 && y >= 0 && x < 10 && y < 15)
                if(a[x][y] == kt)
                {
                    cuoi++;
                    q[cuoi].x = x;
                    q[cuoi].y = y;
                    a[x][y] = '_';
                }
        }
    }
}
/**/
void solve()
{
    int row,col,x,y;
    int tmp;
    bool tuongdoitot;
    
    minball = 150;
    maxmove = 0;
    while(true)
    {
        resetd();
        maxpoint = 0; 
        tuongdoitot = false;  
        for(col=0;col<15;col++)
        {
            for(row=9;row>=0;row--)
            {
                if(a[row][col] == '_')
                    break;
                if(d[row][col])
                {
                    tmp = loang(row,col);
                    if(tmp > maxpoint)
                    {
                        maxpoint = tmp;
                        x = row;
                        y = col;
                        // cat
                        if(maxpoint > minball / 2)       
                        {
                            tuongdoitot = true;
                            break;
                        }
                    }
                }
            }
            if(tuongdoitot)
                break;
        }
        if(maxpoint < 2)        
            break;
        m[maxmove].t = a[x][y];
        
        clearball(x,y);
        minball -= maxpoint;
        m[maxmove].r = 9-x+1;
        m[maxmove].c = y+1;
        m[maxmove].sl = maxpoint;
        maxmove++;
        dropdown(a,a);
    }
}
/**/
void output(int id)
{
    int i;
    int tmp,sum;
    printf("Game %d:\n\n",id);
    
    if(minball == 150)
        printf("Final score: 0, with 150 balls remaining.\n");
    else
    {
        sum = 0;
        if(!minball)
            sum += 1000;
            
        for(i=0;i<maxmove;i++)
        {
            tmp = (m[i].sl-2) * (m[i].sl-2);
            sum += tmp;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",i+1,m[i].r,m[i].c,m[i].sl,m[i].t,tmp);
        }
        printf("Final score: %d, with %d balls remaining.\n",sum,minball);
    }
}
/**/
void input()
{
    int i;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        for(i=0;i<10;i++)
            scanf("%s",&a[i]);
        solve();
        output(id++);
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
