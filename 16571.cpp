#include <iostream>
#include <vector>

using namespace std;

int map[3][3];
vector<pair<int,int>> emptyMap;

bool checkResult(int pIdx){
    for(int i = 0; i < 3; i++){
        // 가로
        if(map[i][0] == pIdx && map[i][0] == map[i][1] && map[i][1] == map[i][2]) return true;
        // 세로
        if(map[0][i] == pIdx && map[0][i] == map[1][i] && map[1][i] == map[2][i]) return true;
    }

    //대각선
    if(map[0][0] == pIdx && map[0][0] == map[1][1] && map[1][1] == map[2][2]) return true;
    if(map[0][2] == pIdx && map[0][2] == map[1][1] && map[1][1] == map[2][0]) return true;

    return false;
}


int playGame(int pIdx){

    // cout << "in\n";
    if(checkResult(3-pIdx)) return -1;

    int ret = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // cout << i << " " << j << "\n";
            if(map[i][j] != 0) continue;
            map[i][j] = pIdx;
            ret = min(ret,playGame(3-pIdx));
            // cout << "ret: " << ret << "\n";
            map[i][j] = 0;
        }
    }

    if(ret == 2 || ret == 0) return 0;    
    return -ret;
}

int main(){
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) emptyMap.push_back({i,j});
        }
    }

    int pIdx = 1;
    if(emptyMap.size()%2 == 0) pIdx = 2;

    int ret = playGame(pIdx);

    if(ret == 1) cout <<"W\n";
    else if(ret == 0) cout << "D\n";
    else cout << "L\n";

    return 0;
}