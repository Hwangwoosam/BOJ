#include <iostream>
#include <queue>

using namespace std;

int n,m;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int map[1001][1001],dist[1001][1001];
bool visited[1001][1001];
queue<pair<int,int>> q;

void bfs(){
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if(map[nextX][nextY] == 0) continue;
            if(visited[nextX][nextY]) continue;

            q.push({nextX,nextY});
            dist[nextX][nextY] = dist[curX][curY] + 1;
            visited[nextX][nextY] = true;
        }

    }

}

int main(){
    cin >> n >> m;

    int startX = 0, startY = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 2){
                startX = i;
                startY = j;
            }
        }
    }

    visited[startX][startY] = true;
    q.push({startX,startY});

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && map[i][j] == 1){
                cout << "-1 "; 
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}