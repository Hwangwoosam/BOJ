#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

string map[50];
int rain[50][50];
int userTime[50][50];
bool visited[50][50];
int r,c;
int startX,startY,endX,endY,rainX = -1,rainY = -1;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pair<int,int>> rains;
queue<pair<int,int>> user;

void setRain(){

    while (!rains.empty())
    {
        int curX = rains.front().first;
        int curY = rains.front().second;
        rains.pop();

        for(int i = 0; i < 4; i ++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] != '.') continue;

            visited[nx][ny] = true;
            rain[nx][ny] = rain[curX][curY] + 1;
            rains.push({nx,ny});
        }
    }
    
}

int main(){
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        cin >> map[i];
        for(int j = 0; j < c; j++){
            rain[i][j] = INT_MAX;
            userTime[i][j] = INT_MAX;
            if(map[i][j] == 'H'){
                endX = i;
                endY = j;
            }else if(map[i][j] == 'W'){
                startX = i;
                startY = j;
                userTime[i][j] = 0;
            }else if(map[i][j] == '*'){
                rains.push({i,j});
                rain[i][j] = 0;
            }
        }
    }

    if(rains.size() > 0){
        setRain();
    }

    memset(visited,0,sizeof(visited));

    map[endX][endY] = '.';

    user.push({startX,startY});
    visited[startX][startY] = true;

    while (!user.empty())
    {
        int curX = user.front().first;
        int curY = user.front().second;
        user.pop();

        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] != '.') continue;
            if(userTime[curX][curY] + 1 >= rain[nx][ny]) continue;

            visited[nx][ny] = true;
            userTime[nx][ny] = userTime[curX][curY] + 1;
            user.push({nx,ny});
        }
    }
    
    if(userTime[endX][endY] ==  INT_MAX){
        cout <<"FAIL\n";
    }else{
        cout << userTime[endX][endY] << "\n";
    }


    return 0;
}