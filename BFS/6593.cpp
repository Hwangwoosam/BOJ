#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

char input[31][31][31];
int map[31][31][31];
int visit[31][31][31];

int x,y,z;
int exit_x,exit_y,exit_z;
int L,R,C;

int dir[6][3] = {1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};


void make_map(){
    for(int i = 0; i < L ; i++){
        for(int j = 0; j < R ; j++){
            for(int k = 0; k < C; k++){
                if(input[i][j][k] == 'S'){
                    z = i;
                    x = j;
                    y = k;
                }else if(input[i][j][k] == '#'){
                    map[i][j][k] = -1;
                }else if(input[i][j][k] == 'E'){
                    exit_z = i;
                    exit_x = j;
                    exit_y = k;
                }
            }
        }
    }
}

int BFS(){
    queue<pair<int,pair<int,int>>> a;
    a.push({z,{x,y}});
    visit[z][x][y] = 1;
    
    while(!a.empty()){
        int cur_z = a.front().first;
        int cur_x = a.front().second.first;
        int cur_y = a.front().second.second;
        a.pop();
        
        if(cur_z == exit_z && cur_x == exit_x && cur_y == exit_y){
            return map[cur_z][cur_x][cur_y];
        }

        for(int i = 0; i < 6; i++){
            int next_z = cur_z + dir[i][0];
            int next_x = cur_x + dir[i][1];
            int next_y = cur_y + dir[i][2];
            if(next_z < 0 || next_z >= L || next_x < 0 || next_x >= R || next_y < 0 || next_y >= C || visit[next_z][next_x][next_y] != 0 || map[next_z][next_x][next_y] == -1){
                continue;
            }
            visit[next_z][next_x][next_y] = 1;
            map[next_z][next_x][next_y] = map[cur_z][cur_x][cur_y] + 1;
            a.push({next_z,{next_x,next_y}});     
        }
    }
    return -1;
}
int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);
   
    
    freopen("test.txt","r",stdin);
    while (1){
        cin >> L >> R >> C; 
        if(L == 0 && R == 0 && C == 0){
            break;
        }
        memset(visit,0,sizeof(visit));
        memset(map,0,sizeof(map));

        for(int i = 0; i < L ; i++){
            for(int j = 0; j < R ; j++){
                cin >> input[i][j];
            }
        }
        make_map();

        int result = BFS();
        if(result == -1){
            printf("Trapped!\n");
        }else{
            printf("Escaped in %d minute(s).\n",result);
        }
    }
}