/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int maxn = 3e5 + 10;
int n, m, vis[maxn], flag[maxn];
ll pow2[maxn], ans = 1;
vector<int> edges[maxn];
vector<int> ans_vec;
void dfs(int now, int fm, int step){
    vis[now] = 1, flag[now] = step;
    for(auto &to : edges[now]){
        if(to == fm) continue;
        if(!vis[to]){
            dfs(to, now, step + 1);
        }
        else{
            if(step >= flag[to]){
                ans_vec.push_back(step - flag[to] + 1);
            }
            continue;
        }
    }
}
void initquickpow2(){
    pow2[0] = 1;
    for (int i = 1; i <= m; i++){
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    initquickpow2();
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to);
        edges[to].push_back(fm);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1, 0);
        }
    }

    ll tot = 0;
    for (int i = 0; i < ans_vec.size(); i++){
        ans *= (pow2[ans_vec[i]] - 1 + MOD) % MOD, tot += ans_vec[i];
        ans %= MOD;
    }
    ans = ans * pow2[m - tot] % MOD;
    cout << ans << endl;
    return 0;
}
/*
16 19
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 2
7 10
5 11
5 12
11 12
5 13
5 14
13 14
5 15
5 16
15 16
*/
/*
7 8
1 2
2 3
2 4
2 5
4 5
2 6
2 7
6 7
*/