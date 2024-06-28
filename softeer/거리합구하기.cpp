#include <iostream>
#include <vector>

using namespace std;

int n;
long long result = 0;
 vector<pair<int,long long>> node[200001];
long long dist[200001];
long long subtreeSize[200001];


void getInfo(int cur, int prev){ // 1노드가 루트일 경우 총합 구하기

    subtreeSize[cur] = 1;

    int childSize = node[cur].size();

    for(int i = 0; i < childSize; i++){
        int childIdx = node[cur][i].first;
        long long childVal = node[cur][i].second;

        if(childIdx != prev){
            getInfo(childIdx,cur);
            
            subtreeSize[cur] += subtreeSize[childIdx];
            dist[cur] += dist[childIdx] + childVal * subtreeSize[childIdx];
        }
    }
}

void getDist(int cur, int prev){
    int childSize = node[cur].size();

    for(int i = 0; i < childSize; i++){
        int childIdx = node[cur][i].first;
        long long childVal = node[cur][i].second;

        if(childIdx != prev){
            dist[childIdx] = dist[cur] + childVal*(n-2*subtreeSize[childIdx]); 
            getDist(childIdx,cur);
        }
    }
}

int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        int from,to;
        long long val;
        cin >> from >> to >> val;
        node[from].push_back({to,val});
        node[to].push_back({from,val});
    }

    getInfo(1,0);
    getDist(1,0);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << "\n";
    }
}