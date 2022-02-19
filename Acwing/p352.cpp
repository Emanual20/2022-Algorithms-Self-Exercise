/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;

struct edge{
    int fm, to;
};
vector<edge> edges[maxn];

const int maxd = 17;
int depth[maxn], fa[maxn][maxd + 1];

void InitDepthAndFa(int root){
    memset(depth, 0x3f, sizeof(depth));
    depth[0] = 0, depth[root] = 1, fa[root][0] = 0;
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int nfm = iter.fm, nto = iter.to;
            if(depth[nto] > depth[now] + 1){
                depth[nto] = depth[now] + 1;
                fa[nto][0] = now;
                for (int i = 1; i <= maxd; i++){
                    fa[nto][i] = fa[fa[nto][i - 1]][i - 1];
                }
                q.push(nto);
            }
        }
    }
}

int d[maxn], ans = 0;
int Calc_LCA(int x, int y){
    if(depth[x] < depth[y])
        swap(x, y);
    for (int i = maxd; i >= 0; i--){
        if(depth[fa[x][i]] >= depth[y]){
            x = fa[x][i];
        }
    }
    if(x == y)
        return x;
    for (int i = maxd; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

int dfs(int now, int fm){
    int res = d[now];
    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(nto != fm){
            int tmp = dfs(nto, now);
            if(tmp == 0)
                ans += m;
            else if(tmp == 1)
                ans += 1;
            res += tmp;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({fm, to}), edges[to].push_back({to, fm});
    }

    InitDepthAndFa(1);

    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        d[fm] += 1, d[to] += 1, d[Calc_LCA(fm, to)] -= 2;
    }

    dfs(1, -1);
    cout << ans << endl;
    return 0;
}