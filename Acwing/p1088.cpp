/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
int n;
ll a[maxn][2];
ll pre[maxn], ans[maxn];

struct item{
    int index;
    ll val;
};
deque<item> dq;

void reverse(){
    for (int i = 1; i <= n + 1 - i; i++){
        swap(a[i][0], a[n + 1 - i][0]);
    }
    for (int i = 1; i <= n + 1 - i; i++){
        swap(a[i][1], a[n - i][1]);
    }
    for (int i = 1; i <= n; i++){
        a[n + i][0] = a[i][0], a[n + i][1] = a[i][1];
    }
    for (int i = 1; i < 2 * n; i++){
        pre[i] = pre[i - 1] + (a[i][0] - a[i][1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
        a[n + i][0] = a[i][0], a[n + i][1] = a[i][1];
    }
    for (int i = 1; i < 2 * n; i++){
        pre[i] = pre[i - 1] + (a[i][0] - a[i][1]);
    }

    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < 2 * n; i++){
        if(dq.front().index < i - n + 1){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().val >= pre[i])
            dq.pop_back();
        dq.push_back({i, pre[i]});

        if(i >= n)
            ans[i - n + 1] = ans[i - n + 1] || (dq.front().val - pre[i - n] >= 0);
    }

    reverse();

    for (int i = 1; i < 2 * n; i++){
        if(dq.front().index < i - n + 1){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().val >= pre[i])
            dq.pop_back();
        dq.push_back({i, pre[i]});

        if(i >= n)
            ans[-i + 2 * n] = ans[-i + 2 * n] || (dq.front().val - pre[i - n] >= 0);
    }

    for (int i = 1; i <= n; i++){
        cout << (ans[i] ? "TAK\n" : "NIE\n");
    }
    return 0;
}