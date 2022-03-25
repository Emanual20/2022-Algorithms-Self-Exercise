/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30 + 10;
ll pre[maxn][10], x, y;

void init(){
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < 10; i++){
        pre[1][i] = 1;
    }
    for (int i = 2; i <= 20; i++){
        for (int j = 0; j < 10; j++){
            for (int k = j; k < 10; k++){
                pre[i][j] += pre[i - 1][k];
            }
        }
    }
}

ll solve(int tmp){
    if(tmp == 0) return 1;
    vector<int> vec;
    while(tmp) vec.push_back(tmp % 10), tmp /= 10;

    ll ret = 0, res = 0;
    for (int i = vec.size() - 1; i >= 0; i--){
        // process ndigit = res-vec[i]-1
        for (int j = res; j < vec[i]; j++){
            ret += pre[i + 1][j];
        }
        // process ndigit = vec[i]
        if(vec[i] < res) break;
        res = max(res, vec[i] * 1ll);
        if(i == 0) ret++;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    while(cin >> x >> y){
        auto ansl = solve(x - 1), ansr = solve(y);
        cout << ansr - ansl << endl;
    }
    return 0;
}