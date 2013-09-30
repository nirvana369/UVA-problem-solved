#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <map>
#include <math.h>

#define fi "a.inp"
#define fo "a.out"

using namespace std;
/////////////
struct word{
            long vt,gt;
            };

class sosanh{
public:
    bool operator()(word x,word y)
    {
        if(x.gt > y.gt)
            return true;
        else if(x.gt == y.gt)
            if(x.vt > y.vt)
                return true;
        return false;
    }
};
word a[100010];
map <string, long> mmap;
priority_queue <word, vector <word>, sosanh > pq;

long d[100010],fix[1000010];
long da;
long vitri,id,bd,kt;
char s[1000000];
void xuly()
{
    int i;
    int l,dem;
    char temp[1000];
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            temp[dem++] = s[i];
        else
        {
            temp[dem] = 0;
            if(dem != 0)
            {
                if(mmap[temp] == 0)
                {
                    mmap[temp] = id;
                    a[da].vt = vitri;
                    a[da].gt = id;
                    id++;
                }
                else
                {
                    a[da].vt = vitri;
                    a[da].gt = mmap[temp];
                }
                pq.push(a[da]);
                da++;
                fix[da] = mmap[temp];
                vitri++;
            }
            dem = 0;
        }
}
void kiemtra(long dau,long cuoi)
{
    long i;
    long temp;
    temp = id-1;
    for(i=dau;i<=cuoi;i++)    
        if(d[fix[i]] == 0)
        {
            d[fix[i]] = 1;
            temp--;
        }
    if(temp == 0)
    {
        if(cuoi - dau < kt - bd)
        {
            bd = dau;
            kt = cuoi;
        }
    }
}
void khoitao()
{
    long i;
    for(i=1;i<id;i++) 
        d[i] = 0;   
}

void solve()
{
    long i;
    long dau,cuoi;
    long val;
    val = 0;
    
    da = 0;
    while(!pq.empty())
    {
        a[da++] = pq.top();
        pq.pop();
    }
    for(i=0;i<da;i++)
        if(a[i].gt != val)
        {
            if(val && a[i].vt - dau + 1 >= id - 1)
            {
                khoitao();
                kiemtra(dau,a[i].vt);
                if(kt - bd - 1 == id-1)
                    break;
            }
            dau = a[i].vt;
            val = a[i].gt;
        }
        else
        {
            cuoi = a[i].vt-1;
            if(a[i].vt - dau + 1>= id-1)
            {
                khoitao();
                kiemtra(dau,cuoi);
                if(kt - bd - 1 == id-1)
                    break;
            }
            dau = a[i].vt;
        }
    if(bd == 0 && kt == da*2)
    {
        bd = 1;
        kt = da;
    }
    printf("%ld %ld\n",bd,kt);
}

void input()
{
    int ntest,cs;
    scanf("%d",&ntest);
    cs = 1;
    while(ntest--)    
    {
        mmap.clear();
        while(!pq.empty())
            pq.pop();
        id = 1;
        vitri = 1;
        da = 0;
        while(true)
        {
            gets(s);
            if(strcmp(s,"END") == 0)
                break;
            xuly();
        }
        bd = 0;
        kt = da*2;
        printf("Document %d: ",cs++);
        solve();
    }
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();
    
    return 0;
}

