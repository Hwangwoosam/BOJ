#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;
vector<int> visited;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    graph.resize(n+1,vector<int>());
    visited.resize(n+1,0);
    dist.resize(n+1,0);
    for(int i = 1; i <= n; i++){
        while(1){
            int next;
            cin >> next;

            if(next == 0) break;

            graph[i].push_back(next);
        }
        dist[i] = 1e8;
    }

    int m;
    cin >> m;

    queue<int> q;
    for(int i = 0; i < m; i++){
        int origin;
        cin >> origin;
        q.push(origin);
        dist[origin] = 0;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int gSize = graph[cur].size();
        for(int i = 0; i < gSize; i++){
            int next = graph[cur][i];
            visited[next]++;
            if(2*visited[next] < (graph[next].size())) continue;
            if(dist[next] <= dist[cur]+1) continue;

            dist[next] = dist[cur]+1;
            q.push(next); 
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(dist[i] == 1e8) cout << "-1 ";
        else cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}