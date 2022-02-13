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
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
int a, b, n, m, f[maxn * maxn], mat[maxn][maxn];
struct edge{
    int fm, to, w;
};
vector<edge> edges;
bool comp(edge e1, edge e2){
    if(e1.w != e2.w)
        return e1.w < e2.w;
    return e1.fm < e2.fm;
}
void init_dsu(int x){
    for(int i = 1; i <= x; i++){
        f[i] = i;    
    }
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
        ret += now.w, tot++;
        merge(now.fm, now.to);
    }
    return (tot == n - 1 ? ret : inf);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    n = a * b;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            mat[i][j] = (i - 1) * a + j;
        }
    }

    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        int pos1 = mat[x1][y1], pos2 = mat[x2][y2];
        edges.push_back({pos1, pos2, 0});
    }

    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if(i != a){
                edges.push_back({mat[i][j], mat[i + 1][j], 1});
            }
            if(j != b){
                edges.push_back({mat[i][j], mat[i][j + 1], 2});
            }
        }
    }

    int ret = kruskal();
    cout << ret << endl;
    return 0;
}