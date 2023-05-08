#include <iostream>
#include <queue>

int s,e;
int t = -1,cnt;

bool visit[200001];

void bfs(){
    std::queue<std::pair<int,int>> q;
    q.push({s,0});
    visit[s] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        visit[cur] = true;

        if(cnt && cur == e && t == time){
            cnt++;
        }
        
        if(!cnt && cur == e){
            t = time;
            cnt++;
        }

        if(cur*2 <= 100000 && !visit[cur*2]){
            q.push({cur*2,time+1});
        }

        if(cur + 1 <= 100000 && !visit[cur+1]){
            q.push({cur+1,time+1});
        }
        
        if(cur -1 >= 0 && !visit[cur-1]){
            q.push({cur-1,time+1});
        }
    }
}

int main(){

    std::cin >> s >> e;
    bfs();
    std::cout << t << "\n" << cnt << "\n";
    return 0;
}