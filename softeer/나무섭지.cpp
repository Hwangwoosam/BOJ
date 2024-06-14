#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

queue<pair<int,int>> q;
int startX,startY;
int endX,endY;

int map[1001][1001];
bool visited[1001][1001];
int ghostMove[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;

void checkGhostMove(){
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(ghostMove[nx][ny] <= ghostMove[curX][curY] + 1) continue;
        
            ghostMove[nx][ny] = ghostMove[curX][curY] + 1;
            q.push({nx,ny});
        }
    }
}

bool findWay(){
    queue<pair<int,int>> way;
    way.push({startX,startY});
    visited[startX][startY] = true;

    while(!way.empty()){
        int curX = way.front().first;
        int curY = way.front().second;
        way.pop();

        if(curX == endX && curY == endY){
            return true;
        }

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >=  n || ny < 0 || ny >= m) continue;
            if(map[curX][curY] + 1 >= ghostMove[nx][ny]) continue;
            if(map[nx][ny] == -1) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            map[nx][ny] = map[curX][curY] + 1;
            way.push({nx,ny});
        }
    }

    return false;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string inp;
        cin >> inp;
        for(int j = 0; j < m; j++){
            ghostMove[i][j] = INT32_MAX;
            if(inp[j] == '.'){
                map[i][j] = 0;
            }else if(inp[j] == 'D'){
                endX = i;
                endY = j;
            }else if(inp[j] == '#'){
                map[i][j] = -1;
            }else if(inp[j] == 'N'){
                startX = i;
                startY = j;
            }else{
                q.push({i,j});
                ghostMove[i][j] = 0;
            }
        }
    }

    checkGhostMove();

    if(findWay()){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }


    return 0;
}