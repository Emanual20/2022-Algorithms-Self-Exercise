#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
typedef long long ll;
ll k, n;
stack<int> ans;
bool vis[maxn];
int a[maxn], b[maxn];
int ptr = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    ans.push(b[n - k]);
    ptr = n - k + 1;

    for (int i = n - 1; i >= k; i--){
        int remove = a[i], now = ans.top();
        // cout << remove << " " << now << " " << ptr << endl;
        if(remove < now){
            // cout << "fine" << endl;
            ans.push(now);
        }
        else{
            ptr--;
            // cout << ptr << endl;
            while(vis[ptr]){
                // cout << "ptr:" << ptr << ", vis:" << vis[ptr] << endl;
                ptr--;
            }
            ans.push(ptr);
        }
        vis[remove] = true;
    }
    
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}