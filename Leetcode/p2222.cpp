typedef long long ll;
const int maxn = 1e5 + 10;
class Solution {
public:
    ll tot0[maxn], tot1[maxn];
    long long numberOfWays(string s) {
        ll ret = 0;
        memset(tot0, 0, sizeof(tot0));
        memset(tot1, 0, sizeof(tot1));
        int lens = s.length();
        for(int i = 1; i <= lens; i++){
            if(s[i - 1] == '0') tot0[i]++;
            if(s[i - 1] == '1') tot1[i]++;;
            tot0[i]+=tot0[i-1], tot1[i]+=tot1[i-1];
        }
        for(int i = 1; i <= lens; i++){
            if(s[i-1]=='0'){
                ret += (tot1[i-1] * (tot1[lens] - tot1[i]));
            }
            else if(s[i-1]=='1'){
                ret += (tot0[i-1] * (tot0[lens] - tot0[i]));
            }
        }
        return ret;
    }
};