/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 5e5 + 10;
int n, dp[maxn][2];
struct item{
    int to, w;
};
vector<item> edges[maxn];
set<int> st;
ll ans = 0;

void dfs(int now, int fm, int nt){
    dp[now][0] = 1, dp[now][1] = 0;
    for(auto &it : edges[now]){
        int nto = it.to, nw = it.w;
        if(nto != fm){
            dfs(nto, now, nt);
        }
    }

    for(auto &it : edges[now]){
        int nto = it.to, nw = it.w;
        if(nto != fm){
            if(nw == nt){
                ans += dp[nto][0] * dp[now][0];
                dp[now][1] += dp[nto][0];
            }
            else{
                ans += dp[nto][0] * dp[now][1];
                ans += dp[nto][1] * dp[now][0];
                dp[now][0] += dp[nto][0];
                dp[now][1] += dp[nto][1];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int nfm, nto, nw;
        cin >> nfm >> nto >> nw;
        edges[nfm].push_back({nto, nw}), edges[nto].push_back({nfm, nw}), st.insert(nw);
    }
    
    for(auto &it : st)
        dfs(1, -1, it);
    cout << ans << endl;
    return 0;
}
/*
5
1 2 1
1 3 1
2 4 1
2 5 2
*/