/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e4 + 10, maxlog = 16;
int n, m, q, root = -1;
int depth[maxn], fa[maxn][maxlog + 1];
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void InitDepthAndFather(){
    memset(depth, 0x3f, sizeof(depth));
    memset(fa, 0, sizeof(fa));
    depth[0] = 0, depth[root] = 1, fa[root][0] = 0;
    queue<int> q;
    q.push(root);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto &iter : edges[now]){
            int nto = iter.to;
            if(depth[nto] > depth[now] + 1){
                depth[nto] = depth[now] + 1;
                q.push(nto);
                fa[nto][0] = now;
                for (int k = 1; k <= maxlog; k++){
                    fa[nto][k] = fa[fa[nto][k - 1]][k - 1];
                }
            }
        }

    }
}
int Calc_LCA(int x, int y){
    if(depth[x] < depth[y])
        swap(x, y);
    for (int i = maxlog - 1; i >= 0; i--){
        if(depth[fa[x][i]] >= depth[y]){
            x = fa[x][i];
        }
    }
    if(x == y)
        return x;
    for (int i = maxlog - 1; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i], y = fa[y][i];
        }
    }
    if(fa[x][0] != fa[y][0]){
        cerr << "fxxk, that must be something wrong..!" << endl;
    }
    return fa[x][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if(b == -1){
            root = a;
        }
        else{
            edges[a].push_back({b, 1}), edges[b].push_back({a, 1});
        }
    }

    InitDepthAndFather();

    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int anc = Calc_LCA(x, y);
        if(anc == x){
            cout << 1 << endl;
        }
        else if(anc == y){
            cout << 2 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}