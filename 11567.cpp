#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[501][501];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;
int sx,sy,ex,ey;
vector<string> map;

bool bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] ++;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(nx == ex-1 && ny == ey-1){
                visited[nx][ny]++;
                if(map[nx][ny] == 'X') return true;
                else if(visited[nx][ny] == 2) return true;
                q.push({nx,ny});
            }else{
                if(map[nx][ny] == 'X') continue;
                if(visited[nx][ny] != 0) continue;
                visited[nx][ny]++;
                q.push({nx,ny});
            }
        }
    }

    return false;
}

int main(){
    cin >> n >> m;

    map.resize(n);

    for(int i = 0; i < n; i++) cin >> map[i];
    
    cin >> sx >> sy;
    cin >> ex >> ey;

    if(bfs(sx-1,sy-1)) cout << "YES\n";
    else cout <<"NO\n";

    return 0;
}