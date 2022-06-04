/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-28
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
int t, a, b, c, d, tota, totb;
string s;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> s, tota = totb = 0;
        for(auto &ch : s)
            if(ch == 'A')
                tota += 1;
            else totb += 1;
 
        if(tota != a + c + d || totb != b + c + d){
            cout << "NO\n";
        }
        else{
            vector<int> vaa, vab, vba;
            int beg = -1, last = -1, ntot = 0, lens = s.length();
            for (int i = 0; i <= lens; i++){
                if(beg == -1){
                    beg = last = s[i], ntot += 1;
                }
                else{
                    if(i == lens || s[i] == last){
                        if (beg == 'A' && last == 'A' || beg == 'B' && last == 'B')
                            vaa.push_back(ntot);
                        else if(beg == 'A' && last == 'B')
                            vab.push_back(ntot);
                        else if(beg == 'B' && last == 'A')
                            vba.push_back(ntot);
                        beg = last = s[i], ntot = 1;
                    }
                    else{
                        last = s[i], ntot += 1;
                    }
                }
            }
 
            sort(vaa.begin(), vaa.end());
            sort(vab.begin(), vab.end());
            sort(vba.begin(), vba.end());
            // for vaa with len, it can provide len / 2 ab, len / 2 ba
            // for vbb with len, it can provide len / 2 ab, len / 2 ba
            // so we can merge vaa and vbb into vaa
            int tot = 0;
            for(auto &it : vaa){
                tot += it / 2;
            }
            // for vab with len, it can provide only len / 2 - 1 ba, if we parse it into ab and ba
            // so we need waste less greedily
            for(auto &it : vab){
                int nc = min(c, it / 2);
                int nd = max(0, it / 2 - 1 - nc);
                c -= nc, d -= nd;
            }
            for(auto &it : vba){
                int nd = min(d, it / 2);
                int nc = max(0, it / 2 - 1 - nd);
                c -= nc, d -= nd;
            }
            cout << (max(0, c) + max(0, d) <= tot ? "YES\n" : "NO\n");
        }
    }
    return 0;
}