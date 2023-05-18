#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

int N, M, cnt =3, result = 0;


int map[8][8];
bool visited[8][8];
int tmp_map[8][8];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

std::vector<std::pair<int,int>> virus;

void bfs(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            tmp_map[i][j] = map[i][j];
        }
    }

    std::queue<std::pair<int,int>> q;
    for(int i = 0; i < virus.size(); i++){
        q.push({virus[i].first,virus[i].second});
        visited[virus[i].first][virus[i].second] = true;

        while(!q.empty()){
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();

            for(int j = 0; j < 4; j++){
                int next_y = cur_y + dir[j][0];
                int next_x = cur_x + dir[j][1];

                if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M){
                    continue;
                }

                if(!visited[next_y][next_x] && tmp_map[next_y][next_x] == 0){
                    q.push({next_y,next_x});
                    visited[next_y][next_x] = true;
                    tmp_map[next_y][next_x] = 2;
                }
            }
        }
    }

    memset(visited,false,sizeof(visited));

    int size = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(tmp_map[i][j] == 0){
                size++;
            }
        }
    }

    if(size > result){
        result = size;
    }
}

void search(int cnt){
    if(cnt == 3){
        return bfs();
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                search(cnt+1);
                map[i][j] = 0;
            }
        }
    }

}

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

    search(0);

    std::cout << result << "\n";
    return 0;
}