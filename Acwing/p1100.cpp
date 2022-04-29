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
const int maxn = 2e5 + 10;
int vis[maxn], a[maxn], n, fm, to;

bool check(int loc){
    return loc >= 0 && loc <= 2e5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> fm >> to;
    queue<int> q;
    q.push(fm), vis[fm] = 1, a[fm] = 0;
    while(!q.empty()){
        auto now = q.front();
        if(now == to)
            break;
        if(check(now - 1) && !vis[now - 1]){
            q.push(now - 1), vis[now - 1] = 1, a[now - 1] = a[now] + 1;
        }
        if(check(now + 1) && !vis[now + 1]){
            q.push(now + 1), vis[now + 1] = 1, a[now + 1] = a[now] + 1;
        }
        if(check(now * 2) && !vis[now * 2]){
            q.push(now * 2), vis[now * 2] = 1, a[now * 2] = a[now] + 1;
        }
        q.pop();
    }
    
    cout << a[to] << endl;
    return 0;
}