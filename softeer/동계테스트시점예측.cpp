#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int map[101][101];
int cnt[101][101];
bool visited[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool checkMap(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]) return true;
        }
    }
    return false;
}

void meltIce(int curX,int curY){
    visited[curX][curY] = true;
    for(int i = 0; i < 4; i++){
        int nx = curX + dx[i];
        int ny = curY + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
        if(visited[nx][ny]) continue;
    
        if(map[nx][ny]) cnt[nx][ny]++;
        else meltIce(nx,ny);
    }

}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int answer = 0;

    while(1){

        if(!checkMap()) break;
        answer++;
        memset(visited,0,sizeof(visited));
        memset(cnt,0,sizeof(cnt));
        meltIce(0,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cnt[i][j] >= 2) map[i][j] = 0;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}