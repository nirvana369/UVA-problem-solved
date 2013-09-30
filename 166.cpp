//Le Thanh Hai
//Making Change

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <map>
#include <queue>

using namespace std;

#define fi "166.inp"
#define fo "166.out"
#define maxx 10000
/**/
int na, nb;
int pay, kq;

int a[100000], b[10];
int da[1000], db[1000];

///////
int convert(int xp)
{
    if (xp == 1)
        return 5;
    else if (xp == 2)
        return 10;
    else if (xp == 3)
        return 20;
    else if (xp == 4)
        return 50;
    else if (xp == 5)
        return 100;
    else if (xp == 6)
        return 200;    
}
void init()
{
    int i, j, maxval;
    
    nb = 0;
    
    for (i=1; i<=6; i++)
        b[nb++] = convert(i);
    
    for (i=0; i<=500; i++)
        db[i] = maxx;
            
    maxval = 0;
    db[0] = 0;
      
    for (i=0; i<nb; i++)
        for (j=0; j<=maxval; j++)
            if (db[j] != maxx && b[i] + j <= 500)
            {
                db[b[i]+j] = min(db[b[i]+j], db[j] + 1);
                maxval = max(maxval, b[i]+j);        
            }
}

void xuly(int x[])
{
    int i, j;
    
    na = 0;
    
    for (i=1; i<=6; i++)
        for (j=0; j<x[i]; j++)
            a[na++] = convert(i);
}
void solve()
{
    int i, j, maxval;
    
    for (i=0; i<=500; i++)
        da[i] = maxx;
    
    //  
    maxval = 0;
    da[0] = 0;
      
    for (i=0; i<na; i++)
        for (j=maxval; j>=0; j--)
            if (da[j] != maxx && a[i] + j <= 500)
            {
                da[a[i]+j] = min(da[a[i]+j], da[j] + 1);
                maxval = max(maxval, a[i]+j);        
            }  
   
    //
    kq = maxx;
                    
    for (i=pay; i<=500; i++)
        kq = min(kq, da[i] + db[i-pay]);
        
    printf("%3d\n", kq);
}
void chuyen(char x[])
{
    int i, dem;
    int t[10];
    
    for (i=0; i<4; i++)
        t[i] = 0; 
    
    dem = 0;
    
    for (i=0; i<strlen(x); i++)
        if (x[i] != '.')
            t[dem++] = (x[i]-48);
            
    pay = 0;
    
    for (i=0; i<3; i++)
        pay = pay*10 + t[i];
}
void input()
{
    int i;
    double x;
    bool stop;
    int t[10];
    char s[10];
    
    while (scanf("%d %d %d %d %d %d", &t[1], &t[2], &t[3], &t[4], &t[5], &t[6]) == 6)
    {
        stop = true;
        
        for (i=1; i<=6; i++)
            if (t[i] != 0)
            {
                stop = false;
                break;    
            }    
            
        if (stop)
            break;
        
        scanf("%s", &s);
        
        chuyen(s);
        
        xuly(t);   
        solve();
    }   
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    init();
    input();    
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
