#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int pillarLen = 0,branchLen = 0;
vector<pair<int,int>> node[200001];
bool visited[200001];

int findGiga(int r){
    int rootLine = node[r].size();
    if(rootLine >= 2 || rootLine == 0) return r;

    queue<int> q;
    q.push(r);
    visited[r] = true;

    int gigaIdx = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int curSize = node[cur].size();

        if(curSize > 2 || curSize == 0){
            gigaIdx = cur;
            break;
        }

        for(int i = 0; i < curSize; i++){
            if(!visited[node[cur][i].first]){
                visited[node[cur][i].first] = true;
                pillarLen += node[cur][i].second;
                q.push(node[cur][i].first);
            }
        }
    }

    return gigaIdx;
}

void findMaxLen(int g,int len){
    int nSize = node[g].size();

    if(nSize == 1){
        branchLen = max(branchLen,len);
        return;
    }

    for(int i = 0; i < nSize; i++){
        if(visited[node[g][i].first]) continue;

        visited[node[g][i].first] = true;
        findMaxLen(node[g][i].first,len + node[g][i].second);
    }
}

int main(){
    int n,r;
    cin >> n >> r;

    for(int i = 0; i <n-1; i++){
        int a,b,d;
        cin >> a >> b >> d;
        node[a].push_back({b,d});
        node[b].push_back({a,d});
    }

    int gigaIdx = findGiga(r);

    visited[gigaIdx] = true;
    findMaxLen(gigaIdx,0);
    // cout << gigaIdx << "\n";    
    // cout << pillarLen << "\n";
    cout << pillarLen << " " << branchLen << "\n";
    return 0;
}