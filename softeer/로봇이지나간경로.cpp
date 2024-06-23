#include <iostream>
#include <string>
#include <vector>

using namespace std;

int w,h;

// 북동남서
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool visited[25][25];
vector<string> map;
vector<pair<int,int>> track;

int startX,startY,startD;
int resultX,resultY,resultD;
string resultCommand = "-1";

// L : 로봇이 왼쪽으로 90도 회전
// R : 로봇이 오른쪽으로 90도 회전
// A : 바라보는 방향으로 두칸 전진한다.

void findWay(int curX,int curY, int dir,int cnt,string command){
    if(track.size() == cnt){
        if(resultCommand == "-1" || resultCommand.size() > command.size()){
            resultX = startX;
            resultY = startY;
            resultD = startD;
            resultCommand = command;
        }
        return;
    }

    // cout << "cur: " << curX << " " << curY << "\n";
    // cout << "cnt: " << cnt << "\n";

    for(int i = 0; i < 4; i++){
        int nd = (dir+i)%4;
        
        string nCommand = "A";
        if(i == 1) nCommand = "RA";
        else if(i== 2) nCommand = "RRA";
        else if(i== 3) nCommand = "LA";

        int nx1 = curX + dx[nd];
        int ny1 = curY + dy[nd];

        int nx2 = curX + 2*dx[nd];
        int ny2 = curY + 2*dy[nd];

        if(nx1 < 0 || nx1 >= h || ny1 < 0 || ny1 >= w) continue;
        if(nx2 < 0 || nx2 >= h || ny2 < 0 || ny2 >= w) continue;
        if(map[nx1][ny1] == '.' || map[nx2][ny2] == '.') continue;
        if(visited[nx1][ny1] || visited[nx2][ny2] ) continue;

        visited[nx1][ny1] = true;
        visited[nx2][ny2] = true;
        findWay(nx2,ny2,nd,cnt+2, command + nCommand);
        visited[nx1][ny1] = false;
        visited[nx2][ny2] = false;
    }
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        string inp;
        cin >> inp;
        map.push_back(inp);
        for(int j = 0; j < w; j++){
            if(inp[j] == '#'){
                track.push_back({i,j});
            }
        }
    }

    int tSize = track.size();
    vector<char> command;
    vector<pair<pair<int,int>,int>> record;
    for(int i = 0; i < tSize; i++){
        int curX = track.at(i).first;
        int curY = track.at(i).second;
        startX = curX;
        startY = curY;
        for(int j = 0; j < 4; j++){
            startD = j;
            visited[curX][curY] = true;
            findWay(curX,curY,j,1,"");
            visited[curX][curY] = false;
        }
    }

    cout << resultX+1 << " " << resultY+1 << "\n";

    if(resultD == 0)        cout << "^\n";
    else if(resultD == 1)   cout << ">\n";
    else if(resultD == 2)   cout << "v\n";
    else if(resultD == 3)   cout << "<\n";
    
    cout << resultCommand << "\n";
    return 0;
}