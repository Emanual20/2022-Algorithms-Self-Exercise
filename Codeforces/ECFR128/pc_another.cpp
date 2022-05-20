/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t, lens, pre0[maxn], pre1[maxn];
string s;

int cal(int l, int r){
    return max(pre0[r] - pre0[l - 1], pre1[l - 1] - pre1[0] + pre1[lens] - pre1[r]);
}

bool check(int tmp){
    int sum = inf;
    for (int i = 1, j = 0; i <= lens; i++){
        sum = min(sum, cal(i, j));
        while(pre0[j] - pre0[i - 1] <= tmp && j < lens)
            j++, sum = min(sum, cal(i, j));
    }
    return sum <= tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        lens = s.length();
        for(int i = 0; i < lens; i++){
            if(s[i] == '0'){
                pre0[i + 1] = pre0[i] + 1;
                pre1[i + 1] = pre1[i];
            }
            else{
                pre0[i + 1] = pre0[i];
                pre1[i + 1] = pre1[i] + 1;                
            }
        }
        
        int left = 0, right = lens;
        while(left < right){
            int mid = left + right >> 1;
            if(check(mid)){
                right = mid;
            }
            else
                left = mid + 1;
        }
        cout << right << endl;
    }
    return 0;
}