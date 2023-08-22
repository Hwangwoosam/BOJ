#include <iostream>
#include <vector>

using namespace std;

int r,c, answer = 0;

vector<string> map;
bool alp[27];
bool visited[20][20];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int curX, int curY,int cnt){
    if(cnt > answer){
        answer = cnt;
    }
    
    for(int i = 0; i < 4; i++){
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];
        
        if(nextX < 0 || nextX >=r || nextY < 0 || nextY >= c) continue;
        if(visited[nextX][nextY]) continue;
        if(alp[map[nextX][nextY] - 'A']) continue;
        
        visited[nextX][nextY] = true;
        alp[map[nextX][nextY] - 'A'] = true;
        dfs(nextX,nextY,cnt+1);

        visited[nextX][nextY] = false;
        alp[map[nextX][nextY] - 'A'] = false;
    }

}

int main(){
    cin >> r >> c;

    for(int i = 0; i < r ; i++){
        string inp;
        cin >> inp;
        map.push_back(inp);
    }

    visited[0][0] = true;
    alp[map[0][0]-'A'] = true;
    dfs(0,0,1);

    cout << answer <<"\n";
    return 0;
}