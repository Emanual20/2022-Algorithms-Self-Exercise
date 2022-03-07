/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<int> edges[maxn];
int n, dp[maxn][2], dp_deg[maxn][2];

int color[maxn], w[maxn];

void dfs(int now, int fm){
    for(auto &iter : edges[now]){
        if(iter != fm){
            dfs(iter, now);
            dp[now][0] += dp[iter][1];
            dp_deg[now][0] += dp_deg[iter][1];

            dp[now][1] += max(dp[iter][0], dp[iter][1]);
            if(dp[iter][0] > dp[iter][1]){
                dp_deg[now][1] += dp_deg[iter][0];
            }
            else if(dp[iter][1] > dp[iter][0]){
                dp_deg[now][1] += dp_deg[iter][1];
            }
            else if(dp_deg[iter][1] <= dp_deg[iter][0]){
                dp_deg[now][1] += dp_deg[iter][1];
            }
            else{
                dp_deg[now][1] += dp_deg[iter][0];
            }
        }
    }
    dp[now][0] += 1, dp_deg[now][0] += edges[now].size();
}

void dfs2(int now, int fm, int nc){
    color[now] = nc, w[now] = nc;
    
    if(nc == 0){
        for(auto &iter : edges[now]){
            if(iter != fm){
                dfs2(iter, now, 1);
            }
        }
    }
    else{
        for(auto &iter : edges[now]){
            if(iter != fm){
                if(dp[iter][0] > dp[iter][1]){
                    dfs2(iter, now, 0);
                }
                else if(dp[iter][1] > dp[iter][0])
                    dfs2(iter, now, 1);
                else if(dp_deg[iter][1] <= dp_deg[iter][0]){
                    dfs2(iter, now, 1);
                }
                else{
                    dfs2(iter, now, 0);
                }
            }
        }
    }
}

int rt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to), edges[to].push_back(fm);
    }

    for (int i = 1; i <= n; i++){
        if(edges[i].size() == 1){
            rt = i;
            break;
        }
    }

    if(n == 2){
        cout << 2 << " " << 2 << endl
             << 1 << " " << 1 << endl;
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    dfs(rt, -1);
    dfs2(rt, -1, 0);

    ll ans1 = max(dp[rt][0], dp[rt][1]), ans2 = 0;
    for (int i = 1; i <= n; i++){
        if(!color[i]){
            for(auto &iter : edges[i]){
                w[i] += w[iter];
            }
        }
        ans2 += w[i];
    }

    cout << ans1 << " " << ans2 << endl;
    for (int i = 1; i <= n; i++){
        cout << w[i] << " ";
    }
    cout << endl;
    return 0;
}