#include <iostream>
#include <queue>

using namespace std;

int n,answer = 0;

int map[16][16];


//bfs
queue<pair<pair<int,int>,int>> q;

//대각선: 0,가로: 1, 세로: 2
int dx[] = {1,0,1};
int dy[] = {1,1,0};

void dfs(int curX,int curY,int dir){
    if(curX == n-1 && curY == n-1){
        answer++;
        return;
    }

    for(int i = 0; i < 3; i++){
        if(dir == 1 && i ==  2) continue;
        if(dir == 2 && i ==  1) continue;

        int nextX = curX + dx[i];
        int nextY = curY + dy[i];

        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
        if(map[nextX][nextY] == 1) continue;
        if(i == 0 && (map[curX][nextY] == 1 || map[nextX][curY] == 1)) continue;
        
        dfs(nextX,nextY,i);
    }
}

void bfs(){

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        if(curX == n-1 && curY == n-1){
            answer++;
        }

        for(int i = 0; i < 3; i++){
            if(dir == 1 && i ==  2) continue;
            if(dir == 2 && i ==  1) continue;

            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
            if(map[nextX][nextY] == 1) continue;
            if(i == 0 && (map[curX][nextY] == 1 || map[nextX][curY] == 1)) continue;

            q.push({{nextX,nextY},i});
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        } 
    }

    dfs(0,1,1);

    q.push({{0,1},1});
    bfs();

    cout << answer << "\n";
    return 0;
}