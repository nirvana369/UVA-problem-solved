//Le Thanh Hai
//Processing MX Records  

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define fi "335.inp"
#define fo "335.out"
/**/
int n;

struct arr
{
    int priority;
    string wildcard, machine;    
};
vector <arr> a;
map <string, bool> d;

///////
vector <string> xuly(char x[])
{
    vector <string> t;
    char *p;

    p = strtok(x, " ");
    
    while (p != NULL)
    {
        t.push_back(p);

        p = strtok(NULL, " ");    
    }

    return t;
}
bool sosanh(arr t1, arr t2)
{
    if (t1.priority < t2.priority)
        return true;
        
    return false;
}
int kiemtra(string x, string y)
{
    int lx, ly, vt;
    
    lx = x.size();
    ly = y.size();  
    vt = 0;
    
    while (x[lx - vt] != '*')
    {
        if (x[lx - vt] != y[ly - vt])
            return false;
            
        vt++;    
    }
    
    return true;
}
void output(string x)
{
    int i;
    
    cout << x << " =>";
    
    //
    for (i=0; i<a.size(); i++)
        if (a[i].wildcard == x)
        {
            if (d[a[i].machine] == false)
                continue;
                
            cout << " " << a[i].machine << endl;
            return;    
        } 
        else if (a[i].wildcard[0] == '*')
        {
            if (d[a[i].machine] == false)
                continue;
                
            if (kiemtra(a[i].wildcard, x) == 1)
            {
                cout << " " << a[i].machine << endl;
                return;    
            }
        } 
        
    cout << endl;  
}
void solve(char com, string x)
{
    if (com == 'A')
        output(x);
    else if (com == 'D')
        d[x] = false;
    else if (com == 'U')
        d[x] = true;         
}
void input()
{
    int i;
    char s[1000], com[10];
    string prev, machine;
    vector <string> t;
    arr temp;
    
    //
    scanf("%d", &n);
    gets(s);
    
    for (i=0; i<n; i++)
    {
        gets(s);
        
        t = xuly(s);  
        
        if (t.size() == 2)
        {
            temp.wildcard = prev;
            temp.priority = atoi(t[0].c_str());
            temp.machine = t[1];    
        }
        else
        {
            prev = t[0];
            temp.wildcard = t[0];
            temp.priority = atoi(t[1].c_str());
            temp.machine = t[2];    
        }
        
        a.push_back(temp);
    }   
    
    sort(a.begin(), a.end(), sosanh);
    
    //
    for (i=0; i<a.size(); i++)
        d[a[i].machine] = true;
        
    while (scanf("%s", &com) == 1)
    {
        if (!strcmp(com, "X"))
            break;
            
        cin >> machine;
        
        solve(com[0], machine);    
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
