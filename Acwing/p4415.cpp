/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int T, n, m, sum1 = 0, sum2 = 0;
int color[maxn], vis[maxn];
bool CheckPartBipartite(int root){
    int tot = 0;
    color[root] = 1, sum1 += 1;

    queue<int> q;
    q.push(root), vis[root] = 1, tot = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(!vis[to]){
                vis[to] = 1, tot++, color[to] = 3 - color[now], q.push(to);
                if(color[to] == 1)
                    sum1 += 1;
                else
                    sum2 += 1;
            }
            else if(color[to] == color[now]){
                return false;
            }
        }
    }
    return true;
}

const ll MOD = 998244353;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}

int CheckBipartite(){
    ll ret = 1;
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            if(edges[i].size() && ret){
                int res1 = sum1, res2 = sum2;
                ret = CheckPartBipartite(i) ? ret : 0;
                ret *= (quickpow(2, sum1 - res1) + quickpow(2, sum2 - res2));
                ret %= MOD;
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        sum1 = 0, sum2 = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int nfm, nto;
            cin >> nfm >> nto;
            edges[nfm].push_back({nto, 1}), edges[nto].push_back({nfm, 1});
        }

        ll ans = CheckBipartite();
        if(!ans){
            cout << 0 << endl;
        }
        else{
            ans = ans * quickpow(3, n - sum1 - sum2) % MOD;
            cout << ans << endl;
        }

        for (int i = 1; i <= n; i++){
            edges[i].clear();
            vis[i] = 0, color[i] = 0;
        }
    }
    return 0;
}