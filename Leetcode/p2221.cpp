const int maxn = 1e3 + 10;
class Solution {
public:
    int a[maxn][maxn];
    int triangularSum(vector<int>& nums) {
        int len = nums.size();
        memset(a, 0, sizeof(a));
        for(int i = 0; i < len; i++){
            a[0][i] = nums[i];
        }
        for(int i = 1; i < len; i++){
            for(int j = 0; j < len - i; j++){
                a[i][j] = (a[i - 1][j] + a[i - 1][j + 1]) % 10;
            }
        }
        return a[len-1][0];
    }
};