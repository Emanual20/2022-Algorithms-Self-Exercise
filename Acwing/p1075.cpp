/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;

struct edge{
    int to, w, ans;
};
vector<edge> edges[maxn];
int n, ans = 0;

int dfs(int now, int fm){
    int res1 = 0, res2 = 0;
    for(auto iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            int tmp = dfs(nto, now) + nw;
            if(tmp > res1) res2 = res1, res1 = tmp;
            else if(tmp > res2) res2 = tmp;
        }
    }
    ans = max(ans, res1 + res2);
    return res1;
}

void build_edges(int x){
    for (int i = 2; i <= n; i++){
        int tmp = 1;
        for (int j = 2; j <= i / j; j++){
            if(i % j == 0){
                tmp += j;
                if(j * j != i) tmp += i / j;
            }
        }
        if(tmp < i)
            edges[tmp].push_back({i, 1}), edges[i].push_back({tmp, 1});
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    build_edges(n);

    dfs(1, -1);
    cout << ans << endl;
    return 0;
}