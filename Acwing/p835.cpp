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
const int maxn = 2e5 + 10;

int q;
string s;
char x;

class Trie{
    int son[maxn][26], cnt[maxn], idx = 1;
public:
    void insert(string s){
        int lens = s.length();
        int p = 0;
        for (int i = 0; i < lens; i++){
            int now = s[i] - 'a';
            if(!son[p][now]){
                son[p][now] = idx++;
            }
            p = son[p][now];
        }
        cnt[p] += 1;
    }

    int query(string s){
        int lens = s.length();
        int p = 0;
        for (int i = 0; i < lens; i++){
            int now = s[i] - 'a';
            if(!son[p][now]) return 0;
            p = son[p][now];
        }
        return cnt[p];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;
    Trie trie;
    while(q--){
        cin >> x >> s;
        if(x == 'I'){
            trie.insert(s);
        }
        else{
            int ans = trie.query(s);
            cout << ans << "\n";
        }
    }
    return 0;
}