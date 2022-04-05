/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
string s;
int a[maxn][maxn];

int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, -1, 1, 0};

bool check(int nx, int ny){
    bool ret = 0;
    for (int i = 0; i < 5; i++){
        ret = ret || a[nx + dx[i]][ny + dy[i]];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int lens = s.length(), nx = 100, ny = 100, flag = 0;
    for (int i = 0; i < lens; i++){
        int orix = nx, oriy = ny;
        if(s[i] == 'U')
            ny++;
        else if(s[i] == 'D')
            ny--;
        else if (s[i] == 'L')
            nx--;
        else if(s[i] == 'R')
            nx++;

        flag = flag || check(nx, ny);
        a[orix][oriy] = 1;
    }

    cout << (flag ? "NO" : "YES") << endl;
    return 0;
}