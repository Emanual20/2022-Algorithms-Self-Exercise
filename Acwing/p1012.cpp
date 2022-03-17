/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
struct item{
    int left, right;
};
vector<item> items;

bool comp(item i1, item i2){
    return i1.left < i2.left;
}

int n, dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    items.push_back({-1, -1});
    for (int i = 1; i <= n; i++){
        int left, right;
        cin >> left >> right;
        items.push_back({left, right});
    }

    sort(items.begin(), items.end(), comp);


    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if(items[i].right > items[j].right)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans + 1 << endl;
    return 0;
}