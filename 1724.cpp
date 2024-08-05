#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0}; // 왼 위 오른 아래 

int map[501][501];
bool visited[501][501];
int flag[] = {1,2,4,8}; // 왼쪽 위 오른쪽 아래 벽이 존재
int n,m;

int getSize(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    int cnt = 1;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if((map[curX][curY] & flag[i]) == flag[i]) continue;

            visited[nx][ny] = true;
            cnt++;
            q.push({nx,ny});
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;

    int t;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;

        if(sx == ex){ // 같은 행일 경우
            int minY = min(sy,ey);
            int maxY = max(sy,ey); 

            for(int j = minY; j < maxY; j++){ // 좌우로 선분이 생성되기 때문에 위쪽에 벽추가하기로
                //위쪽 셀 아래의 벽이 없을 경우 추가
                if( sx-1 >= 0 && ((map[sx-1][j] & flag[3]) == 0)) map[sx-1][j] += flag[3];
                //현재 셀 위의 벽이 없을 경우 추가
                if( sx < n && ((map[sx][j] & flag[1]) == 0)) map[sx][j] += flag[1];
            }
        }else{ // 같은 열일 경우
            int minX = min(sx,ex);
            int maxX = max(sx,ex);

            for(int j = minX; j < maxX; j++){ 
                // 왼쪽 셀 오른쪽 벽이 없을 경우 추가
                if(sy-1 >= 0 && ((map[j][sy-1] & flag[2]) == 0)) map[j][sy-1] += flag[2];
                //현재 셀 왼쪽 벽이 없을 경우 추가
                if(sy < m && ((map[j][sy] & flag[0]) == 0)) map[j][sy] += flag[0];
            }
        }
    }

    int maxCnt = 0, minCnt = n*m + 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            int s = getSize(i,j);
            maxCnt = max(maxCnt,s);
            minCnt = min(minCnt,s);
        }
    }

    cout << maxCnt << "\n" << minCnt << "\n";

    return 0;
}