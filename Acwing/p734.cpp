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
const int maxn = 1e4 + 10;
const long double ld1 = 1.0;
const long double eps = 1e-6;
struct item{
    int s, e, l;
};
int t, n, dp[maxn];
vector<item> items;
bool comp(item i1, item i2){
    if(abs(i1.s * ld1 / i1.l - i2.s * ld1 / i2.l)<eps)
        return i1.e > i2.e;
    return i1.s * i2.l < i2.s * i1.l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for (int nt = 0; nt < t; nt++){
        items.clear();
        cin >> n;
        ll tot_times = 0;
        for (int i = 0; i < n; i++){
            int now_s, now_e, now_l;
            cin >> now_s >> now_e >> now_l;
            items.push_back({now_s, now_e, now_l});
            tot_times += now_s;
        }
        sort(items.begin(), items.end(), comp);
        int ans = 0;
        memset(dp, -0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < items.size(); i++){
            for (int j = tot_times; j >= items[i].s; j--){
                dp[j] = max(dp[j], dp[j - items[i].s] + max(0, items[i].e - (j - items[i].s) * items[i].l));
            }
        }
        for (int j = 0; j <= tot_times; j++){
            ans = max(ans, dp[j]);
        }
        cout << "Case #" << nt+1 << ": " << ans << endl;
    }
    return 0;
}