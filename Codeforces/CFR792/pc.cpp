/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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

int t, n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0)), b;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        b = a;
        for (int i = 0; i < n; i++){
            sort(a[i].begin(), a[i].end());
        }

        int flag = 1, st = -1, pos0 = -1, pos1 = -1;
        for (int i = 0; i < n; i++){
            int now = 0;
            for (int j = 0; j < m; j++){
                if(a[i][j] != b[i][j]){
                    if(st == -1){
                        if(pos0 == -1)
                            pos0 = j;
                        else if(pos1 == -1)
                            pos1 = j, st = 1;
                    }
                    else{
                        if(now == 0){
                            if(j == pos0){
                                now += 1;
                            }
                            else{
                                flag = 0;
                                break;
                            }
                        }
                        else if(now == 1){
                            if(j == pos1){
                                now += 1;
                            }
                            else{
                                flag = 0;
                                break;
                            }
                        }
                        else{
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }

        if(flag == 1){
            if(pos0 == -1 && pos1 == -1){
                pos0 = pos1 = 1;
            }
            else{
                for (int i = 0; i < n; i++){
                    flag = flag && (b[i][pos0] >= b[i][pos1]);
                }
            }
        }

        if(flag == 1){
            cout << pos0 << " " << pos1 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}