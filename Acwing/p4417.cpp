/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct line{
    int x, y;
};

vector<line> vec1, vec2;
int n, m, nx, ny;

bool compx(line nl1, line nl2){
    return nl1.x < nl2.x;
}

bool compy(line nl1, line nl2){
    return nl1.y < nl2.y;
}

int dist(line nl1, line nl2){
    return max(0, nl2.x - nl1.y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> nx >> ny;
        vec1.push_back({nx, ny});
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> nx >> ny;
        vec2.push_back({nx, ny});
    }

    int ans = 0;
    sort(vec1.begin(), vec1.end(), compy);
    sort(vec2.begin(), vec2.end(), compx);
    ans = max(ans, dist(vec1[0], vec2[vec2.size() - 1]));

    sort(vec1.begin(), vec1.end(), compx);
    sort(vec2.begin(), vec2.end(), compy);
    ans = max(ans, dist(vec2[0], vec1[vec1.size() - 1]));
    cout << ans << "\n";
    return 0;
}