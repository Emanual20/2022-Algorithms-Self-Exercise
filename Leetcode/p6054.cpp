const int maxn = 300 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;

struct item{
    int x, y, timestamp;
};

class Solution {
public:
    int grids[maxn][maxn];
    int fire[maxn][maxn], man[maxn][maxn], n, m;
    int vis_fire[maxn][maxn], vis_man[maxn][maxn];
    
    bool check(int tmpx, int tmpy){
        return (tmpx >= 1 && tmpx <= n) && (tmpy >= 1 && tmpy <= m);
    }
    
    bool check_path(int tmp){
        queue<item> qq;
        bool nvis[maxn][maxn];
        memset(nvis, 0, sizeof(nvis));
        int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
        int flag = 0;
        
        qq.push({1, 1, 0}), nvis[1][1] = 0;
        while(!qq.empty()){
            auto now = qq.front();
            for(int k = 0; k < 4; k++){
                int nx = now.x + dx[k], ny = now.y + dy[k];
                int nw = fire[nx][ny] - man[nx][ny] - 1;
                if(check(nx, ny) && !nvis[nx][ny] && grids[nx][ny] == 0 && nw >= tmp){
                    nvis[nx][ny] = 1, qq.push({nx, ny, now.timestamp + 1});
                    if(nx == n && ny == m){
                        flag = 1;
                    }
                }
            }
            qq.pop();
        }
        return flag;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        // 0 is available, 1 is fire, 2 is wall
        n = grid.size(), m = grid[0].size();
        int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                fire[i][j] = inf;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grids[i + 1][j + 1] = grid[i][j];
            }
        }
        memset(man, 0, sizeof(man));
        memset(vis_man, 0, sizeof(vis_man));
        memset(vis_fire, 0, sizeof(vis_fire));
        
        queue<item> q;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grids[i][j] == 1){
                    q.push({i, j, 0}), vis_fire[i][j] = 1, fire[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto now = q.front();
            for(int k = 0; k < 4; k++){
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(check(nx, ny) && !vis_fire[nx][ny] && grids[nx][ny] == 0){
                    vis_fire[nx][ny] = 1, fire[nx][ny] = now.timestamp + 1;
                    q.push({nx, ny, now.timestamp + 1});
                }
            }
            q.pop();
        }
        
        q.push({1, 1, 0}), vis_man[1][1] = 1;
        while(!q.empty()){
            auto now = q.front();
            for(int k = 0; k < 4; k++){
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(check(nx, ny) && !vis_man[nx][ny] && grids[nx][ny] == 0){
                    vis_man[nx][ny] = 1, man[nx][ny] = now.timestamp + 1;
                    q.push({nx, ny, now.timestamp + 1});
                }
            }
            q.pop();
        }
        
        fire[n][m] += 1;
        
        int left = 0, right = 1e9;
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(check_path(mid)) left = mid;
            else right = mid - 1;
        }
        
        int ans = right;
        if(ans == 0 && !check_path(ans)){
            ans = -1;
        }
        return ans;
    }
};