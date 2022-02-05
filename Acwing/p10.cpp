/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int n, v, root;
struct item{
    int v, w;
};
vector<item> items;
int dp[maxn][maxn];
vector<int> edges[maxn];
void dfs(int now_root){
    for (int i = 0; i < edges[now_root].size(); i++){
        dfs(edges[now_root][i]);
    }
    for (int i = 0; i < edges[now_root].size(); i++){
        int IndexOfSon = edges[now_root][i];
        for (int j = v; j >= 0; j--){
            for (int k = j; k >= 0; k--){
                dp[now_root][j] = max(dp[now_root][j],
                                      dp[now_root][j - k] + dp[IndexOfSon][k]);
            }
        }
    }
    for (int j = v; j >= items[now_root].v; j--){
        dp[now_root][j] = dp[now_root][j - items[now_root].v] + items[now_root].w;
    }
    for (int j = items[now_root].v - 1; j >= 0; j--){
        dp[now_root][j] = 0;
    }
    // cout << now_root << " " << dp[now_root][v] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>v;
    for (int i = 0; i < n; i++){
        int now_v, now_w, now_p;
        cin >> now_v >> now_w >> now_p;
        if(now_p == -1){
            root = i;
        }
        edges[now_p - 1].push_back(i);
        items.push_back({now_v, now_w});
    }

    dfs(root);
    cout << dp[root][v] << endl;
    return 0;
}