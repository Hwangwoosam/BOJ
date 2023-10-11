#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n,k,l;
// 0: 오른쪽, 1:아래 , 2: 왼쪽, 3: 위
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

// 1: 몸 , 2: 사과
int map[101][101];
bool check[101][101] ={0,};
deque<pair<int,int>> snake;
vector<pair<int,char>> dir;

void printCheck(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(check[i][j]){
                cout << "1"; 
            }else{
                cout << "0";
            }
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printMap(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(){
    int time = 0;
    int dir_idx = 0;
    int idx = 0;
    int cx = 1, cy = 1;

    snake.push_back({1,1});
    check[1][1] = true;

    while(1){
        time++;
        int nx = cx + dx[dir_idx];
        int ny = cy + dy[dir_idx];

        if(nx < 1 || ny < 1 || nx > n || ny > n || check[nx][ny] == true) break;

        cx = nx;
        cy = ny;

        check[nx][ny] = true;
        snake.push_front({nx,ny});

        if(map[nx][ny] == 0){
            int tx = snake.back().first;
            int ty = snake.back().second;
            check[tx][ty] = false;
            snake.pop_back();
        }else{
            map[nx][ny] = 0;
        }

        if(time == dir[idx].first){
            if(dir[idx].second == 'D'){
                dir_idx++;
                if(dir_idx > 3){
                    dir_idx = 0;
                }
            }else{
                dir_idx--;
                if(dir_idx < 0){
                    dir_idx = 3;
                }
            }

            idx++;
        }
    }

    cout << time << '\n';
}

int main(){

    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int col,row;
        cin >> col >> row;
        map[col][row] = 2;        
    }

    int t;
    char d;
    
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> t >> d;
        dir.push_back({t,d});
    }

    dfs();
    

    return 0;
}