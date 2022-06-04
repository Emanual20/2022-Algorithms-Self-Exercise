/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-01
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

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t, n, k;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        int tot1 = 0, lens = s.length();
        for(auto &ch : s)
            tot1 += (ch == '1');
        int ans = tot1 * 11 - (s[0] == '1' ? 1 : 0) - (s[lens - 1] == '1' ? 10 : 0);

        int flag1 = s[0] == '1', mk1 = inf;
        if(!flag1){
            for (int i = 1; i < lens - 1; i++)
                if(s[i] == '1'){
                    mk1 = i; break;
                }
        }

        int flag2 = s[lens - 1] == '1', mk2 = -inf;
        if(!flag2){
            for (int i = lens - 2; i >= 1; i--)
                if(s[i] == '1'){
                    mk2 = i; break;
                }
        }

        int res = 0;
        if(!flag1 && mk1 <= k)
            res = max(res, 1);
        if(!flag2 && lens - 1 - mk2 <= k)
            res = max(res, 10);
        if(!flag1 && !flag2 && mk1 != mk2 && mk1 + lens - 1 - mk2 <= k)
            res = max(res, 11);
        if(flag1 && !flag2 && lens - 1 <= k)
            res = max(res, 9);
        ans -= res;
        cout << ans << "\n";
    }
    return 0;
}