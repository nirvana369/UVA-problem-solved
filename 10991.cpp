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

#define fi "10991.inp"
#define fo "10991.out"
#define eps 1e-7
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    double s,r1,r2,r3,ab,ac,bc,goca,gocb,gocc,ca,cb,cc,p,pi;
    pi = acos(-1);
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        ab = r1 + r2;   // tinh canh ab
        bc = r2 + r3;   // tinh canh bc
        ac = r1 + r3;   // tinh canh ac
        goca = (ab * ab + ac * ac - bc * bc) / (2 * ab * ac);   // tinh cos goc A
        gocb = (ab * ab + bc * bc - ac * ac) / (2 * ab * bc);   // tinh cos goc B
        gocc = (bc * bc + ac * ac - ab * ab) / (2 * bc * ac);   // tinh cos goc C
        goca = acos(goca);      // doi tu radian sang degree A
        gocb = acos(gocb);      //  doi tu radian sang degree B
        gocc = acos(gocc);       // doi tu radian sang degree C
        ca = (goca * r1 * r1) / 2;  // tinh dien tich hinh quat ban kinh r1
        cb = (gocb * r2 * r2) / 2;  // tinh dien tich hinh quat ban kinh r2
        cc = (gocc * r3 * r3) / 2;  // tinh dien tich hinh quat ban kinh r3
        p = (ab + bc + ac) / 2;     // tinh chu vi tam giac tao boi 3 canh ab bc ac
        s = sqrt(p * (p-ab) * (p-bc) * (p-ac)); // tinh dien tinh tam giac
        s -= (ca + cb + cc);        // lay dien tich tam giac tru di dien tich cua 3 hinh quat tao boi 3 ban kinh r1 r2 r3
        printf("%0.6lf\n",s+eps);   // in ket qua
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
