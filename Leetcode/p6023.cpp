const int maxn = 1e3 + 10;
class Solution {
public:
    int dp[maxn][maxn];
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int lenf = floor.length();
        for(int j = 1; j <= lenf; j++){
            dp[0][j] = dp[0][j - 1] + (floor[j - 1] == '1');
        }
        for(int i = 1; i <= numCarpets; i++){
            for(int j = 1; j <= lenf; j++){
                dp[i][j] = dp[i][j - 1] + (floor[j - 1] == '1');
                if(j >= carpetLen) dp[i][j] = min(dp[i][j], dp[i - 1][j - carpetLen]);
                else dp[i][j] = 0;
            }
        }
        return dp[numCarpets][lenf];
    }
};