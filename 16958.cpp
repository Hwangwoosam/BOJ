#include <iostream>
#include <vector>

using namespace std;

#define MAX 10e7

vector<pair<int,int>> city;
int dist[1001][1001];
bool teleport[1001];

int main(){
    int n,t,m;
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = MAX;
        }
    }

    for(int i = 0; i < n; i++){
        int s,x,y;
        cin >> s >> x >> y;
        city.push_back({x,y});

        if(s == 1) teleport[i] = true;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int val = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
            dist[i][j] = val;
            if(teleport[i] && teleport[j]) dist[i][j] = min(dist[i][j],t);
            dist[j][i] = dist[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = 0; k < n; k++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }


    cin >> m;
    for(int i = 0; i < m; i++){
        int st,end;
        cin >> st >> end;
        cout << dist[st-1][end-1] << "\n";
    }

    return 0;
}