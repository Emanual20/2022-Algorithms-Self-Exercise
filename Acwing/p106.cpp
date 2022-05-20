/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int t, group = 0, n, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> group >> n;
        cout << group << " " << (n + 1) / 2 << endl;

        priority_queue<int, vector<int>, greater<int>> up;
        priority_queue<int, vector<int>> down;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            
            if(down.empty() || a[i] <= down.top())
                down.push(a[i]);
            else
                up.push(a[i]);
            
            if(down.size() > up.size() + 1)
                up.push(down.top()), down.pop();
            if(down.size() < up.size())
                down.push(up.top()), up.pop();
            
            if(i % 2 == 1){
                cout << down.top() << " ";
            }
            if(i % 20 == 0){
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}