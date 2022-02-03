/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
vector<string> ans_vec;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int now = 'z';
    for (int i = 0; i < s.length(); i++){
        now = min(now, (int)s[i]);
    }
    int left = 0, right = s.length() - 1;
    while(now <= 'z'){
        int lastl = left, lastr = right;
        while(left < right){
            while(s[left] <= now && left < right){
                left++;
            }
            while(s[right] != now && left < right){
                right--;
            }
            if(left < right){
                swap(s[left], s[right]);
                left++, right--;
                lastl = left, lastr = right;
            }
        }
        left = lastl, right = lastr;
        now++;
    }
    cout << s << endl;
    return 0;
}