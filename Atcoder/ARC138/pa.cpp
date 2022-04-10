/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
int n, k, a[maxn];

struct item{
    int index, val;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<item> inc_s;
    inc_s.push({-1, -inf});

    for (int i = 0; i < k; i++){
        while(!inc_s.empty() && inc_s.top().val >= a[i]){
            inc_s.pop();
        }
        inc_s.push({i, a[i]});
    }

    int lens = inc_s.size();
    vector<item> vec(lens + 1, {0, 0});
    for (int i = lens - 1; i >= 1; i--){
        vec[i] = inc_s.top(), inc_s.pop();
    }

    int ans = inf;
    
    for (int i = k; i < n; i++){
        int left = 1, right = lens - 1;
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(a[i] > vec[mid].val){
                left = mid;
            }
            else
                right = mid - 1;
        }
        ans = min(ans, (a[i] > vec[right].val ? i - vec[right].index : inf));
    }

    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}