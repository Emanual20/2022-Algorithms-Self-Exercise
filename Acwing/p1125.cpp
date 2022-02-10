/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 150 + 10;
struct point{
    int x, y;
};
int n;
long double a[maxn][maxn], dp[maxn][maxn], maxdist[maxn], ans = inf;
double dis_between_2points(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
vector<point> points;

int f[maxn];
void dsu_init(){
    for (int i = 0; i <= n; i++)
        f[i] = i;
}
int find(int k){
    if(f[k]==k) return k;
    return f[k] = find(f[k]);
}
void merge(int x,int y){
    int a = find(x), b = find(y);
    f[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dsu_init();
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            dp[i][j] = a[i][j] = inf;
            if(s[j] - '0'){
                merge(i, j);
                dp[i][j] = a[i][j] = dis_between_2points(points[i], points[j]);
            }
            if(i == j){
                dp[i][j] = a[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i != j && dp[i][j] < inf / 2){
                maxdist[i] = max(maxdist[i], dp[i][j]);
            }
        }
    }

    for (int _1 = 0; _1 < n; _1++){
        for (int _2 = _1 + 1; _2 < n; _2++){
            if(find(_1) != find(_2)){
                ans = min(ans, maxdist[_1] + maxdist[_2] + dis_between_2points(points[_1], points[_2]));
            }
        }
    }

    for (int i = 0; i < n; i++){
        ans = max(ans, maxdist[i]);
    }

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}