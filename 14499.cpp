#include <iostream>
#include <vector>

using namespace std;

// 6 = (x,y);
int map[20][20];
int dice[7] = {0,0,0,0,0,0,0};
int n,m;
vector<int> dir;
// 위 북 동 서 남 밑
//  1  2 3  4  5  6
// 동쪽
//  4  2 1  6  5  3
// 서쪽
//  3  2 6  1  5  4
// 남쪽
//  2  6 3  4  1  5
// 북쪽
//  5 1  3  4  6  2
void rollEast(){
    int tmp[7] = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
    for(int i = 0; i < 7; i++){
        dice[i] = tmp[i];
    }
}

void rollWest(){
    int tmp[7] = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
    for(int i = 0; i < 7; i++){
        dice[i] = tmp[i];
    }
}

void rollSouth(){
    int tmp[7] = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
    for(int i = 0; i < 7; i++){
        dice[i] = tmp[i];
    }
}

void rollNorth(){
    int tmp[7] = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
    for(int i = 0; i < 7; i++){
        dice[i] = tmp[i];
    }
}


void rollDice(int x, int y, int k){

    for(int i = 0; i < k; i++){
        // cout << "dice: ";
        // for(int i = 1; i < 7; i++){
            // cout << dice[i] << " ";
        // }
        // cout << "\n";
        // cout << "("<< i <<"):"<< x << " " << y << "\n";
        int idx = dir[i];
        // cout << "idx: " << idx << "\n";
        switch(idx){
            case 1:
                if(y+1 >= m) continue;
                rollEast();
                y++;
                break;
            case 2:
                if(y-1 < 0) continue;
                rollWest();
                y--;
                break;
            case 3:
                if(x-1 < 0) continue;
                rollNorth();
                x--;
                break;
            case 4:
                if(x+1 >= n) continue;
                rollSouth();
                x++;
                break;
        }

        if(map[x][y] != 0){
            dice[6] = map[x][y];
            map[x][y] = 0;
        }else if(map[x][y] == 0){
            map[x][y] = dice[6];
        }

        cout << dice[1] << "\n";
    }

}


int main(){
    int x,y,k;

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        int d;
        cin >> d;
        dir.push_back(d);
    }

    rollDice(x,y,k);

    return 0;
}