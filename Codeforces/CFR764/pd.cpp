#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int T, n, k, cnt[256], odd = 0, even = 0;
string s;
bool check(int len){
    int nodd = odd, neven = even;
    if(len % 2 == 1){
        if(nodd >= k){
            nodd -= k;
        }
        else{
            nodd = 0;
            neven -= (k - odd + 1) / 2;
        }
    }
    return neven >= (len / 2 * k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        odd = even = 0;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++){
            cnt[s[i]]++;
        }
        for (int ch = 'a'; ch <= 'z'; ch++){
            even += cnt[ch] / 2;
            odd += cnt[ch] % 2;
        }
        int left = 1, right = n / k;
        while(left < right){
            int mid = (left + right) >> 1;
            // cout << check(mid) << " " << mid << " " << left << " " << right << endl;
            if(check(mid)){
                left = mid;
            }
            else
                right = mid - 1;
            
            if(right - left == 1){
                check(right) == 1 ? left = right : right = left;
            }
        }
        cout << (left + right) / 2 << endl;
    }
    
    return 0;
}