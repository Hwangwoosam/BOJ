#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

int n,m,x,y,z;
int dist[3][100001];
vector<pair<int,int>> edge[100001];

void dijkstra(int i, int s, int e){
    priority_queue<pair<int,int>> pq;
    dist[i][s] = 0;
    pq.push({0,s}); 
    while (!pq.empty())
    {
        int curD = -pq.top().first;
        int curX = pq.top().second;
        pq.pop();

        if(i <= 1 && curX == e) return;
        if(dist[i][curX] < curD) continue;

        for(int j = 0 ; j < edge[curX].size(); j++){
            int nextD = edge[curX][j].first;
            int nextX = edge[curX][j].second;

            if(i == 2 && nextX == y) continue;

            if(dist[i][nextX] > curD + nextD){
                dist[i][nextX] = curD + nextD;
                pq.push({-dist[i][nextX],nextX});
            }
        }
    }
    
}

int main(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        dist[0][i] = INT_MAX/2;  // x->y
        dist[1][i] = INT_MAX/2;  // y->z
        dist[2][i] = INT_MAX/2;  // x->z && != y
    }

    for(int i = 1; i <= m; i++){
        int from,to,w;
        cin >> from >> to >> w;
        edge[from].push_back({w,to});
    }

    cin >> x >> y >> z;

    dijkstra(0,x,y);
    dijkstra(1,y,z);
    dijkstra(2,x,z);

    if(dist[0][y] != INT_MAX/2 && dist[1][z] != INT_MAX/2) cout << dist[0][y] + dist[1][z] << " ";
    else cout << "-1 ";

    if(dist[2][z] != INT_MAX/2) cout << dist[2][z] << "\n";
    else cout << "-1\n";

    return 0;
}