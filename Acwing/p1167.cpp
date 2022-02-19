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
const int maxn = 26 * 26 + 10;
const int inf = 0x3f3f3f3f;
long double dist[maxn];
int vis[maxn], cnt[maxn], HasNegaRing;
int n, m;
struct edge{
    int to, w;
};
vector<edge> edges[26 * 26 + 10];
void spfa(int source, long double x){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    int tot = 0;
    HasNegaRing = 0;

    if(source == -1){
        for (int i = 0; i < n; i++){
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
            long double nw = -(iter.w - x);
            if(dist[to] > dist[now] + nw){
                dist[to] = dist[now] + nw;

                // if exist negative ring
                cnt[to] = cnt[now] + 1, tot++;
                if (cnt[to] >= n || tot >= 10 * n){
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
const int maxp = 26 * 26 + 10;
const long double eps = 1e-5;
int trans(char c1, char c2){
    return (c1 - 'a') * 26 + (c2 - 'a');
}
bool check(long double x){
    spfa(-1, x);
    return HasNegaRing;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n, n){
        for (int i = 0; i < maxp; i++){
            edges[i].clear();
        }

        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            int len = s.length();
            if(len < 2) continue;
            edges[trans(s[0], s[1])].push_back({trans(s[len - 2], s[len - 1]), len});
        }

        n = 26 * 26;
        long double left = 0, right = 1e3;
        while(right - left > eps){
            long double mid = (left + right) / 2;
            if(check(mid)){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        if(left >= 2){
            cout << fixed << setprecision(2) << right << '\n';
        }
        else{
            cout << "No Solution" << '\n';
        }
    }
    return 0;
}