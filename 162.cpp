/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <iostream>

#define fi "162.inp"
#define fo "162.out"
/**/
using namespace std;
/**/
stack<int > p1,p2,c;
int card[100];
int icard;
/**/
int getval(char gt)
{
    if(gt == 'A')
        return 4;
    if(gt == 'J')
        return 1;
    if(gt == 'Q')
        return 2;
    if(gt == 'K')
        return 3;
    return 0;
}
/**/
void xuly(char s[])
{
    int i;
    i = 0;
    
    while(s[i])
    {
        if(s[i] != ' ')
        {
            card[icard++] = getval(s[i+1]);
            i++;
        }
        i++;
    }
}
/**/
void solve()
{
    int i,j;
    int tg[100];
    bool player,flg;
    int win,val,gt;
    
    while(!c.empty())
        c.pop();
    
    while(!p1.empty())
        p1.pop();
        
    while(!p2.empty())
        p2.pop();
        
    for(i=0;i<icard;i+=2)
    {
        p1.push(card[i]);
        p2.push(card[i+1]);
    }
    
    player = false;
    win = 0;
    
    while(true)
    {
        
        if(!player)
        {
            if(p1.empty())
            {
                win = 2;
                break;
            }
            val = p1.top();
            c.push(val);
            p1.pop();
        }
        else
        {
            if(p2.empty())
            {
                win = 1;
                break;
            }
            val = p2.top();
            c.push(val);
            p2.pop();
        }
        player = !player;

        if(!val)
            continue;
            
        while(val)
        {
            for(i=0;i<val;i++)
            {
                if(player)
                {
                    if(p2.empty())
                    {
                        win = 1;
                        break;
                    }
                    gt = p2.top();
                    c.push(gt);
                    p2.pop();
                }
                else
                {
                    if(p1.empty())
                    {
                        win = 2;
                        break;
                    }
                    gt = p1.top();
                    c.push(gt);
                    p1.pop();
                }
                
                if(gt)
                    break;
            }
            
            if(win)
                break;
            
            player = !player;
            val = gt;
        }
        
        if(!win)
        {
            if(!player)
            {
                i = 0;
                while(!p1.empty())
                {
                    tg[i++] = p1.top();
                    p1.pop();
                }
                while(!c.empty())
                {
                    p1.push(c.top());
                    c.pop();
                }
                for(j=i-1;j>=0;j--)
                    p1.push(tg[j]);
            }
            else
            {
                i = 0;
                while(!p2.empty())
                {
                    tg[i++] = p2.top();
                    p2.pop();
                }
                while(!c.empty())
                {
                    p2.push(c.top());
                    c.pop();
                }
                for(j=i-1;j>=0;j--)
                    p2.push(tg[j]);
            }
        }
        else
            break;
    }
    
    if(win == 1)
        printf("%d%3d\n",win+1,p1.size());
    else
        printf("%d%3d\n",win-1,p2.size());
}
/**/
void input()
{
    char s[1000];
    while(true)
    {
        icard = 0;       
        s[0] = 0;
        while(s[0] == 0)
            gets(s);
        if(s[0] == '#')
            break;
        while(true)
        {
            xuly(s);
            if(icard == 52)
                break;
            gets(s);
        }
        solve();
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
