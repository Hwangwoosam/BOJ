#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;
int map[101][101];
int visit[101][101];
int dir[4][2] = {-1,0,1,0,0,-1,0,1};

int n;

int make_land(int n){
    int cnt = 1;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                queue<pair<int,int>> a;
                a.push({i,j});
                while(!a.empty()){
                    int cur_x = a.front().first;
                    int cur_y = a.front().second;
                    map[cur_x][cur_y] = cnt;
                    visit[cur_x][cur_y] = 1;
                    a.pop();
                    for(int k = 0; k < 4; k++){
                        int next_x = cur_x + dir[k][0];
                        int next_y = cur_y + dir[k][1];
                        if(next_x < 0 || next_x >=n || next_y < 0 || next_y >= n || visit[next_x][next_y] || map[next_x][next_y] == 0){
                            continue;
                        }
                        visit[next_x][next_y] = 1;
                        a.push({next_x,next_y});
                    }
                }
                cnt++;   
            }
        }
    }
    return cnt;
}

int BFS(int num){
    int result = 0;
    queue<pair<int,int>> a;
    for(int j = 0; j < n; j ++){
        for(int k = 0; k < n; k++){
            if(map[j][k] == num){
                visit[j][k] = 1;
                a.push({j,k});
            }
        }
    }
    while(!a.empty()){
            int size = a.size();
            for(int j=0; j < size; j++){
                int cur_x = a.front().first;
                int cur_y = a.front().second;
                a.pop();
                for(int k = 0; k < 4; k++){
                    int next_x = cur_x + dir[k][0];
                    int next_y = cur_y + dir[k][1];
                    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >=n){
                        continue;
                    }
                    if(map[next_x][next_y] != 0 && map[next_x][next_y] != num){
                        return result;
                    }else if(map[next_x][next_y] == 0 && visit[next_x][next_y] == 0){
                        visit[next_x][next_y] = 1;
                        a.push({next_x,next_y});
                    } 
                }
            }
            result++;
    }
    return 10000;
}


int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);
   
    freopen("test.txt","r",stdin);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int cnt = make_land(n);
    int minimum = 10000;;
    int  answer = 0;

    for(int i = 1 ; i <= cnt; i++){
        memset(visit,0,sizeof(visit));
        int temp = BFS(i);
        minimum = min(minimum,temp);
    }
    printf("%d\n",minimum);

}