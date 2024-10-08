#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    vector<pair<int,int>> conv;
    
    for(int i = 0; i < r; i++){
        int a,b,p;
        cin >> a >> b >> p;
        map[a][b] = p;
    }

    for(int i = 0; i < c; i++){
        int c,d;
        cin >> c >> d;
        conv.push_back({c,d});
    }

    int ans = 10e7;
    queue<pair<pair<int,int>,int>> q;
    for(int j = 0; j < c; j++){
        q.push({{conv[j].first,conv[j].second},0});
        visited[conv[j].first][conv[j].second];
    }

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curD = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] > 0) {
                // cout << nx << " " << ny << "\n";
                // cout << ans << " " << curD+1 << " " << map[nx][ny] << "\n";
                ans = min(ans,(curD+1)*map[nx][ny]);
            }
            q.push({{nx,ny},curD+1});
            visited[nx][ny] = true;
        }

    }

    cout << ans << "\n";
    return 0;
}