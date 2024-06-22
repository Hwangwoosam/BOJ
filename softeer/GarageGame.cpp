#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int map[45][15];
int answer = 0;

void dfs(int cnt, int sum){
    bool check[15][15]={false,};
    int dup[45][15];
    
    memcpy(dup,map,sizeof(map));

    for(int i = 2*n; i < 3*n; i++){
        for(int j = 0; j < n; j++){
            int cur = dup[i][j];

            if(cur == 0 || check[i-2*n][j]) continue;

            memcpy(map,dup,sizeof(dup));

            int maxX = i;
            int maxY = j;
            int minX = i;
            int minY = j;

            int connect = 1;
            queue<pair<int,int>> q;
            q.push({i,j});
            check[i-2*n][j] = true;

            int depth[15] = {0,};
            while(!q.empty()){
                int curX = q.front().first;
                int curY = q.front().second;
                map[curX][curY] = 0;
                depth[curY]++;
                q.pop();

                maxX = max(maxX,curX);
                maxY = max(maxY,curY);
                minX = min(minX,curX);
                minY = min(minY,curY);

                for(int k = 0; k < 4; k++){
                    int nx = curX + dx[k];
                    int ny = curY + dy[k];

                    if(nx < 2*n || nx >= 3*n || ny < 0 || ny >= n) continue;
                    if(check[nx-2*n][ny]) continue;
                    if(dup[nx][ny] != cur) continue; 
                
                    check[nx-2*n][ny] = true;
                    q.push({nx,ny});
                    connect++;
                }
            }

            if(cnt < 2){
                
                for(int k = minY; k <= maxY; k++){
                    for(int m = maxX; m >= minX; m--){
                        if(map[m][k] != 0) continue;

                        int jump = 0;
                        for(int l = m-1; l >= 0; l--){
                            if(map[l][k]){
                                jump = m-l;
                                break;
                            }
                        }

                        if(jump){
                            for(int l = m; l >= jump; l--){
                                map[l][k] =  map[l-jump][k];
                                map[l-jump][k] = 0;
                            }
                        }
                    }
                }  
                dfs(cnt+1,sum + connect + (maxX - minX + 1) * (maxY - minY + 1));
            }else{
                answer = max(answer,sum + connect + (maxX - minX + 1) * (maxY - minY + 1));
                continue;
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < 3*n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    dfs(0,0);
    cout << answer << "\n";

    return 0;   
}
