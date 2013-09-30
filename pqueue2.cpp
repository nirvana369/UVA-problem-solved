#include <iostream>
#include <queue>
#include <iomanip>
#include <conio.h>

using namespace std;

struct time1 {
    int h; // >= 0
    int m; // 0-59
    int s; // 0-59
};

class comparetime
{
public:
    bool operator()(time1 &t1, time1 &t2) // t2 has highest prio than t1 if t2 is later (bigger) than t1 // t1 -> t2 t3 t4, t2 uu tien hon thi doi cho t1
    {
        if (t1.h < t2.h) 
            return true;                    //doi cho
        if (t1.h == t2.h && t1.m < t2.m) 
            return true;
        if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) 
            return true;
            
        return false;
    }
};

priority_queue<time1, vector<time1>, comparetime> pq;

int main()
{
    time1 t2;
    
    // Array of 4 time1 objects:
    time1 t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
 
    for (int i = 0; i < 4; ++i)
       pq.push(t[i]);

    while (! pq.empty()) 
    {
       
       
       t2 = pq.top();
       
       cout.width(3);
       cout << t2.h;
       cout.width(3);
       cout << t2.m;      //printf("%3d",t2.m);
       cout.width(3);
       cout << t2.s << endl;
       
       pq.pop();
    }
    
    getch();
    return 0;
}
