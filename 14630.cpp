#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector<string> state;
vector<int> cost;
int n;

int getCost(int sIdx,int eIdx){
    string s = state[sIdx];
    string e = state[eIdx];

    int sSize = s.size();
    int res = 0;
    for(int i = 0; i < sSize; i++){
        res += pow(s[i]-e[i],2);
    }

    return res;
}

void dijkstra(int s,int e){
    priority_queue<pair<int,int>> pq;
    pq.push({s,0});

    cost[s] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int curCost = pq.top().second;

        pq.pop();

        for(int i = 1; i <= n; i++){
            if(i == s) continue;

            int next = i;
            int nextCost = curCost + getCost(cur,next);
        
            if(cost[next] > nextCost){
                cost[next] =  nextCost;
                pq.push({next,nextCost});
            }
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;

    state.resize(n+1);
    cost.resize(n+1,INT_MAX);

    for(int i = 1; i <= n; i++){
        cin >> state[i];
    }

    int s,e;
    cin >> s >> e;

    dijkstra(s,e);

    cout << cost[e] << "\n";
    return 0;
}