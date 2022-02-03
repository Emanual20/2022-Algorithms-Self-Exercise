/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll n, l, w;
struct item{
    ll pos;
    ll st;
};
vector<item> a;
bool comp(item i1, item i2){
    if(i1.pos == i2.pos)
        return i1.st < i2.st;
    return i1.pos < i2.pos;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> w;
    a.push_back({0, -1});
    a.push_back({l, 1});
    for (int i = 0; i < n; i++){
        ll pos;
        cin >> pos;
        a.push_back({pos, 1});
        a.push_back({pos + w, -1});
    }

    sort(a.begin(), a.end(), comp);
    ll last = 0, ans = 0;
    for (int i = 0; i < a.size(); i++){
        if(a[i].st == 1){
            ll cnt = a[i].pos > last ? ceil((a[i].pos - last) * (long double)1.0 / w) : 0;
            ans += cnt;
            last = max(last + cnt * w, a[i].pos + w);
        }
    }
    cout << ans << endl;
    return 0;
}