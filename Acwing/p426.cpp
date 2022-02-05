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
const int maxn = 3e4 + 10;
int v, n, dp[maxn];
struct item{
    int v, w;
};
vector<item> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> n;
    for (int i = 0; i < n; i++){
        int single, x;
        cin >> single >> x;
        items.push_back({single, single * x});
    }

    for (int i = 0; i < n; i++){
        for (int j = v; j >= items[i].v; j--){
            dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
        }
    }
    cout << dp[v] << endl;
    return 0;
}