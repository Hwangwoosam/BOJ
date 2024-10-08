// #include <iostream>
// #include <vector>
// #include <tuple>

// using namespace std;

// int dx[] = {0,0,-1,1};
// int dy[] = {1,-1,0,0};

// int map[12][12];

// int n,k;
// vector<tuple<int,int,int>> board[12][12];
// tuple<int,int,int,int> player[12];

// void move(int curX,int curY, int nX,int nY, int idx){
//     int curCnt = board[curX][curY].size();
//     for(int i = idx; i < curCnt; i++){


//     }
// }

// int main(){
//     cin >> n >> k;

//     for(int i = 0; i < n ; i++){
//         for(int j = 0; j < n; j++){
//             cin >> map[i][j];
//         }
//     }

//     for(int i = 0; i < k; i++){
//         int x,y,d;
//         cin >> x >> y >> d;

//         player[i] = make_tuple(x,y,i,d);
//         board[x][y].push_back(make_tuple(x,y,d));
//     }

//     int t = 0;
//     int pIdx = 0;
//     while(1){
//         if(t > 1000) break;


//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std; 
#define x first
#define y second 
typedef struct{int x, y, th, dir;} piece;   // 말의 정보를 나타내는 구조체
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int board[12][12];int n, m; 
void move(vector<piece> pieces[][12], pair<int, int> cur, pair<int, int> nx, int th){ // cur 위치에 있는 th번째 말과 위에 올려져 있는 말들을 nx로 이동시키는 함수    

for(auto iter = pieces[cur.x][cur.y].begin() + th; iter != pieces[cur.x][cur.y].end();){ // th번째 말부터 nx 위치에 쌓음        
        (*iter).x = nx.x; (*iter).y = nx.y; // 말의 좌표 수정        
        pieces[nx.x][nx.y].push_back((*iter));  // nx 위치에 쌓음        
        iter = pieces[cur.x][cur.y].erase(iter);    // 현재 위치의 말 제거    
    }
} 

int main(){    
    ios::sync_with_stdio(0);    
    cin.tie(0);     
    cin >> n >> m;    
    for(int i = 0; i < n; i++)        
        for(int j = 0; j < n ; j++)            
            cin >> board[i][j];        
    
    vector<piece> pieces[12][12];    
    for(int i = 0; i < m; i++){        
        piece p; cin >> p.x >> p.y >> p.dir;        
        p.th = i;        
        p.x--; p.y--; p.dir--;        
        pieces[p.x][p.y].push_back(p);    
    }     
    
    int t = 0;   
     while(true){        
        if(t > 1000) {t = -1; break;}        
        for(int th = 0; th < m;){            
            for(int i = 0; i < n; i++){                
                for(int j = 0; j < n; j++){                    
                    for(int k = 0; k < pieces[i][j].size(); k++){                        
                        piece p = pieces[i][j][k];                        
                        if(p.th == th){                            
                            pair<int, int> nx = {p.x + dx[p.dir], p.y + dy[p.dir]}; // 이동하려는 칸                            
                            th++; // 이동시키려는 말 번호 증가      

                            if((nx.x < 0 || nx.y <0 || nx.x >= n || nx.y >= n) || board[nx.x][nx.y] == 2){    // 다음 칸이 파란색이거나 체스판을 벗어나는 경우                                
                                if(pieces[i][j][k].dir % 2 == 0) pieces[i][j][k].dir++; // 방향 바꿈                                
                                else pieces[i][j][k].dir--;                                 
                            
                                nx = {p.x + dx[pieces[i][j][k].dir], p.y + dy[pieces[i][j][k].dir]};    
                            // 방향 바꾼 후, 다음 칸                                 
                            // 이동하려는 칸이 파란색이거나, 체스판을 벗어나는 경우 이동하지 않는다.                                
                                if(nx.x < 0 || nx.y <0 || nx.x >= n || nx.y >= n || board[nx.x][nx.y] == 2) continue;                                 
                                
                                int s = pieces[nx.x][nx.y].size();                                
                                move(pieces, {i, j}, nx, k); // 다음 칸에 th번째 말과 그 위에 있는 말들을 옮김                                                                
                                
                                if(board[nx.x][nx.y] == 1)  // 다음 칸이 빨간색인 경우                                    
                                    reverse(pieces[nx.x][nx.y].begin() + s, pieces[nx.x][nx.y].end()); // 위에 있던 말의 순서를 바꿈                            
                            
                            }else if(board[nx.x][nx.y] == 0 || board[nx.x][nx.y] == 1){ // 다음 칸이 흰색 또는 빨간색인 경우                                
                                
                                int s = pieces[nx.x][nx.y].size();                                
                                move(pieces, {i, j}, nx, k);    // 다음 칸에 th번째 말과 그 위에 있는 말들을 옮김                                                                

                                if(board[nx.x][nx.y] == 1)  // 다음 칸이 빨간색인 경우                                    
                                    reverse(pieces[nx.x][nx.y].begin() + s, pieces[nx.x][nx.y].end()); // 위에 있던 말의 순서를 바꿈                            
                            }  

                            if(pieces[nx.x][nx.y].size() >= 4) {cout << ++t; return 0;} // 말이 4개 이상 쌓이는 순간 게임 종료                        
                        }                    
                    }                
                }            
            }        
        }               
        t++;    
    }    
    cout << t << "\n";

    return 0;
}
