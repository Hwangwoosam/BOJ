#include <iostream>
#include <vector>

int TC,N,M,W;
int dist[501];

// std::vector<std::pair<int,int>> info[501];

bool BF(int n, std::vector<std::pair<int,int>>* info){
    dist[1] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++ ){
            for(int k = 0; k < info[j].size(); k++){
                if(dist[info[j][k].first] > dist[j] + info[j][k].second){
                    dist[info[j][k].first] = dist[j] + info[j][k].second;
                    if(i == n) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    std::cin >> TC;
    
    for(int i = 0; i < TC; i++){
        std::cin >> N >> M >> W;

        for(int i = 1; i <= N; i++){
            dist[i] = 10001;
        }
        
        std::vector<std::pair<int,int>> info[501];

        int s, e, t;
        for(int j = 0 ; j < M; j++){
            std::cin >> s >> e >> t;
            info[s].push_back({e,t});
            info[e].push_back({s,t});
        }

        for(int j = 0; j < W; j++){
            std::cin >> s >> e >> t;
            info[s].push_back({e,-t});
        }

        if(BF(N,info)){
            std::cout << "YES\n";
        }else{
            std::cout << "NO\n";
        }

    }

    return 0;
}