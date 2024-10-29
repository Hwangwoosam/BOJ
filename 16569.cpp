#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int m,n,v;
int sx,sy;

int map[100][100];
int volcanoTime[100][100];
bool visited[100][100];

vector<pair<int,int>> volcano;
int maxHeight = 0;
int minTime = 1e9;

void getVolcanoTime(){
    queue<pair<int,int>> q;

    for(auto elem : volcano) q.push(elem);
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            // if(visited[nx][ny])continue;
            if(volcanoTime[nx][ny] <= volcanoTime[curX][curY] + 1) continue;

            volcanoTime[nx][ny] = volcanoTime[curX][curY] + 1;
            q.push({nx,ny});
        }
    }
}

void getPersonTime(int x,int y){
    queue<pair<pair<int,int>,int>> q;

    q.push({{x,y},0});
    visited[x][y] = true;
    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curT = q.front().second;
        q.pop();

        if(maxHeight < map[curX][curY]){
            maxHeight = map[curX][curY];
            minTime = curT;
        }

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(volcanoTime[nx][ny] <= curT+1) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({{nx,ny},curT+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> v;
    cin >> sx >> sy;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];    
            volcanoTime[i][j] = 1e9;
        }
    }

    for(int i = 0; i < v; i++){
        int x,y,t;
        cin >> x >> y >> t;
        volcanoTime[x-1][y-1] = t;
        visited[x-1][y-1] = true;
        volcano.push_back({x-1,y-1});
    }

    getVolcanoTime();
    getPersonTime(sx-1,sy-1);

    cout << maxHeight << " " << minTime << "\n";
    return 0;
}