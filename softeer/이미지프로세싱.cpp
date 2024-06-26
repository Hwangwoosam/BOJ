#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int h,w,q;
int map[129][129];
bool visited[129][129];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


void getProcessing(int x, int y, int c){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
            if(map[curX][curY] != map[nx][ny]) continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
        map[curX][curY] = c;
    }
}

int main(){
    cin >> h >> w;

    for(int i = 1; i <= h ; i++){
        for(int j = 1; j <= w; j++){
            cin >> map[i][j];
        }
    }

    cin >> q;

    for(int i = 0; i < q; i++){
        int x,y,c;
        cin >> x >> y >> c;
        getProcessing(x,y,c);
        memset(visited,0,sizeof(visited));
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
