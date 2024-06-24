#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n,t;

//위오아래왼
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int map[100][100][4];
//x,y,t,d
bool visited[100][100][4][4];
vector<int> signal[13] = {
 {},
 {1,0,2},
 {0,1,3},
 {3,0,2},
 {2,1,3},
 {1,0},
 {0,3},
 {3,2},
 {2,1},
 {1,2},
 {0,1},
 {3,0},
 {2,3}
};

set<pair<int,int>> answer;


int main(){
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                cin >> map[i][j][k];
            }
        }
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    visited[0][0][0][1] = 1;
    answer.insert({0,0});
    int time = 0;
    while(!q.empty()){
        if(time == t) break;
        int sz  = q.size();

        while(sz--){
            int curX = q.front().second.first;
            int curY = q.front().second.second;
            int curD = q.front().first;
            q.pop();

            int curSignal = map[curX][curY][time%4];
            if(signal[curSignal][0] != curD) continue;

            int signalSize = signal[curSignal].size();
            for(int i = 0; i < signalSize; i++){
                int nx = curX + dx[signal[curSignal][i]];
                int ny = curY + dy[signal[curSignal][i]];

                if(nx <0 || nx >= n || ny < 0 || ny >= n) continue;
                if(visited[nx][ny][time%4][signal[curSignal][i]]) continue;

                visited[nx][ny][time%4][signal[curSignal][i]] = true;
                q.push({signal[curSignal][i],{nx,ny}});
                answer.insert({nx,ny});
            } 
        }
        time++;
    }

    cout << answer.size() << "\n";
    return 0;
}