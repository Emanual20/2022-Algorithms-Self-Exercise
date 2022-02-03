#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 60;
int a[maxn];
int T, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        cout << abs(a[n - 1] - a[0]) << endl;
    }

    return 0;
}