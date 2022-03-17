/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct point{
    ll x, y;
};

bool comp(point p1, point p2){
    return p1.y < p2.y;
}
vector<point> points;

int t, n = 3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        points.clear();
        for (int i = 1; i <= n; i++){
            ll x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }
        sort(points.begin(), points.end(), comp);

        long double ans = 0;
        if(points[1].y == points[2].y){
            ans = abs(points[1].x - points[2].x);
        }
        cout << ans << endl;
    }
    return 0;
}