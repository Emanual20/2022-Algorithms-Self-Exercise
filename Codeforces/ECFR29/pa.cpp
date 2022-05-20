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

const int maxn = 2e5 + 10;
string s;
int x;

bool check(string tmp){
    int len = tmp.length();
    int ret = 1;
    for (int i = 0; i < len; i++){
        ret = ret && (tmp[i] == tmp[len - i - 1]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> x;
    s = to_string(x);
    int lens = s.length(), flag = 0;
    string tmp = s;
    for (int i = 0; i <= s.length(); i++){
        flag = flag || check(tmp);
        tmp = "0" + tmp;
    }
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}