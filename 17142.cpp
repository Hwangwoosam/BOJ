#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> virus;

int n,m,ans = INT_MAX;
int map[50][50];
int copyMap[50][50];
bool visited[50][50];
bool selectedVirus[10];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int getTime(vector<pair<int,int>> selected){
    memset(visited,0,sizeof(visited));
    memset(copyMap,-1,sizeof(copyMap));

    queue<pair<int,int>> q;
    for(int i = 0; i < m; i++){
        q.push({selected[i].first,selected[i].second});
        copyMap[selected[i].first][selected[i].second] = 0;
        visited[selected[i].first][selected[i].second] = true;
    }

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 1) continue; 

            visited[nx][ny] = true;
            copyMap[nx][ny] = copyMap[curX][curY] + 1;
            q.push({nx,ny});
        }
    }
    // cout << "-----------\n";
    int maxVal = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // cout << copyMap[i][j] << " ";
            if(map[i][j] == 2 || map[i][j] == 1) continue;
            if(!visited[i][j]) return -1;
            maxVal = max(maxVal,copyMap[i][j]);
        }
        // cout << "\n";
    }
    // cout << "-----------\n";

    return maxVal;
}

void activatedVirus(){
    vector<pair<int,int>> selected;

    int vSize = virus.size();
    
    vector<int> zeros(vSize,0);
    fill_n(zeros.begin(),m,1);
    sort(zeros.begin(),zeros.end());
    
    do{
        selected.clear();
        for(int i = 0; i < vSize; i++){
            if(zeros[i] == 1) selected.push_back({virus[i].first,virus[i].second});
        }
        int ret = getTime(selected);
        if(ret == -1) continue;
        ans = min(ans,ret);
    }while(next_permutation(zeros.begin(),zeros.end()));
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];

            if(map[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }

    activatedVirus();

    if(ans == INT_MAX) ans = -1;
    
    cout << ans << "\n";
    return 0;
}