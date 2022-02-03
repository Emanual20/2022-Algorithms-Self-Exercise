#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
typedef long long ll;
struct point{
    long double x;
    long double y;
};
vector<point> vp;
int n;
long double dis(point p1, point p2){
    return abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        point p;
        cin >> p.x >> p.y;
        vp.push_back(p);
    }

    long double ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            long double now = dis(vp[i], vp[j]);
            ans = max(ans, sqrt(now));
        }
    }

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}