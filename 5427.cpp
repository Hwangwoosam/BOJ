#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int fire[1000][1000];
int person[1000][1000];
int visit[1000][1000];
char map[1000][1000];

int dir[4][2] = {1,0,0,1,-1,0,0,-1};


int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);
    
    int test_n;
    cin >> test_n;
    for(int i = 0; i < test_n; i++){
        queue<pair<int,int>> a;
        string str;
        int start_x,start_y;
        for(int j = 0; j < 1000; j++){
            memset(fire[j],1,sizeof(int)*1000);
            memset(person[j],1,sizeof(int)*1000);
            memset(map[j],0,sizeof(char)*1000);
            memset(visit[j],0,sizeof(int)*1000);
        }
        int w, h;
        cin >> w >> h;
        for(int j = 0; j < h; j++){
             cin >> map[j]; 
            for(int k = 0; k < w; k++){ 
                if(map[j][k] == '*'){
                    fire[j][k] = 1;
                    a.push({j,k});                
                }else if(map[k][j] == '@'){
                    person[j][k] = 1;
                    start_y = j;
                    start_x = k;
                }
            }
        }
        while(!a.empty()){
            int cur_x = a.front().first;
            int cur_y = a.front().second;
            visit[cur_x][cur_y] = 1;
            a.pop();
            for(int i = 0; i < 4; i ++){
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if(next_x < 0 || next_x >= h || next_y < 0 || next_y >=w || map[next_x][next_y] =='#' || visit[next_x][next_y] == 1){
                    continue;
                }
                if(map[next_x][next_y] != '.' && map[next_x][next_y] != '@'){
                    continue;
                }
                if(fire[next_x][next_y] > fire[cur_x][cur_y]+1){
                    fire[next_x][next_y] = fire[cur_x][cur_y] +1;
                }
                a.push({next_x,next_y});
            }
        }
         for(int j = 0; j < 1000; j++){
            memset(visit[j],0,sizeof(int)*1000);
        }

        a.push({start_x,start_y});
        int flag = 0;
        while(!a.empty()){
            int cur_x = a.front().first;
            int cur_y = a.front().second;
            visit[cur_x][cur_y] = 1;
            a.pop();
            for(int i = 0; i < 4; i ++){
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if(next_x < 0 || next_x >= h || next_y < 0 || next_y >=w || map[next_x][next_y] =='#' || visit[next_x][next_y] == 1){
                    continue;
                }
                if(map[next_x][next_y] != '.' && map[next_x][next_y] != '@'){
                    continue;
                }
                if(person[next_x][next_y] + 1 < fire[cur_x][cur_y]){
                    person[next_x][next_y] = person[cur_x][cur_y] +1;
                }
                if(next_x == h-1 || next_y == w-1){
                    printf("%d\n",person[next_x][next_y]);
                    flag = 1;
                    break;
                }
                a.push({next_x,next_y});
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            printf("IMPOSSIBLE\n");
        }
        
    }
 


    
}