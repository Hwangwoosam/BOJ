#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

long long dist[100001];
vector<int> test;

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        dist[i] = LONG_MAX;
    }


    vector<vector<pair<int,int>>> city(n+1);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<>>  pq;

    for(int i = 0; i < m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        city[v].push_back({c,u});
    }
    
    for(int i = 0; i < k; i++){
        int idx;
        cin >> idx;
        pq.push({0,idx});
        dist[idx] = 0;
    }

    while (!pq.empty())
    {
        long long curIdx = pq.top().second;
        long long curCost = pq.top().first;
        pq.pop();

        if(dist[curIdx] < curCost) continue;

        for(int i = 0; i < city[curIdx].size(); i++){
            long long next = city[curIdx][i].second;
            long long nextCost = city[curIdx][i].first + curCost;

            if(dist[next] > nextCost){
                pq.push({nextCost,next});
                dist[next] = nextCost;
            }
        }
    }
    
    long long maxIdx = 0,maxDist = 0;
    for(int i = 1; i <=n; i++){
        if(maxDist < dist[i]){
            maxIdx = i;
            maxDist = dist[i];
        }
    }

    cout << maxIdx << "\n" << dist[maxIdx] << "\n";


    return 0;
}