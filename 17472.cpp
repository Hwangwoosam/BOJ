#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[11][11];
int parent[10];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;

vector<pair<int,pair<int,int>>> graph;

void getNumber(int x,int y,int idx){
    queue<pair<int,int>> q;

    q.push({x,y});
    map[x][y] = idx;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] != -1) continue;
            

            map[nx][ny] = idx;
            q.push({nx,ny});
        }
    }

}

void findBridge(int x,int y, int dir){
    int val = map[x][y];
    int nx = x;
    int ny = y;
    int dist = 0;
    // cout << "start: " << x << " " << y << "\n";
    while(1){
        nx += dx[dir];
        ny += dy[dir];
        // cout << nx << " " << ny << ": " << map[nx][ny] << "\n";
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if(map[nx][ny] == val) break;

        if(map[nx][ny] == 0) dist++;
        else{
            if(dist >= 2){
                // cout << val << "->" << map[nx][ny] << ": " << dist << "\n";
                graph.push_back({dist,{val,map[nx][ny]}});
            }
            break;
        }
    }
}

int getParent(int a){
    if(parent[a] == a) return a;
    else return getParent(parent[a]);
}

void unionParent(int a,int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool isSameParent(int a,int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;

    return false;
}


int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }

    int cnt = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == -1){
                getNumber(i,j,cnt);
                cnt++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                if(map[i][j] != 0) findBridge(i,j,k);
            }
        }
    }
    
    sort(graph.begin(),graph.end());

    for(int i = 0; i < 10; i++) parent[i] = i;

    int totalDist = 0;
    int gSize = graph.size();
    for(int i = 0 ; i < gSize; i++){    
        // cout << graph[i].second.first << "->" << graph[i].second.second <<":" << graph[i].first << "\n";
        if(!isSameParent(graph[i].second.first,graph[i].second.second)){
            // cout << graph[i].second.first << "->" << graph[i].second.second << ": " << graph[i].first << "\n";
            totalDist += graph[i].first;
            unionParent(graph[i].second.first,graph[i].second.second);
        }
    }

    int root = getParent(1);
    for(int i = 2; i < cnt; i++){
        if(root != getParent(i)){
            totalDist = 0;
            break;
        }
    }

    if(totalDist == 0) cout << "-1\n";
    else cout << totalDist << "\n";


    return 0;
}