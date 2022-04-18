/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int maxst = (1 << 18);
const int inf = 0x3f3f3f3f;
const long double eps = 1e-10;
int t, n, m, dp[maxst];

struct node{
    double x, y;
};
vector<node> poses;

struct param{
    double a, b;
    int cover;
};
vector<param> params;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        poses.clear(), params.clear();

        cin >> n >> m;

        for (int i = 1; i <= n; i++){
            double nx, ny;
            cin >> nx >> ny;
            poses.push_back({nx, ny});
        }

        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                double x1 = poses[i].x, y1 = poses[i].y;
                double x2 = poses[j].x, y2 = poses[j].y;
                if(x1 != x2){
                    double na = (y1 * x2 - y2 * x1) / (x1 * x2 * (x1 - x2));
                    double nb = (y1 * x2 * x2 - y2 * x1 * x1) / (x1 * x2 * (x2 - x1));
                    int nvalid = 0;
                    for (int k = 0; k < n; k++){
                        double x3 = poses[k].x, y3 = poses[k].y;
                        if(abs(y3 - (na * x3 * x3 + nb * x3)) < eps){
                            nvalid = nvalid | (1 << k);
                        }
                    }
                    if(na < 0)
                        params.push_back({na, nb, nvalid});
                }
            }
        }
        for (int i = 0; i < n; i++){
            params.push_back({-1, -1, 1 << i});
        }

        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++){
            if(dp[i] <= inf / 2){
                for (int j = 0; j < params.size(); j++){
                    int nvalid = params[j].cover;
                    dp[i | nvalid] = min(dp[i | nvalid], dp[i] + 1);
                }
            }
        }
        cout << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}