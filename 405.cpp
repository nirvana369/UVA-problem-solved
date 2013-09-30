//Le Thanh Hai
//Message Routing

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

#define fi "405.inp"
#define fo "405.out"
/**/
int itest;
int n, m;

char dt[10][200];

struct arr
{
    int n, d;
    char name[200];
    char data[20][10][200];        
};
arr a[20];

///////
int find_vt(char x[])
{
    int i;
    
    for (i=0; i<n; i++)
        if (!strcmp(x, a[i].name))
            return i;
            
    return -1;   
}
void solve()
{
    int i, j, vt, vt2;
    bool flag;
    
    vt = find_vt(dt[0]);    
    
    if (vt == -1)
    {
        printf("unable to route at %s\n", dt[0]);  
        return; 
    }
    
    for (i=0; i<n; i++)
        a[i].d = 0;
        
    while (true)
    {
        if (a[vt].d > 0)
        {
            printf("circular routing detected by %s\n", a[vt].name); 
            return;   
        }   
        
        a[vt].d++;
        
        //
        for (i=0; i<a[vt].n; i++)
        {
            flag = false;
            
            for (j=1; j<=4; j++)
                if (strcmp(a[vt].data[i][j], "*") != 0 && strcmp(a[vt].data[i][j], dt[j]) != 0)
                {
                    flag = true;
                    break;
                }
                    
            if (!flag)
                break;
        }
        
        if (i >= a[vt].n)
        {
            printf("unable to route at %s\n", a[vt].name);   
            return;    
        }
        
        //
        vt2 = find_vt(a[vt].data[i][0]);
        
        if (vt2 == -1)
        {
            printf("unable to route at %s\n", a[vt].name);   
            return;    
        }
        
        if (vt2 == vt)
        {
            printf("delivered to %s\n", a[vt].name);  
            return; 
        }
        
        vt = vt2;
    }
}
void input()
{
    int i, j, k;
    
    itest = 1;
    
    while (scanf("%d", &n) == 1)
    {
        for (i=0; i<n; i++)
        {
            scanf("%s %d", &a[i].name, &a[i].n);
            
            for (j=0; j<a[i].n; j++)
                for (k=0; k<5; k++)
                    scanf("%s", &a[i].data[j][k]);    
        } 
        
        printf("Scenario # %d\n", itest++);
        
        //
        scanf("%d", &m);
        
        for (i=1; i<=m; i++)
        {
            for (j=0; j<5; j++)
                scanf("%s", &dt[j]);   
            
            printf("%d -- ", i);
            
            //    
            solve();
        } 
        
        printf("\n");
    }  
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
