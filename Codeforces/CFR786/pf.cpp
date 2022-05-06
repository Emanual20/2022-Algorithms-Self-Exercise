/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int tot, n, m, q, a[maxn][maxn];

bool check(int tmpx, int tmpy){
    int res = tot / n, rem = tot % n;
    if(rem == 0){
        return tmpy >= 1 && tmpy <= res;
    }
    else if(res == 0){
        return tmpy == 1 && tmpx >= 1 && tmpx <= rem;
    }
    else{
        return tmpy >= 1 && tmpy <= res && tmpx >= 1 && tmpx <= n ||
               tmpy == res + 1 && tmpx >= 1 && tmpx <= rem;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            a[i][j] = (x == '*'), tot += a[i][j];
        }
    }

    int last = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                last += !check(i, j);
            }
        }
    }

    while(q--){
        int nx, ny;
        cin >> nx >> ny;
        int delta = (a[nx][ny] == 1 ? -1 : 1);

        if(delta == -1){
            last += check(nx, ny);
            int res = tot / n + 1, rem = tot % n;
            if(rem == 0)
                res -= 1, rem += n;
            a[nx][ny] = !a[nx][ny];
            if(a[rem][res] == 0)
                last += delta;
            tot += delta;
        }
        else{
            last -= check(nx, ny);
            tot += delta;
            int res = tot / n + 1, rem = tot % n;
            if(rem == 0)
                res -= 1, rem += n;
            a[nx][ny] = !a[nx][ny];
            if(a[rem][res] == 0)
                last += delta;
        }
        cout << last << "\n";
    }
    return 0;
}