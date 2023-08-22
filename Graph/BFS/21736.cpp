#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,answer;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

vector<string> map;
bool visited[601][601];

int start_x,start_y;
vector<pair<int,int>> person;
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();   

        if(map[cur_x][cur_y] == 'P'){
            answer++;
        }

        for(int i = 0; i < 4 ;i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if(map[next_x][next_y] == 'X') continue;
            if(visited[next_x][next_y]) continue;

            q.push({next_x,next_y});
            visited[next_x][next_y] = true;
        }

    }

}

int main(){
    cin >> n >> m;

    for(int i = 0;i < n ; i++){
        string lines;
        cin >> lines;
        map.push_back(lines);
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'I'){
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }


    bfs();

    if(answer != 0){
        cout << answer << "\n";
    }else{
        cout << "TT\n";
    }
    return 0;
}