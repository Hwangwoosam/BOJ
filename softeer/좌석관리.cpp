#include <iostream>
#include <sstream>
#include <climits>
#include <vector>

using namespace std;

int n,m,q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int map[21][21];

// 0: 안먹, 1: 자리잡음, 2: 이미 다먹음
int user[10001]; // 상태
pair<int,int> location[10001]; //좌표
vector<pair<int,int>> curSeat; // 앉은 자리 좌표

int getDist(int x,int y){
    int vSize = curSeat.size();
    int minVal = INT_MAX;
    
    for(int i = 0; i < vSize; i++){
        int curDist = (curSeat[i].first - x)*(curSeat[i].first - x) + (curSeat[i].second - y)*(curSeat[i].second - y);
        if(minVal > curDist) minVal = curDist;
    }

    return minVal;
}

bool findSeat(int idx){
    int x = -1, y = -1;

    if(curSeat.size() != 0){
        int maxVal = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(map[i][j] > 0) continue;
                int curDist = getDist(i,j);
                if(maxVal < curDist){
                    maxVal = curDist;
                    x = i;
                    y = j;
                }
            }
        }
    }else{
        x = 1, y = 1;
    }


    if( x == -1 && y == -1){
        return false;
    }

    user[idx] = 1;
    curSeat.push_back({x,y});
    location[idx] = {x,y};
    map[x][y]++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;

        map[nx][ny]++;
    }

    return true;
}

int main(){
    cin >> n >> m >> q;
    cin.ignore(100,'\n');

    for(int i = 0; i < q; i++){
        string inp;
        getline(cin,inp);
        istringstream iss(inp);
        string cmd;
        int id;
        iss >> cmd >> id;

        if(cmd == "In"){
            if(user[id] == 0){
                if(findSeat(id)){
                    cout << id << " gets the seat (" << location[id].first << ", " << location[id].second << ").\n";
                }else{
                    cout << "There are no more seats.\n";
                }
            }else if(user[id] == 1){
                cout << id << " already seated.\n";
            }else if(user[id] == 2){
                cout << id << " already ate lunch.\n";
            }
        }else if(cmd == "Out"){
            if(user[id] == 0){
                cout << id << " didn't eat lunch.\n";
            }else if(user[id] == 1){
                cout << id << " leaves from the seat (" << location[id].first << ", " << location[id].second << ").\n";

                user[id] = 2;
                map[location[id].first][location[id].second]--;
                
                for(int j = 0; j < 4; j++){
                    int nx = location[id].first + dx[j];
                    int ny = location[id].second + dy[j];
                    if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                    map[nx][ny]--;
                }

                int cSize = curSeat.size();
                for(int j = 0; j< cSize; j++){
                    if(curSeat[j].first == location[id].first && curSeat[j].second == location[id].second){
                        curSeat.erase(curSeat.begin() + j);
                        break;
                    }
                }

                location[id] = {0,0};
            }else if(user[id] == 2){
                cout << id << " already left seat.\n";
            }
        }
    }

    return 0;
}