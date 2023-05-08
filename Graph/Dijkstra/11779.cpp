#include <iostream>
#include <string>
#include <queue>
#include <vector>

int city_num,bus_num;
int start, end;

std::vector<std::pair<int,int>> vec[1001];
int path[1001];
int dist[1001];

void dijkstra(){
    std::priority_queue<std::pair<int,int>> pq;

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if(cost > dist[cur]){
            continue;
        }

        for(int i = 0; i < vec[cur].size(); i++){
            int ncost = vec[cur][i].first;
            int next = vec[cur][i].second;

            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({dist[next],next});
                path[next] = cur;
            }
        }
    }

}

int main(){
    std::cin >> city_num >> bus_num;
    
    for(int j = 1; j <= city_num; j++){
        dist[j] = 200000001;
    }

    for(int i = 0; i < bus_num; i++){
        int from,to,weight;
        std::cin >> from >> to >> weight;
        
        vec[from].push_back({weight,to});
    }
    
    std::cin >> start >> end;
    dijkstra();

    int val = path[end];
    std::vector<int> arr;
    arr.push_back(end);

    while(val){
        arr.push_back(val);
        val = path[val];
    }  

    std::cout << dist[end] << "\n";
    std::cout << arr.size() << "\n";
    for(int i = arr.size() -1 ; i >= 0; i--){
        std::cout << arr[i] <<" ";
    }
    std::cout << "\n";

    return 0;
}