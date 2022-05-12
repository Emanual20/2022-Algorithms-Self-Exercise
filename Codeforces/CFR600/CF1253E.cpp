/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n, m, dp[maxn];

struct line{
    int x, s;
};
vector<line> lines;
bool comp(line l1, line l2){
    if(l1.x != l2.x)
        return l1.x < l2.x;
    return l1.s < l2.s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int nx, ns;
        cin >> nx >> ns;
        lines.push_back({nx, ns});
    }

    sort(lines.begin(), lines.end(), comp);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (auto &it : lines){
        int nx = it.x, ns = it.s;
        for (int i = 0; i < m; i++){
            dp[min(m, nx + i)] = min(dp[min(m, nx + i)], dp[max(0, nx - i - 1)] + max(0, i - ns));
        }
        for (int i = m - 1; i >= 0; i--){
            dp[i] = min(dp[i], dp[i + 1]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}