#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int>> graph[301];
int dp[301][301];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a < b) graph[a].push_back({c,b});
    }

    int stEdgeSize = graph[1].size();
    for(int i = 0; i < stEdgeSize; i++){
        int next = graph[1][i].second;
        int cost = graph[1][i].first;

        dp[next][2] = max(dp[next][2],cost);
    }

    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(dp[j][i] == 0) continue;

            int gSize = graph[j].size();
            for(int k = 0; k < gSize; k++){
                int next = graph[j][k].second;
                int score = graph[j][k].first;

                dp[next][i+1] = max(dp[next][i+1],dp[j][i] + score); 
                // cout << j << "->"  << next << "(" << i << "): " << dp[next][i+1] <<"\n";
            }
        }
    }
    int answer = 0;
    for(int i = 2; i <= m; i++) answer = max(answer,dp[n][i]); 
    // cout << dp[n][m] << "\n";
    cout << answer << "\n";

    return 0;
}