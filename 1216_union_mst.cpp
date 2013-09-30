
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>

#define fi "1216.inp"
#define fo "1216.out"
using namespace std;
 
int const MAXN = 1000 + 2;
int const MAXE = MAXN * MAXN;
template<class T> struct edge {
    int f, t; T c;
    edge() { f = t = c = -1; }
    edge(int _f, int _t, T _c)
        : f(_f), t(_t), c(_c) {}
    bool operator < (const edge &e) const {
        return c < e.c;
    }
};
int x[MAXN], y[MAXN];
edge<int> edge_list[MAXE];
 
struct disjoint_set {
    int *parent;
    int *rank;
    int components;
 
    disjoint_set(int n) {
        parent = new int[n];
        rank = new int[n];
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
 
    int find(int s) {
        return parent[s] == s ? s : find(parent[s]);
    }
 
    bool equal(int s1, int s2) {
        return find(s1) == find(s2);
    }
 
    void join(int s1, int s2) {
        int p1 = find(s1);
        int p2 = find(s2);
        if (p1 == p2) return;
        if (rank[p1] == rank[p2])
            ++rank[p1];
        if (rank[p1] < rank[p2])
            swap(p1, p2);
        parent[p2] = p1;
        --components;
    }
};
 
 
double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1 - x2, y1 - y2);
}
 
int mst(int nodes, int edges, int forest_num) {
    disjoint_set s(nodes);
    sort(edge_list, edge_list + edges);
    double result = 0;
    for (int i = 0; i < edges; i++) {
        if (!s.equal(edge_list[i].f, edge_list[i].t)) {
            s.join(edge_list[i].f, edge_list[i].t);
            result += edge_list[i].c;
            cout << edge_list[i].c << endl;
        }
        if (s.components == forest_num)
            return (int) ceil(edge_list[i].c);
    }
    return (int) ceil(edge_list[edges - 1].c);
}
 
int main(int argc, char **argv) {
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    int T, rt, n, e; scanf("%d", &T);
    while (T-- != 0) {
        scanf("%d", &rt);
        n = e = 0;
        while (scanf("%d", &x[n]) && x[n] != -1)
            scanf("%d", &y[n++]);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edge_list[e++] = edge<int>(i, j, dist(x[i], y[i], x[j], y[j]));
        printf("%d\n", mst(n, e, rt));
    }
    return 0;
}
