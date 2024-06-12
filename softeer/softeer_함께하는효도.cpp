#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

pair<int,int> friends[3];
vector<vector<pair<int,int>>> routes[3];
bool visited[21][21];
int map[21][21];

int n,m;
int answer = 0; 

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void findWay(int idx, int curX, int curY, vector<pair<int,int>> route){
    if(route.size() == 4){
        routes[idx].push_back(route);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = curX + dx[i];
        int ny = curY + dy[i];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = true;
        route.push_back({nx,ny});
        findWay(idx,nx,ny,route);
        route.pop_back();
        visited[nx][ny] = false;
    }
}

int getScore(vector<vector<pair<int,int>>> route){
    int sum = 0;
    int copyMap[21][21];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            copyMap[i][j] = map[i][j];
        }
    }

    for(vector<pair<int,int>> o : route){
        for(pair<int,int> point : o){
            sum += copyMap[point.first][point.second];
            copyMap[point.first][point.second] = 0;
        }
    }


    return sum;
}

void combination(int idx, vector<vector<pair<int,int>>> route){
    if(idx == m){
        answer = max(answer,getScore(route));
        return;
    }

    for(vector<pair<int,int>> o : routes[idx]){
        route.push_back(o);
        combination(idx+1,route);
        route.pop_back();
    }
}


int main(){

    cin >> n >> m ;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> friends[i].first >> friends[i].second;
    }
    // 각각 가는 가짓수 루트 구하기
    // 각각 친구 별 루트의 조합을 통해 Max값 구하기

    vector<pair<int,int>> route;
    for(int i = 0; i < m; i++){
        route.push_back({friends[i].first,friends[i].second});
        visited[friends[i].first][friends[i].second] = true;
        findWay(i,friends[i].first,friends[i].second,route);
        memset(visited,0,sizeof(visited));
        route.clear();
    }
    vector<vector<pair<int,int>>> result;
    combination(0,result);

    cout << answer << "\n";
    
    return 0;
}