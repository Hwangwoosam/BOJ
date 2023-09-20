#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

using namespace std;

int w,h;
int dist[501][501];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<string> map;

struct compare{
    bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        return a.first > b.first;
    }
};

int FindPath(int dir, int x, int y){
    int PathLength = 1;

    while(true){
        int nextX = x + dx[dir]*PathLength;
        int nextY = y + dy[dir]*PathLength;

        if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) break;
        if(map[nextX][nextY] == 'H') break;
        if(map[nextX][nextY] == 'R') return PathLength - 1;
        if(map[nextX][nextY] == 'E') return PathLength;

        PathLength++;
    }

    return -1;
}
int EscapeIce(vector<string> map, pair<int,int> tera , pair<int,int> end){

    int answer = 0;
    bool visited[h][w] = {false,};

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
    pq.push({0,{tera.first,tera.second}});
    dist[tera.first][tera.second] = 0;

    while(!pq.empty()){
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        int distValue = pq.top().first;
        pq.pop();


        if(visited[curX][curY]) continue;
        visited[curX][curY] = true;

        for(int i = 0; i < 4; i++){
            int PossibleMove = FindPath(i,curX,curY);
            if(PossibleMove < 1) continue;

            int sumDist = 0;
            for(int j = 1; j <= PossibleMove; j++){
                if(map[curX + dx[i]*j][curY + dy[i]*j] == 'E') break;
                else sumDist += (map[curX + dx[i]*j][curY + dy[i]*j] - '0');
            }

            int nextX = curX + dx[i]*PossibleMove;
            int nextY = curY + dy[i]*PossibleMove;
            if(dist[nextX][nextY] > sumDist + distValue){
                dist[nextX][nextY] = sumDist + distValue;
                pq.push({dist[nextX][nextY],{nextX,nextY}});
            }
        }
    }

    if(dist[end.first][end.second] == INT32_MAX){
        answer = -1;
    }else{
        answer = dist[end.first][end.second];
    }

    return answer;
}

int main(){
    int result;
    pair<int,int> tera;
    pair<int,int> end;
    cin >> w >> h;

    for(int i = 0; i < h; i++){
        string inp;
        cin >> inp;
        for(int j = 0; j < w; j++){
            dist[i][j] = INT32_MAX;
            if(inp[j] == 'T'){
                tera.first = i;
                tera.second = j;
                inp[j] = '0';
            }else if(inp[j] == 'E'){
                end.first = i;
                end.second = j;
            }
        }
        map.push_back(inp);
    }


    result = EscapeIce(map,tera,end);

    cout << result << "\n";

    return 0;
}