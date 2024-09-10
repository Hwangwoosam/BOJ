#include <iostream>
#include <queue>

using namespace std;

int map[50][50]; //10^8*4 byte --> 1mb == 2^8*1024 ~ 10^5
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int r1,c1,r2,c2;
int maxLen = 0;

void setMap(){
    int dir = 0;
    int sizeCondition = 0;
    int sizeLen = 1;
    
    queue<pair<int,int>> q;
    q.push({0,0});
    int idx = 1;

    if(0 >=r1 && 0 <= r2 && 0 >= c1 && 0 <= c2) map[0-r1][0-c1] = 1;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        int nx = curX;
        int ny = curY;

        for(int i = 0; i < sizeLen; i++){
            nx = nx + dx[dir];
            ny = ny + dy[dir];
            idx++;

            if(nx >= r1 && nx <= r2 && ny >= c1 && ny <= c2){
                int numLen = to_string(idx).length();
                if(maxLen < numLen) maxLen = numLen;
                // cout << nx-r1 << " " << ny-c1 << " " << idx <<  "\n";
                map[nx-r1][ny-c1] = idx;
            }
        }
        
        dir = (dir+1)%4;
        sizeCondition++;
        if(sizeCondition == 2){
            sizeCondition = 0;
            sizeLen++;
        } 


        if(nx < -5000 || nx > 5000 || ny < -5000 || ny > 5000) continue;
        q.push({nx,ny});
    }
}

int main(){
    cin >> r1 >> c1 >> r2 >> c2;

    setMap();
    for(int i = 0; i <= r2-r1; i++){
        for(int j = 0; j <= c2-c1; j++){
            cout.width(maxLen);
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }   

    return 0;
}