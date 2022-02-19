/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const long double eps = 1e-6;
const int inf = 0x3f3f3f3f;
long double dist[maxn];
int vis[maxn], cnt[maxn], HasNegaRing;
int n, m, fw[maxn];
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source, long double x){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    HasNegaRing = 0;

    if(source == -1){
        for (int i = 1; i <= n; i++){
            q.push(i), vis[i] = 1;
        }
    }
    else{
        dist[source] = 0, q.push(source), vis[source] = 1;
    }
    
    while(!q.empty()){
        int now = q.front();
        vis[now] = 0, q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            long double nw = -(fw[iter.to] - x * iter.w);
            if(dist[to] > dist[now] + nw){
                dist[to] = dist[now] + nw;

                // if exist negative ring
                cnt[to] = cnt[now] + 1;
                if (cnt[to] >= n){
                    HasNegaRing = 1;
                    return;
                }
                
                // if 'to' is already in the queue q
                if(!vis[to]){
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
}
bool check(long double x){
    spfa(-1, x);
    return HasNegaRing;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> fw[i];
    }
    for (int i = 1; i <= m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
    }

    long double left = 0, right = 1000;
    while(right - left > eps){
        long double mid = (left + right) / 2;
        if(check(mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << fixed << setprecision(2) << right << endl;
    return 0;
}