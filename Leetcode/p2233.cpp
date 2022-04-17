typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    bool check(vector<int>& nums, int tmp, int k){
        ll tot = 0;
        for(int i = 0; i < nums.size(); i++){
            tot += max(0, (tmp - nums[i]));
        }
        return tot <= k;
    }
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 1e6 + 1e5;
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(check(nums, mid, k)){
                left = mid;
            }
            else right = mid - 1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= right){
                k -= (right - nums[i]), nums[i] = right;
            }
        }
        for(int i = 0; i < nums.size() && k > 0; i++){
            nums[i]++, k--;
        }
        ll ret = 1;
        for(int i = 0; i < nums.size(); i++){
            ret *= nums[i];
            ret %= MOD;
        }
        return ret;
    }
};