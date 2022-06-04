/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-01
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
int t, n, a[maxn], b[maxn];

void rotate(int left, int right){
    int res = b[right];
    for (int i = right; i > left; i--){
        b[i] = b[i - 1];
    }
    b[left] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], b[i] = i;
        int idx = -1, last = -1, flag = 1, tot = 0;
        for (int i = 1; i <= n + 1; i++){
            if(last == -1)
                tot = 1, last = a[i], idx = i;
            else if(i == n + 1 || last != a[i])
                flag = flag && (tot > 1), tot = 0, last = -1, rotate(idx, idx + tot - 1);
            else
                tot += 1;
        }

        if(flag){
            for (int i = 1; i <= n; i++)
                cout << b[i] << " ";
        }
        else{
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}