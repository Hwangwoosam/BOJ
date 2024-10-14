#include <iostream>
#include <queue>

using namespace std;

int map[8][7];
bool dominos[7][7];
bool visited[8][7];
int dx[] = {0,1};
int dy[] = {1,0};
int ans = 0;

void getWays(int x,int y){
    if(x == 7 && y == 6){
        ans++;
        return;
    }

    if(visited[x][y]){
        if(y+1 < 7) getWays(x,y+1);
        else getWays(x+1,0);
        return;
    }


    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= 8 || ny < 0 || ny >= 7) continue;
        if(visited[nx][ny]) continue;

        int mOne = map[x][y];
        int mTwo = map[nx][ny];

        if(dominos[mOne][mTwo] || dominos[mTwo][mOne]) continue;

        dominos[mOne][mTwo] = true;
        dominos[mTwo][mOne] = true;
        visited[x][y] = true;
        visited[nx][ny] = true;
        if(y+1 < 7) getWays(x,y+1);
        else getWays(x+1,0);

        dominos[mOne][mTwo] = false;
        dominos[mTwo][mOne] = false;
        visited[x][y] = false;
        visited[nx][ny] = false;
    }

}

int main(){
    for(int i = 0; i < 8; i++){
        string inp;
        getline(cin,inp);
        for(int j = 0; j < 7; j++){
            map[i][j] = inp[j]-'0';
        }
    }

    getWays(0,0);

    cout << ans << "\n";
    return 0;
}