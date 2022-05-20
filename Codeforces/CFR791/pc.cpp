/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-14
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
int n, q;
map<int, int> mpr, mpc;
set<int> str, stc;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    mpr[n + 1] = 1, mpc[n + 1] = 1;

    for (int i = 1; i <= n + 1; i++)
        str.insert(i), stc.insert(i);

    for (int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int nx, ny;
            cin >> nx >> ny;
            mpr[nx] += 1, mpc[ny] += 1;
            str.erase(nx), stc.erase(ny);
        }
        else if(type == 2){
            int nx, ny;
            cin >> nx >> ny;
            mpr[nx] -= 1, mpc[ny] -= 1;
            if(mpr[nx] == 0){
                mpr.erase(nx), str.insert(nx);
            }
            if(mpc[ny] == 0){
                mpc.erase(ny), stc.insert(ny);
            }
        }
        else{
            int nx1, ny1, nx2, ny2, flag = 0;
            cin >> nx1 >> ny1 >> nx2 >> ny2;
            auto itr = str.lower_bound(nx1);
            if(*itr > nx2)
                flag = 1;
            auto itc = stc.lower_bound(ny1);
            if(*itc > ny2)
                flag = 1;
            cout << (flag ? "Yes\n" : "No\n");
        }
    }
    return 0;
}