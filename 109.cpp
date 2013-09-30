//Le Thanh Hai
//SCUD Busters

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

#define fi "109.inp"
#define fo "109.out"
/**/
int n, nk;

int N[100], M[100];
bool d[100];

struct point
{
    int x, y;
    
    point() {}
    point(int x, int y) : x(x), y(y) {}    
};
class sosanh
{
    public:
        bool operator ()(point &t1, point &t2)
        {
            if (t2.x < t1.x)
                return true;
                
            if (t2.x == t1.x && t2.y < t1.y)
                return true;
                
            return false;   
        };    
};
priority_queue <point, vector <point>, sosanh > pq;
point P[100][500], con[100][500];

///////
int kiemtra(point C, point A, point B)
{
    if ((C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x) < 0)
        return true;
        
    return false;    
}
void xuly(int &na, int &nv, point a[], point v[])
{
    int i, temp;
    
    nv = 0;

    //
    for (i=0; i<na; i++)
    {
        while (nv > 1 && kiemtra(a[i], v[nv-2], v[nv-1]))
            nv--;
            
        v[nv++] = a[i];    
    }      
    
    temp = nv;
    
    for (i=na-2; i>=0; i--)
    {
        while (nv > temp && kiemtra(a[i], v[nv-2], v[nv-1]))
            nv--;
            
        v[nv++] = a[i];    
    }  
}
int check(point xp, point x[], int n)
{
    int i;

    for (i=0; i<n-1; i++)
        if (kiemtra(xp, x[i], x[i+1]) == 1)
            return false;
            
    return true;     
}
double area(point x[], int n)
{
    int i;
    double val;
    
    val = 0;
    
    for (i=1; i<n; i++) 
        val += x[i-1].x * x[i].y - x[i].x * x[i-1].y;
        
    return fabs(val / 2);    
}
void solve()
{
    int i;
    double sum;
    
    sum = 0;
    
    for (i=0; i<nk; i++)
        if (d[i])
            sum += area(con[i], M[i]);  
            
    printf("%.2lf\n", sum);     
}
void input()
{
    int i, x, y;
    
    nk = 0;
    
    while (scanf("%d", &n) == 1)
    {
        if (n == -1)
            break;  
            
        N[nk] = n;
        
        for (i=0; i<n; i++)
        {
            scanf("%d %d", &x, &y);
            
            pq.push(point(x, y));    
        } 
        
        //
        i = 0;
        while (!pq.empty())
        {
            P[nk][i++] = pq.top();
            pq.pop();    
        }
        
        //
        xuly(n, M[nk], P[nk], con[nk]);
        nk++;
    }
    
    while (scanf("%d %d", &x, &y) == 2)
    {
        for (i=0; i<nk; i++)
            if (check(point(x, y), con[i], M[i]) == 1)
                d[i] = true;    
    }
    
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();    
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
