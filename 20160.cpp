#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

int v,e;
int start;
vector<pair<int,int>> graph[10001];
long long dist[10001][10001];
vector<int> yoghurt;

int getDist(int s,int e){
    
    if(graph[s].empty()) return INT_MAX; 

    for(int i = 1; i <= v; i++){
        dist[s][i] = INT_MAX;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[s][s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > dist[s][cur]) continue;

        int nSize = graph[cur].size();
        for(int j = 0; j < nSize; j++){
            int next = graph[cur][j].second;
            int nCost = graph[cur][j].first;

            if(dist[s][next] > nCost + dist[s][cur]){
                dist[s][next] = nCost + dist[s][cur];
                pq.push({dist[s][next],next});
            }
        }
    }

    return dist[s][e];
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }

    for(int i = 0; i < 10; i++){
        int place;
        cin >> place;
        yoghurt.push_back(place);
    }

    cin >> start;
    
    int ans = INT_MAX;
    long long sum = 0;
    int stIdx = yoghurt.front();

    for(int i = 0; i < 10; i++){
        long long d = getDist(stIdx,yoghurt[i]);
        if(d == INT_MAX) continue;

        sum += d;

        if(getDist(start,yoghurt[i]) <= sum){
            if(ans > yoghurt[i]) ans = yoghurt[i];
        }

        stIdx = yoghurt[i];
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << "\n";

    return 0;
}