#include <iostream>

using namespace std;

int n,m,answer = 0;
int map[51][51];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool find(int x,int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(map[nx][ny] == 0) return true;
    }

    return false;
}

void clean(int x,int y, int d){
    int curX = x ;
    int curY = y;
    int curD = d;
    while(true){
        // cout << curX << " " << curY << " " << answer <<"\n";
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "=============\n";
        if(map[curX][curY] == 0){
            answer++;
            map[curX][curY] = 2;
        }

        if(find(curX,curY)){
            // cout <<"find\n";
            curD--;
            if(curD < 0){
                curD = 3;
            } 
            
            int nx = curX + dir[curD][0];
            int ny = curY + dir[curD][1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 1) continue;
            if(map[nx][ny] == 0){
                curX = nx;
                curY = ny;  
            }
        }else{
            // cout <<"not find\n";
            int nx = curX + dir[curD][0] * -1;
            int ny = curY + dir[curD][1] * -1;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if(map[nx][ny] == 1) break;
            curX = nx;
            curY = ny;
        }

    }

}

int main(){
    cin >> n >> m;
    int rx,ry,d;
    cin >> rx >> ry >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    clean(rx,ry,d);
    cout << answer << "\n";
    return 0;
}