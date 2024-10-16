#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n,m;
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
int dir[8][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
int map[51][51];
bool visited[51][51];
vector<pair<int,int>> cloud;
vector<pair<int,int>> copyMagic;

void getCloud(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j] && map[i][j] >= 2){
                cloud.push_back({i,j});
                map[i][j] -= 2;
            }
        }
    }
    memset(visited,0,sizeof(visited));
}

void moveCloud(int d,int s){
    int cloudCnt = cloud.size();
    while(!cloud.empty()){
        pair<int,int> cur = cloud.back();
        cloud.pop_back();
        int nx = cur.first;
        int ny = cur.second;
        for(int i = 0; i < s; i++){
            nx = (nx + dir[d-1][0]) <= 0 ? n : ((nx+dir[d-1][0]) > n ? 1 : nx+dir[d-1][0]);
            ny = (ny + dir[d-1][1]) <= 0 ? n : ((ny+dir[d-1][1]) > n ? 1 : ny+dir[d-1][1]);
        }
        visited[nx][ny] = true;
        map[nx][ny]++;
        copyMagic.push_back({nx,ny});
    }
    
    
}

void copyMagicOccur(){
    for(auto elem : copyMagic){
        int cnt = 0;
        for(int i = 1; i < 8; i+= 2){
            int nx = elem.first + dir[i][0];
            int ny = elem.second + dir[i][1];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if(map[nx][ny] == 0) continue;

            cnt++;
        }
        map[elem.first][elem.second] += cnt;
    }

    copyMagic.clear();
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    cloud.push_back({n,1});
    cloud.push_back({n,2});
    cloud.push_back({n-1,1});
    cloud.push_back({n-1,2});


    for(int i = 0; i < m; i++){
        int d,s;
        cin >> d >> s;
        moveCloud(d,s);
        copyMagicOccur();
        getCloud();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            if(map[i][j] == 0) continue;
            ans += map[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}