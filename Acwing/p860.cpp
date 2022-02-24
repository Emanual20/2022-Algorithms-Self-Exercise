/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n, m;

int color[maxn], vis[maxn];

bool CheckPartBipartite(int root){
    int tot = 0;
    color[root] = 1;

    queue<int> q;
    q.push(root), vis[root] = 1, tot = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(!vis[to]){
                vis[to] = 1, tot++, color[to] = 3 - color[now], q.push(to);
            }
            else if(color[to] == color[now]){
                return false;
            }
        }
    }
    return true;
}

bool CheckBipartite(){
    int ret = 1;
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            ret = ret && CheckPartBipartite(i);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({to, 1}), edges[to].push_back({fm, 1});
    }

    int ans = CheckBipartite();
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}