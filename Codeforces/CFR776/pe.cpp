/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f;
vector<int> boards;
vector<int> idxs;
int t, n, d;
int dis(int id1, int id2){
    return boards[id2] - boards[id1] - 1;
}
int solve(int index){
    if(index == 0) return -1;
    int ret = inf, maxi = -inf;
    for (int i = 0; i < index - 1; i++){
        ret = min(ret, dis(i, i + 1)), maxi = max(maxi, dis(i, i + 1));
    }
    for (int i = index + 1; i < n; i++){
        ret = min(ret, dis(i, i + 1)), maxi = max(maxi, dis(i, i + 1));
    }
    ret = min(ret, dis(index - 1, index + 1)), maxi = max(maxi, dis(index - 1, index + 1));
    
    int tmp = (maxi - 1) / 2;
    if(index != n){
        tmp = max(tmp, d - boards[n] - 1);
    }
    else{
        tmp = max(tmp, d - boards[n - 1] - 1);
    }
    ret = min(ret, tmp);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        boards.clear(), idxs.clear();

        cin >> n >> d;
        boards.push_back(0);
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            boards.push_back(x);
        }
        boards.push_back(d + 1);
        int mini = inf;
        for (int i = 0; i < n; i++){
            int tmp = dis(i, i + 1);
            if(tmp < mini){
                idxs.clear();
                mini = tmp;
                idxs.push_back(i), idxs.push_back(i + 1);
            }
            else if(tmp == mini){
                idxs.push_back(i), idxs.push_back(i + 1);
            }
        }

        int ans = mini;
        ans = max(ans, solve(idxs[0]));
        ans = max(ans, solve(idxs[1]));
        cout << ans << endl;
    }
    return 0;
}