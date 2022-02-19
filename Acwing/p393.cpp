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
const int maxn = 24 + 10;
const int inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn], cnt[maxn], HasNegaRing;
int nr[maxn], pre[maxn], tot[maxn];
int n, m, t;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, -0x3f, sizeof(dist));
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
            if(dist[to] < dist[now] + iter.w){
                dist[to] = dist[now] + iter.w;

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
bool check(int s24){
    for (int j = 0; j <= 24; j++){
        edges[j].clear();
    }
    for (int j = 1; j <= 24; j++){
        edges[j - 1].push_back({j, 0});
    }
    for (int j = 1; j <= 24; j++){
        edges[j].push_back({j - 1, -tot[j]});
    }
    for (int j = 8; j <= 24; j++){
        edges[j - 8].push_back({j, nr[j]});
    }
    for (int j = 1; j <= 7; j++){
        edges[j + 16].push_back({j, -s24 + nr[j]});
    }
    edges[0].push_back({24, s24}), edges[24].push_back({0, -s24});

    n = 25;
    spfa(0);

    return !HasNegaRing;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        memset(tot, 0, sizeof(tot));

        for (int i = 1; i <= 24; i++){
            cin >> nr[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            tot[x+1]++;
        }

        int left = 0, right = m;
        while(left < right){
            int mid = (left + right) >> 1;
            if(check(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        if(right == m && !check(right)){
            cout << "No Solution" << endl;
        }
        else{
            cout << right << endl;
        }
    }
    return 0;
}