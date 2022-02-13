/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n, m, a[maxn][maxn], dp[maxn][maxn], pos[maxn][maxn], vis[maxn], ans = inf;
vector<int> plans;
void divide_and_conquer(int left, int right){
    if(pos[left][right] == inf){
        if(!vis[left]){
            vis[left] = 1;
            plans.push_back(left);
        }
        if(!vis[right]){
            vis[right] = 1;
            plans.push_back(right);
        }
        return;
    }
    int mid = pos[left][right];
    vis[mid] = 1;
    divide_and_conquer(left, mid);
    plans.push_back(mid);
    divide_and_conquer(mid, right);
}
void print_plans(){
    for (int i = 0; i < plans.size(); i++){
        cout << plans[i] << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        a[fm][to] = a[to][fm] = (a[fm][to] ? min(a[fm][to], w) : w);
    }
    memset(pos, 0x3f, sizeof(pos));
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(a[i][j])
                dp[i][j] = a[i][j];
            if(i == j)
                dp[i][j] = a[i][j] = 0;
        }
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    pos[i][j] = k;
                }
                if(i != j){
                    for (int iter = k + 1; iter <= n; iter++){
                        if(iter != i && iter != j && a[i][iter] && a[iter][j] && dp[i][j] < inf / 2){
                            if(ans > dp[i][j] + a[i][iter] + a[iter][j]){
                                ans = dp[i][j] + a[i][iter] + a[iter][j];
                                plans.clear();
                                memset(vis, 0, sizeof(vis));
                                divide_and_conquer(i, j);
                                plans.push_back(iter);
                            }
                        }
                    }
                }
            }
        }
    }

    if(plans.size() == 0){
        cout << "No solution." << endl;
    }
    else{
        print_plans();
    }
    return 0;
}