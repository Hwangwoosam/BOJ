#include <iostream>
#include <climits>

#define MAX 987654321

int dist[101][101];

int N,M;

int main(){
    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dist[i][j] = MAX;
        }
    }

    for(int i = 0; i < M; i++){
        int from,to,weight;
        std::cin >> from >> to >> weight;
        if(dist[from][to] > weight){
            dist[from][to] = weight;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(dist[j][i] != MAX && dist[i][k] != MAX){
                    dist[j][k] = std::min(dist[j][k],dist[j][i] + dist[i][k]);
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j ||dist[i][j] == MAX){
                std::cout << '0' << " ";
            }else{
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }


    return 0;
}