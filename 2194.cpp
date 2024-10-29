#include <iostream>
#include <queue>

using namespace std;

bool visited[501][501];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int maxVal = 1e8;

bool check(int x,int y,int a,int b,int dir){
    if(dir == 0){
        for(int i = 0; i < b; i++){
            if(visited[x][y+i]) return true;
        }
    }else if(dir == 1){
        for(int i = 0; i < a; i++){
            if(visited[x+i][y+b-1]) return true;
        }
    }else if(dir == 2){
        for(int i = 0; i < b; i++){
            if(visited[x+a-1][y+i]) return true;
        }
    }else{
        for(int i = 0; i < a; i++){
            if(visited[x+i][y]) return true;
        }
    }

    return false;
}

int main(){
    int n,m,a,b,k;
    cin >> n >> m >> a >> b >> k;

    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        visited[x][y] = true;
    }

    int sx,sy,ex,ey;
    cin >> sx >> sy;
    cin >> ex >> ey;

    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});

    if(!visited[sx][sy]){
        visited[sx][sy] = true;

        while(!q.empty()){
            int curX = q.front().first.first;
            int curY = q.front().first.second;
            int curT = q.front().second;
            q.pop();

            if(curX == ex && curY == ey) {
                if(maxVal > curT) maxVal = curT;
                break;    
            }
            for(int i = 0; i < 4; i++){
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if(nx <= 0 || nx+a-1 > n || ny <= 0 || ny+b-1 > m) continue;
                if(check(nx,ny,a,b,i)) continue;
                if(visited[nx][ny]) continue;
                
                q.push({{nx,ny},curT+1});
                visited[nx][ny] = true;
            }
        }
    }
    if(maxVal == 1e8) maxVal = -1;

    cout << maxVal << "\n";

    return 0;
}