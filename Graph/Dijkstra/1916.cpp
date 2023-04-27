#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

int N, M ;
int start,end;
int dist[1001];

std::vector<std::pair<int,int>> cities[1001];

int main(){
    std::cin >> N >> M;
    
    for(int i = 1; i <= N ; i++){
        dist[i] = INT_MAX;
    }

    for(int i = 0; i < M; i++){
        int s,e,w;
        std::cin >> s >> e >> w;
        
        cities[s].push_back({w,e});
    }

    for(int i = 1; i <= N; i++){
        sort(cities[i].begin(),cities[i].end());
    }
    std::cin >> start >> end;

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;

    q.push({0,start});
    while(!q.empty()){
        int cur = q.top().second;
        int cur_w = q.top().first;
        q.pop();

        if(dist[cur] < cur_w) continue;
        
        for(auto& bus : cities[cur]){
            int next = bus.second;
            int next_w = bus.first;

            if(dist[next] > cur_w + next_w){
                dist[next] = cur_w + next_w;
                q.push({dist[next],next});
            }
        }
    }
 
    std::cout << dist[end] << "\n";
    return 0;
}