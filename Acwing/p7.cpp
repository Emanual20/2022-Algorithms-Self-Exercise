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
const int maxn = 1e3 + 10;
int n, m;
struct item{
    int v, s;
};
vector<item> items;
int dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int now_v, now_w, now_s;
        cin >> now_v >> now_w >> now_s;
        if(now_s == -1){
            now_s = 1;
        }
        else if(now_s == 0){
            now_s = ceil(m * 1.0 / now_v);
        }
        int max_index = 0;
        while(now_s >= (1 << (max_index + 1))){
            items.push_back({now_v * (1 << max_index), now_w * (1 << max_index)});
            max_index++;
        }
        int rem = now_s - (1 << max_index) + 1;
        if(rem > 0)
            items.push_back({now_v * rem, now_w * rem});
    }

    for (int i = 0; i < items.size(); i++){
        for (int j = m; j >= items[i].v; j--){
            dp[j] = max(dp[j], dp[j - items[i].v] + items[i].s);
        }
    }

    int ans = 0;
    for (int j = m; j >= 0; j--){
        ans = max(ans, dp[j]);
    }
    cout << ans << endl;
    return 0;
}