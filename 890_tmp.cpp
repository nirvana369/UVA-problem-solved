#include <iostream>
#include <vector>
#define MAXSIZE 39
#define DEBUG 0

#define fi "890.inp"
#define fo "890.out"

using namespace std;

struct celda
{
    int up;
    int down;
    int left;
    int right;
    int visited;
};

struct coord
{
    int row;
    int col;
};

celda grid[MAXSIZE][MAXSIZE];
vector<coord *> list;
int m = 0, n, sm, sn, nflip;

void start()
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            grid[i][j].up = 1;
            grid[i][j].down = 1;
            grid[i][j].left = 1;
            grid[i][j].right = 1;
            grid[i][j].visited = 0;
        }
    list.clear();
    coord *p = new coord;
    p->row = sm-1;
    p->col = sn-1;
    grid[p->row][p->col].visited = 1;
    list.push_back(p);
    if(DEBUG) cout<<"list.size() = "<<list.size()<<"; ("<<p->row<<","<<p->col<<")"<<endl;
}

void flip()
{
    vector<coord *> temp;
    for(int i=list.size()-1; i>=(nflip-1); i--)
        temp.push_back(list[i]);
    for(int i=(nflip-1), j=0; j<temp.size();)
        list[i++] = temp[j++];
}

void up()
{
    coord *p = list.back();
    if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") U"<<endl;
    if((p->row+1) < m && grid[p->row+1][p->col].visited == 0)
    {
        grid[p->row][p->col].up = 0;
        grid[p->row+1][p->col].down = 0;
        grid[p->row+1][p->col].visited = 1;
        coord *pn = new coord;
        pn->row = p->row+1;
        pn->col = p->col;
        list.push_back(pn);
    }
}

void down()
{
    coord *p = list.back();
    if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") D"<<endl;
    if((p->row-1) >= 0 && grid[p->row-1][p->col].visited == 0)
    {
        grid[p->row][p->col].down = 0;
        grid[p->row-1][p->col].up = 0;
        grid[p->row-1][p->col].visited = 1;
        coord *pn = new coord;
        pn->row = p->row-1;
        pn->col = p->col;
        list.push_back(pn);
    }
}

void left()
{
    coord *p = list.back();
    if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") L"<<endl;
    if((p->col-1) >= 0 && grid[p->row][p->col-1].visited == 0)
    {
        grid[p->row][p->col].left = 0;
        grid[p->row][p->col-1].right = 0;
        grid[p->row][p->col-1].visited = 1;
        coord *pn = new coord;
        pn->row = p->row;
        pn->col = p->col-1;
        list.push_back(pn);
    }
}

void right()
{
    coord *p = list.back();
    if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") R"<<endl;
    if((p->col+1) < n && grid[p->row][p->col+1].visited == 0)
    {
        grid[p->row][p->col].right = 0;
        grid[p->row][p->col+1].left = 0;
        grid[p->row][p->col+1].visited = 1;
        coord *pn = new coord;
        pn->row = p->row;
        pn->col = p->col+1;
        list.push_back(pn);
    }
}

int cellisok()
{
    coord *p = list.back();
    /*
    return ((p->row-1) > 0 && grid[p->row-1][p->col].visited == 0) ||
           ((p->row+1) < m && grid[p->row+1][p->col].visited == 0) ||
           ((p->col-1) > 0 && grid[p->row][p->col-1].visited == 0) ||
           ((p->col+1) < n && grid[p->row][p->col+1].visited == 0);
    */
    int i = 0;
    if((p->row-1) >= 0 && grid[p->row-1][p->col].visited == 0)
    {
        i = 1;
        if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") pass down"<<endl;
    }
    if((p->row+1) < m && grid[p->row+1][p->col].visited == 0)
    {
        i = 1;
        if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") pass up"<<endl;
    }
    if((p->col-1) >= 0 && grid[p->row][p->col-1].visited == 0)
    {
        i = 1;
        if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") pass left"<<endl;
    }
    if((p->col+1) < n && grid[p->row][p->col+1].visited == 0)
    {
        i = 1;
        if(DEBUG) cout<<"("<<p->row<<","<<p->col<<") pass right"<<endl;
    }
    
    return i;
}

void printmaze()
{
    for(int j=0; j<n; j++)
    {
        cout<<" ";
        if(grid[m-1][j].up==0)
            cout<<" ";
        else
            cout<<"_";
    }
    for(int i=m-1; i>=0; i--)
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            if(grid[i][j].left==0)
                cout<<" ";
            else
                cout<<"|";
            if(grid[i][j].down==0)
                cout<<" ";
            else
                cout<<"_";
        }
        if(grid[i][n-1].right==0)
            cout<<" ";
        else
            cout<<"|";
    }
    cout<<endl<<endl;
}

int main ()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    int nc;
    char command;
    cin>>nc;
    while(nc--)
    {
        cin>>m>>n>>sm>>sn;
        if(DEBUG) cout<<m<<","<<n<<","<<sm<<","<<sn<<endl;
        start();
        while(list.size())
        {
            if(!cellisok())
            {
                if(DEBUG)
                {
                    coord *p = list.back();
                    cout<<"("<<p->row<<","<<p->col<<") deleted"<<endl;
                }
                list.pop_back();
                continue;
            }
            if(!(cin>>command) || ((int)command>=(int)'0' && (int)command<=(int)'9'))
            {
                if(DEBUG)
                {
                    cout<<"list.size() = "<<list.size()<<endl;
                    cout<<"stoped ("<<command<<")"<<endl;
                }
                break;
            }
            if(command == 'U')
                up();
            else if(command == 'D')
                down();
            else if(command == 'L')
                left();
            else if(command == 'R')
                right();
            else if(command == 'F')
            {
                cin>>nflip;
                flip();
            }
        }
        printmaze();
    }
    return 0;
}
