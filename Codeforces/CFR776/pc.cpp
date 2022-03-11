/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct item{
    int index;
    int x;
    int w;
};

vector<item> points;
vector<item> selected;
int t, n, m;

bool comp_w(item it1, item it2){
    return it1.w < it2.w;
}
bool comp_x(item it1, item it2){
    return it1.x < it2.x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        points.clear();
        selected.clear();

        cin >> m >> n;
        for (int i = 1; i <= n; i++){
            int x, w;
            cin >> x >> w;
            points.push_back({i, x, w});
        }

        sort(points.begin(), points.end(), comp_w);
        ll ans = 0;
        for (int i = 0; i < 2 * m; i++){
            ans += points[i].w;
            selected.push_back({points[i].index, points[i].x, points[i].w});
        }
        sort(selected.begin(), selected.end(), comp_x);

        cout << ans << '\n';
        for (int i = 0; i < m; i++){
            cout << selected[i].index << " " << selected[2 * m - 1 - i].index << '\n';
        }
        cout << endl;
    }
    return 0;
}