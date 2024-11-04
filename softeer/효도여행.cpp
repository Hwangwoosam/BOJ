#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n,m;
string inp;
int dp[5001][5001];
string tree[5001][5001];
bool visited[5001][5001];


vector<string> ways;

bool isLeaf(int cur){
    if(cur == 0) return false;

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(tree[cur][i] != "") cnt++;
    }

    if(cnt == 1) return true;

    return false;
}

void dfs(int cur,string way){
    if(isLeaf(cur)){
        // cout << "way: " << way << "\n";
        ways.push_back(way);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(tree[cur][i] == "") continue;
        if(visited[cur][i]) continue;

        visited[cur][i] = true;
        visited[i][cur] = true;
        way.append(tree[cur][i]);
        dfs(i,way);
        way.pop_back();
        visited[cur][i] = false;
        visited[i][cur] = false;
    }
}

// 3 1 4 2
// 3 1 / 1 4 / 4 2
// 1 3 / 4 1 / 2 4

int LCS(string inp, string way){
    memset(dp,0,sizeof(dp));

    int waySize = way.size();
    int inpSize = inp.size();
    for(int i = 1; i <= inpSize; i++){
        for(int j = 1; j <= waySize; j++){
            // cout << inp.at(i-1) << " " << way.at(j-1) << "\n";
            if(inp.at(i-1) == way.at(j-1)){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[inpSize][waySize];
}

int main(){
    cin >> n >> m;
    cin >> inp;

    for(int i = 0; i < n-1; i++){
        int from,to;
        string c;
        cin >> from >> to >> c;
        tree[from][to] = c;
        tree[to][from] = c;
    }

    string way = "";
    dfs(1,way);

    int totalSize = ways.size();
    int answer = 0;
   
    for(int i = 0; i < totalSize; i++){
        int lcs = LCS(inp,ways.at(i));
        if(lcs > answer) answer = lcs;
    }

    cout << answer << "\n";
    return 0;
}