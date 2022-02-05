/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20 + 10;
int n, m, dp[maxn][maxn];
struct item{
    int v, w;
};
vector<vector<item>> items;
vector<int> ans_vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        vector<item> vec;
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            vec.push_back({j + 1, x});
        }
        items.push_back(vec);
    }

    for (int i = 1; i <= n; i++){
        for (int j = m; j >= 0; j--){
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < items[i-1].size(); k++){
                if(j >= items[i-1][k].v){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i-1][k].v] + items[i-1][k].w);
                }
            }
        }
    }

    int now_ans = dp[n][m], now_v = m;
    cout << now_ans << endl;
    for (int i = n; i >= 1; i--){
        int res = ans_vec.size();
        for (int j = 0; j < items[i-1].size(); j++){
            if(now_v >= items[i-1][j].v && now_ans == dp[i-1][now_v-items[i-1][j].v] + items[i-1][j].w){
                now_ans -= items[i-1][j].w;
                now_v -= items[i-1][j].v;
                ans_vec.push_back(j + 1);
                break;
            }
        }
        if(ans_vec.size() == res){
            ans_vec.push_back(0);
        }
    }

    for (int i = ans_vec.size() - 1; i >= 0; i--){
        cout << (ans_vec.size() - i) << " " << ans_vec[i] << endl;
    }
}