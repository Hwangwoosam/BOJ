#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int,vector<int>,greater<int>> node[100001];
int result[100001];
bool visited[100001];

void dfs(int cur){

    int nextSize = node[cur].size();
    visited[cur] = true;

    // cout << "cur: " << cur << "\n";
    for(int i = 0; i < nextSize; i++){
        int idx = node[cur].top();
        node[cur].pop();

        if(visited[idx]) continue;
        result[idx] = result[cur] + 1;
        // cout << result[idx] << " " << result[cur] << "\n";
        dfs(idx);
    }

}

int main(){
    int n,m,r;
    cin >> n >> m >> r;

    memset(result,-1,sizeof(result));
    result[r] = 0;

    for(int i = 0; i < m; i++){
        int from,to;
        cin >> from >> to;
        node[from].push(to);
        node[to].push(from);
    }

    dfs(r);

    for(int i = 1 ; i <= n; i++){
        cout << result[i] << "\n";
    }
    return 0;
}