/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int n, m, k, dist[maxn], vis[maxn];
vector<edge> edges[maxn];
void heap_dijkstra(int source, int restriction){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    // min-heap
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dist[source] = 0;
    q.push({0, source});

    while(!q.empty()){
        pii now = q.top();
        q.pop();
        if(vis[now.second])
            continue;
        vis[now.second] = 1;
        for (auto &iter : edges[now.second]){
            dist[iter.to] = min(dist[iter.to], 
                                dist[now.second] + (iter.w >= restriction ? 1 : 0));
            q.push({dist[iter.to], iter.to});
        }
    }
}
vector<int> vec_w;
bool check(int x){
    heap_dijkstra(1, vec_w[x]);
    return dist[n] >= (k + 1) && dist[n] <= inf / 2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
        edges[to].push_back({fm, w});
        vec_w.push_back(w);
    }
    
    heap_dijkstra(1, 0);
    if(dist[n] <= k){
        cout << 0 << endl;
        return 0;
    }
    
    sort(vec_w.begin(), vec_w.end());
    int left = 0, right = vec_w.size() - 1;
    while(left < right){
        int mid = (left + right) >> 1;
        if(check(mid)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
        
        if(left == right - 1){
            if(check(right)){
                left = right;
            }
            else right = left;
        }
    }

    int mid = (left + right) >> 1;
    if(check(mid)){
        cout << vec_w[mid] << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}