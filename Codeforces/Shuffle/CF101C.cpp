/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct point{
    ll x, y;
} pa, pb, pc;

bool check(ll np, ll nq){
    bool ret = 1;
    ll w2_nume = pc.y * (pb.x - np) - pc.x * (pb.y - nq);
    ll w2_deno = pc.x * pc.x + pc.y * pc.y;
    ret = ret && (w2_nume % w2_deno == 0);
    ll w2 = w2_nume / w2_deno;
    ll w1_nume = (pc.y == 0 ? pb.x - np - w2 * pc.y : pb.y - nq + w2 * pc.x);
    ll w1_deno = (pc.y == 0 ? pc.x : pc.y);
    ret = ret && (w1_nume % w1_deno == 0);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> pa.x >> pa.y >> pb.x >> pb.y >> pc.x >> pc.y;

    int flag = 0;
    if(pc.x == 0 && pc.y == 0){
        flag = flag || (pa.x == pb.x && pa.y == pb.y);
        flag = flag || (-pa.x == pb.x && -pa.y == pb.y);
        flag = flag || (pa.y == pb.x && -pa.x == pb.y);
        flag = flag || (-pa.y == pb.x && pa.x == pb.y);
    }
    else{
        flag = flag || check(pa.x, pa.y);
        flag = flag || check(-pa.x, -pa.y);
        flag = flag || check(pa.y, -pa.x);
        flag = flag || check(-pa.y, pa.x);
    }
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}