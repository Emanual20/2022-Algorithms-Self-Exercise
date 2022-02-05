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
const int maxn = 5e4 + 10;
struct item{
    int w, s;
};
vector<item> items;
bool comp(item i1, item i2){
    return i1.s + i1.w > i2.s + i2.w;
}
int suf[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int now_w, now_s;
        cin >> now_w >> now_s;
        items.push_back({now_w, now_s});
    }
    sort(items.begin(), items.end(), comp);
    suf[0] = items[0].w;
    int ans = -items[0].s;
    for (int i = 1; i < n; i++){
        ans = max(ans, suf[i - 1] - items[i].s);
        suf[i] = suf[i - 1] + items[i].w;
    }
    cout << ans << endl;
    return 0;
}