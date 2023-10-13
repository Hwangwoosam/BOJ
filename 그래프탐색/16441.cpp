#include <iostream>
#include <queue>

using namespace std;

int n,m;
// #: 0 , . = 1 , + = 2
char map[101][101];
bool visited[101][101];
queue<pair<int,int>> q;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(){
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m || map[nextX][nextY] == '#' || visited[nextX][nextY]) continue;
            
            if(map[nextX][nextY] == '+'){

                while(map[nextX][nextY] == '+'){
                    nextX += dx[i];
                    nextY += dy[i];
                }

                if(map[nextX][nextY] == '#'){
                    nextX -= dx[i];
                    nextY -= dy[i];
                }

                if(!visited[nextX][nextY]){
                    q.push({nextX,nextY});
                    visited[nextX][nextY] = true;
                }

            }else if(map[nextX][nextY] == '.' && !visited[nextX][nextY]){
                q.push({nextX,nextY});
                visited[nextX][nextY] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == false && map[i][j] =='.'){
                map[i][j] = 'P';
            }

            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> map[i][j];

            if(map[i][j] == 'W'){
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }

    bfs();

    return 0;
}