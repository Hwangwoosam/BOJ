#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<string> map;

long long dx[] = {1,0,-1};
long long dy[] = {0,1,0};

long long n,k;

vector<vector<long long>> bfs(long long x,long long y){
    vector<vector<long long>> dist(2,vector<long long>(n,1e18));

    if(map[x][y] == '#') return dist;

    queue<pair<long long,long long>> q;
    dist[x][y] = 0;
    q.push({x,y});
    
    while(!q.empty()){
        long long curX = q.front().first;
        long long curY = q.front().second;
        q.pop();

        for(int i = 0; i < 3; i++){
            long long nx = curX + dx[i];
            long long ny = curY + dy[i];

            if(nx < 0 || nx >= 2 || ny < 0 || ny >= n) continue;
            if(map[nx][ny] == '#') continue;
            if(dist[nx][ny] != 1e18) continue;
        
            dist[nx][ny] = dist[curX][curY] + 1;
            q.push({nx,ny});
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < 2; i++){
        string inp;
        cin >> inp;
        map.push_back(inp);
    }

    if(k != 1){
        if((map[1][0] == '#' && map[0][n-1] == '#') || (map[0][0] == '#' && map[1][n-1] == '#')) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<vector<long long>> startZero = bfs(0,0);
    vector<vector<long long>> startOne = bfs(1,0);
    
    long long ans = 1e18;
    if(map[0][0] == '.' && map[0][n-1] == '.' && startZero[0][n-1] != 1e18) ans = min(ans,(long long)(startZero[0][n-1]*k + k-1));
    if(map[0][0] == '.' && map[1][n-1] == '.' && startZero[1][n-1] != 1e18) ans = min(ans,(long long)(startZero[1][n-1]*k + 2*(k-1)));
    if(map[1][0] == '.' && map[1][n-1] == '.' && startOne[1][n-1] != 1e18)  ans = min(ans,(long long)(startOne[1][n-1]*k + k-1));
    if(map[1][0] == '.' && map[0][n-1] == '.' && startOne[0][n-1] != 1e18)  ans = min(ans,(long long)(startOne[0][n-1]*k + 2*(k-1)));

    if(ans >= 1e18) cout << "-1\n";
    else cout << ans << "\n";
    
    return 0;
}