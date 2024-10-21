#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

string map[50];
int col,row;
int ans = 0;

void findDist(int x,int y){
    queue<pair<int,int>> q;
    vector<vector<int>> visited(50,vector<int>(50,0));
    
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= col || ny < 0 || ny >= row) continue;
            if(map[nx][ny] == 'W' || visited[nx][ny] > 0) continue;

            visited[nx][ny] = visited[curX][curY] + 1;
            ans = max(ans,visited[nx][ny]);
            q.push({nx,ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> col >> row;
    vector<pair<int,int>> lands;

    for(int i = 0; i < col; i++) {
        cin >> map[i];
        for(int j = 0; j < row; j++){
            if(map[i][j] == 'L'){
                lands.push_back({i,j});
            }
        }
    }

    for(auto elem : lands){
        findDist(elem.first,elem.second);
    }

    cout << ans-1 << "\n";
    return 0;
}