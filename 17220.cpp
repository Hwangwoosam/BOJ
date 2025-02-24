#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n,m,ans;
vector<int> graph[26];
vector<int> header;
// map<char,int> m;
int outDegree[26];
bool visited[26];

void dfs(int idx){
    for(int i = 0; i < graph[idx].size(); i++){
        int next = graph[idx][i];
        if(visited[next]) continue;
        ans++;
        dfs(next);
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        char to,from;
        cin >> from >> to;
        graph[from-'A'].push_back((to-'A'));
        outDegree[to-'A']++;
    }

    for(int i = 0; i < n; i++){
        if(outDegree[i] == 0) header.push_back(i);
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        char inp;
        cin >> inp;
        visited[inp-'A'] = true;
    }

    for(int i = 0; i < header.size(); i++){
        int root = header[i];
        if(!visited[root]){
            visited[root] = true;
            dfs(root);
        }
    }

    cout << ans << "\n";
}