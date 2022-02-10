#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 25000 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int fm, to, w;
};
int n, r, p, src, dist[maxn], vis[maxn], block_tot;
vector<edge> edges[maxn];
vector<edge> flights[maxn];
vector<int> connected_components[maxn];
queue<int> qGroups;
int node2blockid[maxn], incnt[maxn];
// min-heap
priority_queue<pii, vector<pii>, greater<pii>> q;
void heap_dijkstra(int source = -1){
    memset(vis, 0, sizeof(vis));
    if(source != -1){
        dist[source] = 0;
        q.push({0, source});
    }

    while(!q.empty()){
        pii now = q.top();
        q.pop();
        if(vis[now.second])
            continue;
        vis[now.second] = 1;
        for (auto &iter : edges[now.second]){
            dist[iter.to] = min(dist[iter.to], dist[now.second] + iter.w);
            q.push({dist[iter.to], iter.to});
        }
    }
}

void bfs(int now, int block_id){
    queue<int> qtmp;

    vis[now] = 1, qtmp.push(now);
    connected_components[block_id].push_back(now);

    while(!qtmp.empty()){
        int now = qtmp.front();
        qtmp.pop();

        for(auto &edge : edges[now]){
            if(!vis[edge.to]){
                vis[edge.to] = 1, qtmp.push(edge.to);
                connected_components[block_id].push_back(edge.to);
            }
        }
    }
}

void Calc_Connected_Component(){
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            bfs(i, block_tot++);
        }
    }
    for (int i = 0; i < block_tot; i++){
        for(auto &id : connected_components[i]){
            node2blockid[id] = i;
        }
    }
    memset(vis, 0, sizeof(vis));
}

void TopologySort(){
    for (int i = 0; i < block_tot; i++){
        if(!incnt[i])
            qGroups.push(i);
    }

    int flag = 0;
    memset(dist, 0x3f, sizeof(dist));
    while(!qGroups.empty()){
        int now = qGroups.front();
        qGroups.pop();

        if(now == node2blockid[src]){
            flag = 1;
        }
        if(flag){
            for(auto &city : connected_components[now]){
                int cnt = 0;
                for(auto &iter_flight : flights[city]){
                    if(city == iter_flight.to){
                        cnt++;
                        dist[city] = min(dist[city], dist[iter_flight.fm] + iter_flight.w);
                    }
                }
                if(cnt)
                    q.push({dist[city], city});
            }
            heap_dijkstra(now == node2blockid[src] ? src : -1);
        }
        
        // delete flight edges of block right now
        for(auto &city : connected_components[now]){
            for(auto &iter_flight : flights[city]){
                if(city == iter_flight.fm && --incnt[node2blockid[iter_flight.to]] == 0){
                    qGroups.push(node2blockid[iter_flight.to]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> p >> src;
    for (int i = 1; i <= r; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({fm, to, w});
        edges[to].push_back({to, fm, w});
    }

    Calc_Connected_Component();

    for (int i = 1; i <= p; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        flights[fm].push_back({fm, to, w});
        flights[to].push_back({fm, to, w});
        incnt[node2blockid[to]]++;
    }

    TopologySort();

    for (int i = 1; i <= n; i++){
        if(dist[i] > inf / 2){
            cout << "NO PATH" << endl;
        }
        else{
            cout << dist[i] << endl;
        }
    }

    return 0;
}