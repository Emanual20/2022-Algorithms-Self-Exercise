const int maxn = 10;
typedef long long ll;
class Solution {
public:
    map<int, int> mp;
    
    ll solve(int x){
        if(x <= 1) return -1;
        else return ceil(x * 1.0f / 3);
    }
    
    ll minimumRounds(vector<int>& tasks) {
        for(auto &iter : tasks){
            mp[iter]++;
        }
        ll ret = 0;
        for(auto &iter : mp){
            ll tmp = solve(iter.second);
            if(tmp == -1) return -1;
            else ret += tmp;
        }
        return ret;
    }
};