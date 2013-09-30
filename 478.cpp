/*
                                                        Hoang Linh
                                                    
                                Problem: POINTS IN FIGURES: RECTANGLES, CIRCLES, TRIANGLES - 478 (478.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "figures.inp"
#define fo "figures.out"
/////////////////////
using namespace std;
/////////////////////
struct toado{
                double x,y;
            };
            
struct figure{
                char figures;
                toado point[10];
                double radius;
             };
             
figure shape[20];
int max_fig;
////////////////////
double tinh_khoangcach(toado a,toado b)
{
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}
////////////////////
bool kt_r(int id,toado a)
{
    if((a.x > shape[id].point[0].x && a.x < shape[id].point[1].x) && (a.y > shape[id].point[1].y && a.y < shape[id].point[0].y))
        return true;
    return false;
}
//////////////////////
bool kt_c(int id,toado a)
{
    double kc,tempx,tempy;
    
    tempx = (a.x - shape[id].point[0].x) * (a.x - shape[id].point[0].x);
    tempy = (a.y - shape[id].point[0].y) * (a.y - shape[id].point[0].y);
    kc = shape[id].radius * shape[id].radius;
    if(tempx + tempy <  kc)
        return true;
    return false;
}
////////////////////
double dientichtg(double c1,double c2,double c3)
{
    double p,s;
    p = (c1+c2+c3) / 2;
    s = p*(p-c1)*(p-c2)*(p-c3);
    return sqrt(s);    
}
////////////////////
bool kt_t(int id,toado a)
{
    int k,k1;
    double canh1,canh2;
    double s[3],line_t[3];
    double temp1,temp2;
    
    for(k=0;k<3;k++)
    {
        if(k == 2)
        {
            canh1 = tinh_khoangcach(a,shape[id].point[0]);
            canh2 = tinh_khoangcach(a,shape[id].point[k]);    
            line_t[k] = tinh_khoangcach(shape[id].point[k],shape[id].point[0]);
            s[k] = dientichtg(canh1,canh2,line_t[k]);
        }
        else
        {
            canh1 = tinh_khoangcach(a,shape[id].point[k]);
            canh2 = tinh_khoangcach(a,shape[id].point[k+1]);
            line_t[k] = tinh_khoangcach(shape[id].point[k],shape[id].point[k+1]);
            s[k] = dientichtg(canh1,canh2,line_t[k]);    
        }
    }
    
    temp1 = dientichtg(line_t[0],line_t[1],line_t[2]);
    temp2 = (s[0] + s[1] + s[2]);
        
    if(temp1 > temp2)
        temp1 = temp1 - temp2;
    else
        temp1 = temp2 - temp1;
            
    temp2 = 0.0001;
    if(temp1 <= temp2)
        return true;
    return false;
}
////////////////////
void solve(toado a,int id)
{
    int i,j;
    bool diemngoai;
    
    diemngoai = true;
    for(i=0;i<max_fig;i++)
    {
        if(shape[i].figures == 'r')
        {
                if(kt_r(i,a))
                {
                    diemngoai = false;
                    printf("Point %d is contained in figure %d\n",id+1,i+1);
                }
        }
        else if(shape[i].figures == 'c')
        {
                if(kt_c(i,a))
                {
                    diemngoai = false;
                    printf("Point %d is contained in figure %d\n",id+1,i+1);
                }
        }
        else if(shape[i].figures == 't')
        {
                if(kt_t(i,a))
                {
                    diemngoai = false;
                    printf("Point %d is contained in figure %d\n",id+1,i+1);
                }
        }
    }
    
    if(diemngoai)
        printf("Point %d is not contained in any figure\n",id+1);
}
/////////////////////////
float gt_tuyetdoi(float temp)
{
    if(temp < 0)
        return temp*(-1);
    return temp;
}
////////////////////
void input()
{
    char type;
    int i , count;
    double out;
    toado coor;
    
    out = 0.0000001;
    count = 0;
    
    while(true)
    {
        scanf("%c",&type);    
        if(type == '*')
            break;
        if(type == 'r')   
        {
            shape[count].figures = type;
            for(i=0;i<2;i++)
                scanf("%lf %lf",&shape[count].point[i].x,&shape[count].point[i].y);
            count++;
        } 
        else if(type == 'c')
        {
            shape[count].figures = type;
            scanf("%lf %lf %lf",&shape[count].point[0].x,&shape[count].point[0].y,&shape[count].radius);
            count++;
        }
        else if(type =='t')
        {
            shape[count].figures = type;
            for(i=0;i<3;i++)
                scanf("%lf %lf",&shape[count].point[i].x,&shape[count].point[i].y);
            count++;
        }
    }
    max_fig = count;
    count = 0;
    while(true)
    {
        scanf("%lf %lf",&coor.x,&coor.y);
        if(gt_tuyetdoi(coor.x-9999.9) < out && gt_tuyetdoi(coor.y-9999.9) <= out)
            break;
        solve(coor,count);
        count++;
    }
}
////////////////////
main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
}
