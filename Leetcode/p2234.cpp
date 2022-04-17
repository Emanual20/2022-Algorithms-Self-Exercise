typedef long long ll;
class Solution {
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        ll n = flowers.size();
        if (flowers[0] >= target) return n * full;

        ll leftFlowers = newFlowers - target * n;
        for (int i = 0; i < n; i++) {
            flowers[i] = min(flowers[i], target);
            leftFlowers += flowers[i];
        }

        ll ans = 0ll, sumFlowers = 0ll;
        for (int i = 0, x = 0; i <= n; i++) {
            if (leftFlowers >= 0) {
                while (x < i && (ll) flowers[x] * x - sumFlowers <= leftFlowers)
                    sumFlowers += flowers[x], x += 1;
                ll beauty = (n - i) * full;
                if (x > 0) beauty += min((leftFlowers + sumFlowers) / x, (ll) target - 1) * partial;
                ans = max(ans, beauty);
            }
            if (i < n) leftFlowers += target - flowers[i];
        }
        return ans;
    }
};