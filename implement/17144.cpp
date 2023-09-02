#include <iostream>
#include <queue>

using namespace std;

int r,c,t, totalDust = 0;
int map[51][51];
int add[51][51];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int air[2];

void spreadDust(){
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j++){
            if(map[i][j] >= 5){
                int cnt = 0;
                int val = map[i][j]/5;

                for(int k = 0; k < 4; k++){
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];

                    if(nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) continue;
                    if(map[nextX][nextY] == -1) continue;

                    add[nextX][nextY] += val;
                    cnt++;
                }
                add[i][j] -= cnt*val;
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            map[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void airCleaner(){
    totalDust -= map[air[0]-1][0];
    totalDust -= map[air[1]+1][0];

    //위 
    for(int i = air[0]-1; i > 0; i--){
        map[i][0] = map[i-1][0];
    }

    for(int i = 0; i < c-1; i++){
        map[0][i] = map[0][i+1];
    }

    for(int i = 1; i <= air[0]; i++){
        map[i-1][c-1] = map[i][c-1];
    }

    for(int i = c-1; i > 1; i--){
        map[air[0]][i] = map[air[0]][i-1];
    }

    //아래
    for(int i = air[1]+1; i < r-1; i++){
        map[i][0] = map[i+1][0]; 
    }

    for(int i = 0; i < c-1; i++){
        map[r-1][i] = map[r-1][i+1];
    }

    for(int i = r-1; i > air[1]; i--){
        map[i][c-1] = map[i-1][c-1];
    }

    for(int i = c-1; i > 1 ; i--){
        map[air[1]][i] = map[air[1]][i-1];
    }

    map[air[0]][1] = 0;
    map[air[1]][1] = 0;
}

int main(){
    cin >> r >> c >> t;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                if(air[0] == 0){
                    air[0] = i;
                }else{
                    air[1] = i;
                }
            }else if(map[i][j] > 0){
                totalDust += map[i][j];
            }
        }
    }
    
    for(int i = 0; i < t; i++){
        spreadDust();
        airCleaner();
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                cout << map[j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << totalDust << "\n";
    return 0;
}