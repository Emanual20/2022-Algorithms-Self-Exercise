/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 40 + 10;
const int maxq = 1e4 + 10;
ll t, n, c, q, pre[maxn];
string s;

struct oper{
    ll l, r, len;
};
oper opers[maxn];
ll queries[maxq];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> c >> q >> s;
        pre[0] = n;
        for (int i = 0; i < c; i++){
            ll nl, nr;
            cin >> nl >> nr;
            opers[i] = {nl, nr, nr - nl + 1};
            pre[i + 1] = pre[i] + opers[i].len;
        }

        for (int i = 1; i <= q; i++){
            ll nq;
            cin >> nq;
            queries[i] = nq;
        }
        
        // for(int j = 0; j <= c; j++)
        //     cout << pre[j] << " ";
        // cout << endl;
        
        for (int i = 1; i <= q; i++){
            for (int j = c; j >= 0; j--){
                if(queries[i] > pre[j])
                    queries[i] = (queries[i] - pre[j] - 1) + opers[j].l;
                // cout << queries[i] << " " << j << endl;
            }
            // cout << endl;
        }

        for (int i = 1; i <= q; i++){
            cout << s[queries[i] - 1] << "\n";
        }
        for (int i = 0; i <= c; i++){
            pre[i] = 0;
        }
    }
    return 0;
}