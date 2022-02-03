/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<double> v;
vector<double> v_check;
int n;
const long double eps = 1e-8;
long double ans_check = 0;
double dp[2][maxn];
void init_check(){
    ans_check = 0;
    v_check.clear();
    memset(dp, 0, sizeof(dp));
}
void check(){
    dp[1][0] = v_check[0];
    for (int i = 1; i < v_check.size(); i++){
        dp[0][i] = dp[1][i-1];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + v_check[i];
    }
    ans_check = max(dp[0][v_check.size() - 1], dp[1][v_check.size() - 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long double left = 0, right = 0, l, r;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        right = max(right, x * (long double)1.0);
        v.push_back(x);
    }
    
    l = left, r = right;
    while(r - l > eps){
        long double mid = (r + l) / 2;
        init_check();
        for (int i = 0; i < n; i++){
            v_check.push_back(v[i] - mid);
        }
        check();
        ans_check > 0 ? l = mid : r = mid;
    }
    cout << (l + r) / 2 << endl;

    int li = left, ri = right;
    while(ri - li >= 0){
        int mid = (ri + li) / 2;
        init_check();
        for (int i = 0; i < n; i++){
            v_check.push_back(v[i] >= mid ? 1 : -1);
        }
        check();
        ans_check > 0 ? li = mid + 1: ri = mid - 1;
    }
    cout << ri << endl;
    return 0;
}