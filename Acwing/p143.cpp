/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, a[maxn];
string s[maxn];

class Trie{
    int son[32 * maxn][2], cnt[32 * maxn], idx = 1;
public:
    void insert(std::string s){
        int lens = s.length();
        int p = 0;
        for (int i = 0; i < lens; i++){
            int now = s[i] - '0';
            if(!son[p][now]){
                son[p][now] = idx++;
            }
            p = son[p][now];
        }
        cnt[p] += 1;
    }

    int query(std::string s){
        int lens = s.length();
        int p = 0, ret = 0;
        for (int i = 0; i < lens; i++){
            ret *= 2;
            int now = !(s[i] - '0');
            if(son[p][now])
                p = son[p][now], ret += now;
            else if(son[p][!now])
                p = son[p][!now], ret += !now;
            else
                return -1;
        }
        return ret;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Trie trie;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        string rem = "";
        for (int j = 31; j >= 0; j--){
            if((a[i] >> j) & 1)
                rem += "1";
            else
                rem += "0";
        }
        trie.insert(rem), s[i] = rem;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int res = trie.query(s[i]) ^ a[i];
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}   