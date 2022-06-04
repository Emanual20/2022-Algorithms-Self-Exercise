/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-23
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

struct item{
    int x, y;
};
item it[maxn];
vector<item> seq;
int t, n, a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        seq.clear();
        
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
            it[i] = {a[i], b[i]};
        }

        for (int i = 1; i <= n; i++){
            for (int j = n; j > i; j--){
                if(it[j].x <= it[j - 1].x && it[j].y <= it[j - 1].y){
                    seq.push_back({j, j - 1});
                    swap(it[j], it[j - 1]);
                }
            }
        }

        int flag = 1;
        for (int i = 1; i < n; i++){
            flag = flag && (it[i].x <= it[i + 1].x && it[i].y <= it[i + 1].y);
        }

        if(flag){
            cout << seq.size() << "\n";
            for(auto &sz : seq)
                cout << sz.x << " " << sz.y << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}