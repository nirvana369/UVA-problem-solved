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

#define fi "450.inp"
#define fo "450.out"
/**/
using namespace std;
/**/
struct information{
                    char info[8][100];
                    string s;
                 };
                 
class sapxep{
public:
    bool operator()(information a,information b)   
    {
        if(a.s.compare(b.s) > 0)
            return true;
        return false;
    }
};
priority_queue <information, vector <information>, sapxep > pq;
char name[100];
/**/
void xuly(char s[])
{
    int i,id;
    information temp;
    int l,dem,len;
    l = strlen(s);
    s[l] = ',';
    id = 0;
    dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] == ',')
        {
            temp.info[id][dem] = 0;
            if(id == 2)
                len = dem;
            id++;
            dem = 0;
        }
        else
            temp.info[id][dem++] = s[i];
    temp.s = "";
    for(i=0;i<len;i++)
        temp.s += temp.info[2][i];
    strcpy(temp.info[2],name);
    pq.push(temp);
}
/**/
void output()
{
    information p;
    while(!pq.empty())
    {
        printf("----------------------------------------\n");
        p = pq.top();
        pq.pop();
        printf("%s %s ",p.info[0],p.info[1]);
        cout << p.s << endl;
        printf("%s\nDepartment: %s\nHome Phone: %s\nWork Phone: %s\nCampus Box: %s\n",p.info[3],p.info[2],p.info[4],p.info[5],p.info[6]);
    }
}
void input()
{
    char temp[1000];
    int n;
    scanf("%d",&n);
    gets(name);
    while(!pq.empty())
        pq.pop();
    while(n--)
    {
        gets(name);
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            xuly(temp);
        }
    }
    output();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
