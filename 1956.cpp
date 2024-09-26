#include <iostream>
// #include <climits>
#include <vector>

using namespace std;

#define INF 1e9

int graph[401][401];

int main(){
    int v,e;
    cin >> v >> e;

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++) graph[i][j] = INF;
    }

    for(int i = 0; i < e; i++){
        int from,to,w;
        cin >> from >> to >> w;
        graph[from][to] = w;
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                if(graph[i][k] + graph[k][j] < graph[i][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int res = INF;
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i == j) continue;
            res = min(res,graph[i][j] + graph[j][i]);
        }
    }

    res = (res == INF) ? -1 : res;

    cout << res << "\n";

    return 0;
}