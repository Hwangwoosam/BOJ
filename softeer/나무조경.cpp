#include <iostream>

using namespace std;

int n,answer = 0;
int cntLimit = 4;
int map[4][4];
bool visited[4][4];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


void findAnswer(int cnt, int result){
    if(cnt == cntLimit){
        answer = max(answer, result);
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;

                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    findAnswer(cnt+1, result + map[i][j] + map[nx][ny]);
                    visited[nx][ny] = false;
                }

                visited[i][j] = false;
            }
        }
    }

}

int main(){
    cin >> n;

    if(n == 2) cntLimit = 2;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    findAnswer(0,0);
    
    cout << answer << "\n";

    return 0;
}