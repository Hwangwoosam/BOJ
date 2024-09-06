#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[2000][2000];
bool visited[2000][2000][4];
int n,m;

vector<pair<int,int>> air;
queue<pair<int,pair<int,int>>> q;

int dx[] = {1,0,-1,0}; // 아래, 왼,위,오 /시계방향
int dy[] = {0,-1,0,1};

/* 1 = 들어온 방향 반대 / 그냥 통과(세로)
   2 = 들어온 방향 반대 / 그냥 통과(가로)
*/

//dir = 나가는 방향

int nextDir(int blockNum,int curDir){
    switch(blockNum){
        case 1:
            if(curDir == 0 || curDir == 2) return curDir;
            break;
        case 2:
            if(curDir == 1 || curDir == 3) return curDir;
            break;
        case 3:
            if(curDir == 0 || curDir == 2) return curDir+1;
            if(curDir == 1 || curDir == 3) return curDir-1;
        case 4:
            if(curDir == 0 || curDir == 2) return curDir -1 > 0 ? curDir-1 : curDir+3;
            if(curDir == 1 || curDir == 3) return curDir +1 < 4 ? curDir+1 : (curDir+1)%4;
        default:
            return curDir;
    }

    return -1; 
}

void findSeat(){
    while(!q.empty()){
        int curDir = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        // visited[curX][curY][curDir] = true;

        int nx = curX + dx[curDir];
        int ny = curY + dy[curDir];
        int nDir = nextDir(map[nx][ny],curDir);
        // cout << "cur: " << curX << " " << curY << " " << curDir << "\n";
        // cout << "next: " <<  nx << " " << ny << " " << visited[nx][ny][nDir] << "\n";
        if(nDir == -1){
            visited[nx][ny][curDir] = true;
            continue;
        }
        if(nx < 0 || nx>= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny][nDir]) continue;
        // cout << "Pass\n";
        visited[nx][ny][nDir] = true;
        // cout << nx << " " << ny << "\n";
        q.push({nDir,{nx,ny}});
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 9) air.push_back({i,j});
        }
    }
    
    int airSize = air.size();
    for(int i = 0; i < airSize; i++){
        for(int j = 0; j < 4; j++){
            visited[air[i].first][air[i].second][j] = true;
            q.push({j,{air[i].first,air[i].second}});
        }
    }

    findSeat();

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool check = false;
            for(int k = 0; k < 4; k++){
                if(visited[i][j][k]){
                    ans++;
                    check = true;
                    // cout << "* ";
                    break;
                }
            }
            // if(!check) cout << "- ";
        }
        // cout << "\n";
    }

    cout << ans << "\n";
    return 0;
}