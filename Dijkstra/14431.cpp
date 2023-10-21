#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

int startX,startY;
int dstX,dstY;

bool Prime[8486];

vector<pair<int,int>> pos;
vector<pair<int,int>> graph[4000];

int getDistance(int x, int y, int a, int b){
    int dis = (abs((x-a)*(x-a))+(abs((y-b)*(y-b))));
    return (int)sqrt(dis);
}


int main(){
    int n = 0;
    cin >> startX >> startY >> dstX >> dstY;
    cin >> n;

    for(int i = 2 ; i < 8486; i++){
        if(Prime[i] == true) continue;

        for(int j = 2*i; j < 8486; j += i){
            Prime[j] = true;
        }
    }

    pos.push_back({startX,startY});

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        pos.push_back({x,y});
    }

    pos.push_back({dstX,dstY});

    for(int i = 0; i < pos.size(); i++ ){
        for(int j = i+1; j < pos.size(); j++){
            int dist = getDistance(pos[i].first,pos[i].second,pos[j].first,pos[j].second);
            if(Prime[dist] == true) continue;

            graph[i].push_back({j,dist});
            graph[j].push_back({i,dist});
        }
    }

    int distance[8486];
    for(int i = 0; i < n+2; i++){
        distance[i] = (int)1e9;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({0,0});
    distance[0] = 0;

    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();

        if(distance[cur.first] < cur.second) continue;

        for(int i = 0; i < graph[cur.first].size(); i++){
            int next_to = graph[cur.first][i].first;
            int next_dist = graph[cur.first][i].second;
            
            if(distance[next_to] > distance[cur.first] + next_dist){
                distance[next_to] = distance[cur.first] + next_dist;
                pq.push({next_to,distance[next_to]});
            }
        }
    }

    if(distance[n+1] != (int)1e9){
        cout << distance[n+1] << "\n";
    }else{
        cout << "-1\n";
    }

    return 0;
}