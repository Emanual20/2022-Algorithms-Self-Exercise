/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll MOD = 1e9 + 7;
int t, n, a[maxn], b[maxn], f[maxn], vis[maxn];
vector<int> edges[maxn];

ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x != 0) f[x] = 1;
        }

        for (int i = 1; i <= n; i++){
            edges[a[i]].push_back(b[i]);
            edges[b[i]].push_back(a[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            if(!vis[i]){
                int flag = 0, tot = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    auto now = q.front();
                    vis[now] = 1, flag = flag || f[now], tot += 1;
                    for(auto &nto : edges[now]){
                        if(!vis[nto]){
                            q.push(nto);
                        }
                    }
                    q.pop();
                }
                
                if(!flag && tot > 1){
                    ans += 1;
                }
            }
        }

        ll res = quickpow(2, ans);
        cout << res << "\n";

        for (int i = 1; i <= n; i++){
            f[i] = 0, vis[i] = 0;
            edges[i].clear();
        }
    }
    return 0;
}