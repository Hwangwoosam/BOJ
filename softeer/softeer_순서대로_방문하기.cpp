#include <iostream>
#include <vector>

using namespace std;

int n,m,ans;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int map[5][5];
bool visited[5][5];

vector<pair<int,int>> pt;

void dfs(int x, int y, int idx){
    if(x == pt[idx].first && y == pt[idx].second){
        // cout << "check: " << x << " " << y << " " << idx << "\n";
        if(idx == m-1){
            ans++;
            return;
        }
        idx++;
    }

    // cout << "cur: " << x << " " << y << "\n";
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // cout << "(nx,ny): " << nx << " " << ny << "\n";

        if(visited[nx][ny]) continue;
        if(nx > n || nx <= 0 || ny > n || ny <= 0) continue;
        if(map[nx][ny] == 1) continue;
        dfs(nx,ny,idx);
    }
    visited[x][y] = false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        pt.push_back({x,y});
    }

    int idx = 0;
    dfs(pt[idx].first,pt[idx].second,idx);

    cout << ans << "\n";
    return 0;
}