#include <iostream>
#include <vector>

using namespace std;

int n,m;
int board1[10][10];
int board2[10][10];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

vector<pair<int,int>> cctv;

bool OOB(int a,int b){ //Out Of Bounds
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || board2[x][y] == 6) return;
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

void BoardCopy(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board2[i][j] = board1[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int totalNum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board1[i][j];
            if(board1[i][j] >= 1 && board1[i][j] <= 5) cctv.push_back({i,j});
            if(board1[i][j] == 0) totalNum++;
        }
    }

    int cctvSize = cctv.size();

    for(int tmp = 0; tmp < (1<<(2*cctvSize)); tmp++){
        BoardCopy();

        int brute = tmp;
        for(int i = 0; i < cctvSize; i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;

            switch (board1[x][y])
            {
            case 1:
                upd(x,y,dir);
                break;
            case 2:
                upd(x,y,dir);
                upd(x,y,dir+2);
                break;
            
            case 3:
                upd(x,y,dir);
                upd(x,y,dir+1);
                break;
            case 4:
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                break;
            case 5:
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
                break;
            }
        }

        int val = 0;
        for(int i=0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                val += (board2[i][j] == 0);
            }
        }

        totalNum = min(totalNum,val);
    }

    cout << totalNum << "\n";
    return 0;
}