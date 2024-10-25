#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<vector<int>> graph;
bool visited[100001];

bool ans = false;

void dfs(int idx){

    if(visited[idx]) return;

    stack<int> st;
    st.push(idx);

    while(!st.empty()){
        int cur = st.top();
        st.pop();



        int nSize = graph[cur].size();
        if(nSize == 0){
            ans = true;
            break;
        }

        for(int i = 0; i < nSize; i++){
            if(visited[graph[cur][i]]) continue;

            st.push(graph[cur][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    graph.resize(n+1,vector<int>());
    for(int i = 0 ; i < m; i++){
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int s;
    cin >> s;

    for(int i = 0; i < s; i++){
        int idx;
        cin >> idx;
        visited[idx] = true;
    }

    dfs(1);
    if(ans) cout <<"yes\n";
    else cout << "Yes\n";
    return 0;
}