/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
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

const int maxn = 100 + 10;
ll k, r = 100;
int a[4][4], b[4][4], n, m, beg = 0;
int f[3][3] = {0, -1, 1, 1, 0, -1, -1, 1, 0};

map<pii, int> mp;
struct item{
    int x, y;
};
item info[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> k >> n >> m;
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> b[i][j];
        }
    }

    for (int i = 1; i <= r; i++){
        int tmp = f[n - 1][m - 1];

        if(tmp == -1)
            info[i].x = info[i - 1].x, info[i].y = info[i - 1].y + 1;
        else if(tmp == 1)
            info[i].x = info[i - 1].x + 1, info[i].y = info[i - 1].y;
        else
            info[i].x = info[i - 1].x, info[i].y = info[i - 1].y;

        int resn = n, resm = m;
        n = a[resn][resm], m = b[resn][resm];
        mp[make_pair(resn, resm)] = i - 1;
        if(mp.find(make_pair(n, m)) != mp.end()){
            r = i - mp[make_pair(n, m)];
            beg = mp[make_pair(n, m)];
            break;
        }
    }

    if(k <= beg){
        cout << info[k].x << " " << info[k].y << endl;
    }
    else{
        ll q = (k - beg) / r, rem = (k - beg) % r;
        ll ans0 = q * (info[r + beg].x - info[beg].x) + (info[rem + beg].x - info[beg].x);
        ll ans1 = q * (info[r + beg].y - info[beg].y) + (info[rem + beg].y - info[beg].y);
        ans0 += info[beg].x, ans1 += info[beg].y;
        cout << ans0 << " " << ans1 << endl;
    }
    return 0;
}