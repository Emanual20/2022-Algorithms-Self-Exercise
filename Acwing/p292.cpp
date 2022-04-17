/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;

int n, m, st[maxn], dp[1024][1024];
vector<int> states;

void init(){
    for (int i = 0; i < (1 << m); i++){
        int tmp = i, flag = 1;
        vector<int> vec;
        while(tmp)
            vec.push_back(tmp % 2), tmp /= 2;
        for (int j = 0; j < vec.size(); j++){
            if(vec[j] == 1){
                for (int k = j - 1; k >= max(0, j - 2); k--){
                    flag = flag && (vec[k] == 0);
                }
                for (int k = j + 1; k <= min(j + 2, (int)vec.size() - 1); k++){
                    flag = flag && (vec[k] == 0);
                }
            }
        }
        if(flag)
            states.push_back(i);
    }
}

int count1(int x){
    int ret = 0;
    while(x){
        x = x & (x - 1);
        ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++){
        int tmp = 0;
        for (int i = 1; i <= m; i++){
            char ch;
            cin >> ch;
            tmp *= 2;
            tmp += (ch == 'P');
        }
        st[i] = tmp;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0, st[0] = 0x3fffffff;
    for (int row = 1; row <= n; row++){
        int ndp[1024][1024];
        memset(ndp, 0, sizeof(ndp));
        for (int i = 0; i < states.size(); i++){
            if(row <= 1 || (states[i] & st[row - 2]) == states[i])
                for (int j = 0; j < states.size(); j++)
                if(row <= 0 || (states[j] & st[row - 1]) == states[j])
                    for (int k = 0; k < states.size(); k++)
                    if((states[k] & st[row]) == states[k] && !(states[i] & states[k]) && !(states[j] & states[k])){
                        ndp[states[j]][states[k]] = max(ndp[states[j]][states[k]], dp[states[i]][states[j]] + count1(states[k]));
                    }
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    int ans = 0;
    for (int i = 0; i < states.size(); i++){
        for (int j = 0; j < states.size(); j++){
            ans = max(ans, dp[states[i]][states[j]]);
        }
    }
    cout << ans << endl;
    return 0;
}