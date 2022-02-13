/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int t, a[maxn], b[maxn], n, f[maxn * maxn * 2], g[maxn * maxn * 2], base;
vector<int> ans[maxn * maxn * 2];
vector<int> newa, newb;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        newa.clear();
        newb.clear();
        for (int j = 0; j <= 100 * 100 * 2; j++){
            ans[j].clear();
        }
        cin >> n;
        base = 100 * 100;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        f[base] = 1;
        for (int i = 1; i <= n; i++){
            int dx = a[i] - b[i];
            vector<int> vecg[maxn * maxn * 2];
            for (int j = 0; j <= base * 2; j++){
                vecg[j] = ans[j];
                ans[j].clear();
            }
            memcpy(g, f, sizeof(g));
            memset(f, 0, sizeof(f));
            for (int j = 0; j <= base * 2; j++){
                if(g[j]){
                    f[j + dx] = 1;
                    ans[j + dx] = vecg[j];
                    ans[j + dx].push_back(1);
                    f[j - dx] = 1;
                    ans[j - dx] = vecg[j];
                    ans[j - dx].push_back(-1);
                }
            }
        }

        for (int i = 0; i <= base; i++){
            if(f[base - i]){
                for (int j = 0; j < n; j++){
                    if(ans[base - i][j] == 1){
                        newa.push_back(a[j + 1]);
                        newb.push_back(b[j + 1]);
                    }
                    else{
                        newa.push_back(b[j + 1]);
                        newb.push_back(a[j + 1]);
                    }
                }
                break;
            }
            else if(f[base + i]){
                for (int j = 0; j < n; j++){
                    if(ans[base + i][j] == 1){
                        newa.push_back(a[j + 1]);
                        newb.push_back(b[j + 1]);
                    }
                    else{
                        newa.push_back(b[j + 1]);
                        newb.push_back(a[j + 1]);
                    }
                }
                break;
            }
        }

        ll ansq = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                ansq += (newa[i] + newa[j]) * (newa[i] + newa[j]);
                ansq += (newb[i] + newb[j]) * (newb[i] + newb[j]);
            }
        }
        cout << ansq << endl;
    }
    return 0;
} 