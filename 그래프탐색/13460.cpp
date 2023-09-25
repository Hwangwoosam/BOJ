#include <iostream>
#include <queue>

using namespace std;

int n,m ;
char map[10][10];
bool visited[10][10][10][10];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int GetPathDist(int x, int y, int dir){
    int cnt = 0;
    while(map[x+dx[dir]][y+dy[dir]] != '#' && map[x][y] != 'O'){
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }

    return cnt;
}

void findPath(int rx,int ry,int bx,int by){
    queue<pair<pair<pair<int,int>,pair<int,int>>,int>> q;
    q.push({{{rx,ry},{bx,by}},0});
    visited[rx][ry][bx][by] = true;

    while(!q.empty()){
        int curRx = q.front().first.first.first;
        int curRy = q.front().first.first.second;
        int curBx = q.front().first.second.first;
        int curBy = q.front().first.second.second;
        int curCnt = q.front().second;

        q.pop();

        if(curCnt >= 10) break;
        for(int i = 0; i < 4; i++){
            int nRx = curRx;
            int nRy = curRy;
            int nBx = curBx;
            int nBy = curBy;
            int nCnt = curCnt + 1;

            int BpathLen = GetPathDist(nBx,nBy,i);
            int RpathLen = GetPathDist(nRx,nRy,i);

            nBx += dx[i]*BpathLen;
            nBy += dy[i]*BpathLen;
            nRx += dx[i]*RpathLen;
            nRy += dy[i]*RpathLen;

            if(map[nBx][nBy] == 'O') continue;
            if(map[nRx][nRy] == 'O'){
                cout << nCnt << "\n";
                return;
            }

            if(nRx == nBx && nRy == nBy){
                if(RpathLen > BpathLen){
                    nRx -= dx[i];
                    nRy -= dy[i];
                }else{
                    nBx -= dx[i];
                    nBy -= dy[i];
                } 
            }

            if(visited[nRx][nRy][nBx][nBy]) continue;
            visited[nRx][nRy][nBx][nBy] = true;
            q.push({{{nRx,nRy},{nBx,nBy}},nCnt});
        }
    }

    cout << "-1\n";
}

int main(){
    int rx,ry,bx,by;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                rx = i;
                ry = j;
            }else if(map[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }

    findPath(rx,ry,bx,by);

    return 0;
}