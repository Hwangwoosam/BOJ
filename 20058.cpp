#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int map[64][64];
bool visited[64][64];
int totalSize,ansSum,ansSize;
vector<pair<int,int>> nextMelt;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void rotate(int x,int y,int nSize){
    vector<vector<int>> copyMap(nSize,vector<int>(nSize,0));
    
    for(int i = 0; i < nSize; i++){
        for(int j = 0; j < nSize; j++){
            copyMap[i][j] = map[x+nSize-1-j][y+i];
        }
    }

    for(int i = x; i < x + nSize; i++){
        for(int j = y; j < y+ nSize; j++){
            map[i][j] = copyMap[i-x][j-y];
        }
    }
}

void meltIce(){


    for(int i = 0; i < totalSize; i++){
        for(int j = 0; j < totalSize; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                // cout << nx << " " << ny << "\n";
                if(nx < 0 || nx >= totalSize || ny < 0 || ny >= totalSize) continue;
                if(map[nx][ny] <= 0) continue;
                cnt++;
            }

            // cout << i << ":" << j << "=" << cnt << "\n";
            if(cnt < 3 && map[i][j] > 0) {
                // cout << "check: " << i << "  " << j << "\n";
                nextMelt.push_back({i,j});
            }
        }
    }
    
    while(!nextMelt.empty()){
        auto elem = nextMelt.back();
        map[elem.first][elem.second]--;
        nextMelt.pop_back();
    }
}

void findAnswer(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    
    int cnt = 0;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        ansSum += map[curX][curY];

        cnt++;
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= totalSize || ny < 0 || ny >= totalSize) continue;
            if(map[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }

    if(ansSize < cnt) ansSize = cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q,l;
    cin >> n >> q;

    totalSize = 1 << n;
    for(int i = 0; i < totalSize; i++){
        for(int j = 0; j < totalSize; j++){
            cin >> map[i][j];   
        }
    }

    for(int i = 0; i < q; i++){
        cin >> l;
        int nSize = 1 << l;
        int repeat = totalSize/nSize;

        for(int j = 0; j < repeat; j++){
            for(int k = 0; k < repeat; k++){
                rotate(j*nSize,k*nSize,nSize); 
            }
        }
        meltIce();
        memset(visited,0,sizeof(visited));
    }

    for(int i = 0; i < totalSize; i++){
        for(int j = 0; j < totalSize; j++){
            if(map[i][j] > 0 && !visited[i][j]){
                findAnswer(i,j);
            }
        }
    }

    cout << ansSum << " " << ansSize << "\n";

    return 0;
}