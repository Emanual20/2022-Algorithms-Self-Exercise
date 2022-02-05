/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxv = 32000 + 10;
const int maxn = 60 + 10;
int v, n, dp[maxv];
vector<int> relations[maxn];
struct item{
    int v, w;
};
item master[maxn], servant[maxn];
vector<vector<item>> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> n;
    for (int i = 0; i < n; i++){
        int now_v, now_p, now_q;
        cin >> now_v >> now_p >> now_q;
        if(!now_q){
            master[i] = {now_v, now_v * now_p};
        }
        else{
            servant[i] = {now_v, now_v * now_p};
            relations[now_q - 1].push_back(i);
        }
    }

    for (int i = 0; i < n; i++){
        if(master[i].v || master[i].w){
            int NumOfServant = relations[i].size();
            vector<item> tmp_vec;
            for (int j = 0; j < (1 << NumOfServant); j++){
                int now_index = j, now_v = master[i].v, now_w = master[i].w, hh = 0;
                while(now_index){
                    if(now_index & 1){
                        now_v += servant[relations[i][hh]].v;
                        now_w += servant[relations[i][hh]].w;
                    }
                    now_index >>= 1;
                    hh++;
                }
                tmp_vec.push_back({now_v, now_w});
            }
            items.push_back(tmp_vec);
        }
    }
    

    for (int i = 0; i < items.size(); i++){
        for (int j = v; j >= 0; j--){
            for (int k = 0; k < items[i].size(); k++){
                if(j >= items[i][k].v){
                    dp[j] = max(dp[j], dp[j - items[i][k].v] + items[i][k].w);
                }
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}