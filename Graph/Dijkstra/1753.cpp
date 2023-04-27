#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int V,E;

int dist[20001];

int start = 0;

std::vector<std::pair<int,int>> info[20001];

std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
int main(){
    std::cin >> V >> E >> start;
    
    for(int i = 1; i <= V; i++){
        dist[i] = INT_MAX;
    }

    for(int i = 0; i < E; i++){
        int u,v,w;
        std::cin >> u >> v >> w;

        info[u].push_back({w,v});
    }

    dist[start] = 0;
    
    q.push({0,start});

    while(!q.empty()){
        int cur_w = q.top().first;
        int cur = q.top().second;
        q.pop();
        
        for(auto& vertex : info[cur]){
            int next_w = vertex.first;
            int next = vertex.second;

            if(dist[next] > dist[cur] + next_w){
                dist[next] = dist[cur] + next_w;
                q.push({dist[next],next});
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == INT_MAX){
            std::cout << "INF\n";
        }else{
            std::cout << dist[i] << "\n";
        }
    }
    return 0;
}