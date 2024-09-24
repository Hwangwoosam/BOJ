#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int map[500][500];
int dp[500][500][5];

int n;
int dx[] = {1,0};
int dy[] = {0,1};

int findWay(int x, int y, int cnt){
    if(x == n-1 && y == n-1){
        if(cnt == 4) return 1;
        return 0;
    }

    if(dp[x][y][cnt] != -1) return dp[x][y][cnt];
    if(map[x][y] == 1) cnt = 1; 

    int ret = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= n || ny >= n) continue;
        
        if(cnt > 0 && cnt < 4) ret = max(ret, findWay(nx,ny, ((map[nx][ny] == cnt+1) ? cnt + 1 : 0)));
        else if(cnt == 4) ret = max(ret,findWay(nx,ny,0)+1);
        else ret = max(ret,findWay(nx,ny,0));
    }

    return dp[x][y][cnt] = ret;
}

int main(){
    cin >> n;

    memset(map,-1,sizeof(map));
    memset(dp,-1,sizeof(dp));

    for(int i = 0; i < n; i++){
        string inp;
        cin >> inp;

        for(int j = 0; j < n; j ++){
            int val;
            if(inp[j] == 'M') val = 1;
            else if(inp[j] == 'O') val = 2;
            else if(inp[j] == 'L') val = 3;
            else if(inp[j] == 'A') val = 4;
            else val = 0;

            map[i][j] = val;
        }
    }

    int result = findWay(0,0, map[0][0] == 1 ? 1 : 0);
    
    cout << result << "\n";

    return 0;
}