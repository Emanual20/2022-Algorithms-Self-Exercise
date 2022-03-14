/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;

int n, m, q, nxt[maxn], pre[maxn];
string s, t;
vector<int> pos;

int cnt = 0;

inline void get_nxt(string str2, int len2){
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i<len2){
        if (j == -1 || str2[i] == str2[j])nxt[++i]=++j;
        else j = nxt[j];
    }
}
inline void kmp(string str1, string str2, int len1, int len2){
    int i = 0, j = 0;
    get_nxt(str2, len2);
    while (i < len1){
        if (j == -1 || str1[i] == str2[j])++i,++j;
        else j = nxt[j];
        if (j == len2) ++cnt, pre[i] = 1, j = nxt[j];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q >> s >> t;
    int lens = s.length(), lent = t.length();
    kmp(s, t, lens, lent);
    for (int i = 1; i <= lens; i++){
        pre[i] += pre[i - 1];
    }
    while(q--){
        int l, r, ans = 0;
        cin >> l >> r;
        if(r - l + 1 < lent) ans = 0;
        else{
            int real_beg = l + t.length() - 1;
            ans = r > real_beg - 1 ? pre[r] - pre[real_beg - 1] : 0;
        }
        cout << ans << endl;
    }
    return 0;
}