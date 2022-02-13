/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;
int n, m, k, f[maxn], tot[maxn];
struct point{
    int x, y;
};
vector<point> points;
ll DistBetween2Point(point p1, point p2){
    int dx = abs(p1.x - p2.x), dy = abs(p1.y - p2.y);
    return dx * dx + dy * dy;
}
struct edge{
    int fm, to;
    ll w;
};
vector<edge> edges;
vector<edge> ans_vec;
bool comp(edge e1, edge e2){
    if(e1.w == e2.w) return e1.fm < e2.fm;
    return e1.w < e2.w;
}
void init_dsu(int x){
    for(int i = 0; i <= x; i++){
        f[i] = i;    
    }
    memset(tot, 0, sizeof(tot));
}
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int src, int dst){
    int s = find(src), d = find(dst);
    f[d] = s;
}

int kruskal(){
    init_dsu(n);
    int ret = 0, tot = 0;
    sort(edges.begin(), edges.end(), comp);
    for(auto &now : edges){
        if(tot == n - 1 || find(now.fm) == find(now.to)){
            continue;
        }
        ans_vec.push_back({now});
        ret += now.w, tot++;
        merge(now.fm, now.to);
    }
    return (tot == n - 1 ? ret : inf);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            edges.push_back({i, j, DistBetween2Point(points[i], points[j])});
        }
    }

    sort(edges.begin(), edges.end(), comp);
    int ret = kruskal();
    int ans = ans_vec.size() >= k ? ans_vec[ans_vec.size() - k].w : 0;
    cout << fixed << setprecision(2) << sqrt(ans) << endl;
    return 0;
}