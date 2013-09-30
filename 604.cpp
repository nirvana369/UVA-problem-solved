/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "604.inp"
#define fo "604.out"
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
                
char a[7][7],b[7][7],kq[5];
bool d[7][7];
int va[7][7],vb[7][7];
map<string,int > mmap;

bool chkvw(char s)
{
    if(s == 'A' || s == 'E' || s == 'O' || s == 'U' || s == 'I' || s == 'Y')
        return true;
    return false;
}
/**/
bool xuly(int hang, char s[])
{
    int i;
    int cot;
    
    i = 0;
    cot = 1;
    while(s[i])
    {
        if(s[i] != ' ')
        {
            if(s[i] == '#')
                return true;
            else
            {
                a[hang][cot] = s[i];
                if(chkvw(s[i]))
                    va[hang][cot] = 1;
                else
                    va[hang][cot] = 0;
                cot++;
            }
        }
        i++;
        if(cot == 5)
            break;
    }
    
    cot = 1;
    while(s[i])
    {
        if(s[i] != ' ')
        {
            if(s[i] == '#')
                return true;
            else
            {
                b[hang][cot] = s[i];
                if(chkvw(s[i]))
                    vb[hang][cot] = 1;
                else
                    vb[hang][cot] = 0;
                cot++;
            }
        }
        i++;
    }
    return false;
}
/**/
void dqa(int r,int c,int vw,int id)
{
    int i;
    int px,py;
        
    if(id == 4)
    {
        if(vw != 2)
            return;
        kq[id] = 0;
        mmap[kq] = 1;
        return;
    }
    
    for(i=0;i<8;i++)
    {
        px = r + h[i].x;
        py = c + h[i].y;
        if(px > 0 && px < 5 && py > 0 && py < 5)
            if(d[px][py])
            {
                kq[id] = a[px][py];
                d[px][py] = false;
                
                if(va[px][py])
                    dqa(px,py,vw+1,id+1);    
                else
                    dqa(px,py,vw,id+1);    
                    
                d[px][py] = true;
            }
    }
}
/**/
void dqb(int r,int c,int vw,int id)
{
    int i;
    int px,py;
        
    if(id == 4)
    {
        if(vw != 2)
            return;
        kq[id] = 0;
        if(mmap[kq])
            mmap[kq] = 2;
        return;
    }
    
    for(i=0;i<8;i++)
    {
        px = r + h[i].x;
        py = c + h[i].y;
        if(px > 0 && px < 5 && py > 0 && py < 5)
            if(d[px][py])
            {
                kq[id] = b[px][py];
                d[px][py] = false;
                
                if(vb[px][py])
                    dqb(px,py,vw+1,id+1);    
                else
                    dqb(px,py,vw,id+1);    
                    
                d[px][py] = true;
            }
    }
}
/**/
void _initd()
{
    int i,j;
    for(i=1;i<5;i++)
        for(j=1;j<5;j++)
            d[i][j] = true;
}
/**/
void solve()
{
    int i,j;
    bool tontai;
    
    mmap.clear();
    _initd();
    
    for(i=1;i<5;i++)
        for(j=1;j<5;j++)
        {
            kq[0] = a[i][j];
            d[i][j] = false;
            if(va[i][j])
                dqa(i,j,1,1);
            else
                dqa(i,j,0,1);
            d[i][j] = true;
        }
    
    for(i=1;i<5;i++)
        for(j=1;j<5;j++)
        {
            kq[0] = b[i][j];
            d[i][j] = false;
            if(vb[i][j])
                dqb(i,j,1,1);
            else
                dqb(i,j,0,1);
            d[i][j] = true;
        }
    
    map<string, int >::iterator k;
    tontai = false;
    for(k=mmap.begin();k!=mmap.end();k++)
        if(k->second == 2)
        {
            tontai = true;
            cout << k -> first << endl;
        }
        
    if(!tontai)
        cout << "There are no common words for this pair of boggle boards." << endl;
}
/**/
void input()
{
    int i;
    char s[100];
    int id;
    id = 0;
    while(true)
    {
        for(i=1;i<5;i++)
        {
            gets(s);
            if(xuly(i,s))
                return;
        }
        gets(s);
        if(id)
            printf("\n");
        solve();      
        id++;  
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
