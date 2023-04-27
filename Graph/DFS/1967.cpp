#include <iostream>
#include <vector>
#include <cstring>

int N;
bool visited[10001] = {false,};

int dist[10001];
int result = 0;
int end_v = 0;
std::vector<std::pair<int,int>> arr[10001];

void dfs(int x, int dist){
    if(visited[x]) return;

    visited[x] = true;

    if(dist > result){
        result = dist;
        end_v = x;
    }

    for(int i = 0; i < arr[x].size(); i++){
        int next = arr[x][i].first;
        int next_d = arr[x][i].second;

        dfs(next,next_d + dist);
    }

}

int main(){
    std::cin >> N;
    
    for(int i = 1; i < N; i++){
        int s,e,w;
        std::cin >> s >> e >> w;
        arr[s].push_back({e,w});
        arr[e].push_back({s,w});
    }

    visited[N] = false;
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    result = 0;
    dfs(end_v,0);

    std::cout << result <<"\n";
    return 0;
}