class Solution {
public:
    int m, n, ans;
    vector<vector<int>> grid;
    vector<vector<int>> tot2, tot5;
    vector<vector<int>> pref2, pref5;
    vector<vector<int>> pref2_col, pref5_col;
    
    void init(){
        tot2 = vector<vector<int>>(m + 1, vector<int>(n + 1));
        tot5 = vector<vector<int>>(m + 1, vector<int>(n + 1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = grid[i][j], tot = 0;
                while(tmp % 2 == 0) tmp /= 2, tot++;
                tot2[i][j] = tot;
                
                tmp = grid[i][j], tot = 0;
                while(tmp % 5 == 0) tmp /= 5, tot++;
                tot5[i][j] = tot;
            }
        }
        
        pref2 = vector<vector<int>>(m + 1, vector<int>(n + 1));
        pref5 = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m; i++){
            int ntot2 = 0, ntot5 = 0;
            pref2[i][0] = ntot2, pref5[i][0] = ntot5;
            for(int j = 0; j < n; j++){
                ntot2 += tot2[i][j];
                ntot5 += tot5[i][j];
                pref2[i][j + 1] = ntot2, pref5[i][j + 1] = ntot5;
            }
        }
        
        pref2_col = vector<vector<int>>(n + 1, vector<int>(m + 1));
        pref5_col = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; i++){
            int ntot2 = 0, ntot5 = 0;
            pref2_col[i][0] = ntot2, pref5_col[i][0] = ntot5;
            for(int j = 0; j < m; j++){
                ntot2 += tot2[j][i];
                ntot5 += tot5[j][i];
                pref2_col[i][j + 1] = ntot2, pref5_col[i][j + 1] = ntot5;
            }
        }
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0, this->grid = grid;
        init();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout<<i<<" "<<j<<" "<<"hello"<<" ";
                int ntot2, ntot5;
                
                ntot2 = ntot5 = 0;
                ntot2 = pref2[i][j + 1] + pref2_col[j][i + 1] - tot2[i][j];
                ntot5 = pref5[i][j + 1] + pref5_col[j][i + 1] - tot5[i][j];
                ans = max(ans, min(ntot2, ntot5));
                
                // cout<<"?";
                
                ntot2 = ntot5 = 0;
                ntot2 = (pref2[i][n] - pref2[i][j]) + pref2_col[j][i + 1] - tot2[i][j];
                ntot5 = (pref5[i][n] - pref5[i][j]) + pref5_col[j][i + 1] - tot5[i][j];
                ans = max(ans, min(ntot2, ntot5));
                
                // cout<<"?";
                
                ntot2 = ntot5 = 0;
                ntot2 = pref2[i][j + 1] + (pref2_col[j][m] - pref2_col[j][i]) - tot2[i][j];
                ntot5 = pref5[i][j + 1] + (pref5_col[j][m] - pref5_col[j][i]) - tot5[i][j];
                ans = max(ans, min(ntot2, ntot5));
                
                // cout<<"?";
                
                ntot2 = ntot5 = 0;
                ntot2 = (pref2[i][n] - pref2[i][j]) + (pref2_col[j][m] - pref2_col[j][i]) - tot2[i][j];
                ntot5 = (pref5[i][n] - pref5[i][j]) + (pref5_col[j][m] - pref5_col[j][i]) - tot5[i][j];
                ans = max(ans, min(ntot2, ntot5));
            
                // cout<<"?!"<<endl;
            }
        }
        return ans;
    }
};