#include <iostream>
#include <vector>

int N, M;

int map[8][8];

std::vector<std::pair<int,int>> virus;

int main(){
    std::cin >> N >> M;

    for(int i = 0; i < N ;i ++){
        for(int j = 0; j < M; j++){
            std::cin >> map[i][j];
            if(map[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }



    return 0;
}