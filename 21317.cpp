#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> jump(21);

int dp[25][2];

int main(){
    int n,k;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int s,l;
        cin >> s >> l;
        jump[i+1] = {s,l};
    }

    cin >> k;

    for(int i = 0; i <= n; i++){
        dp[i][0] = 100000;
        dp[i][1] = 100000;
    }

    dp[1][0] = 0;
    dp[2][0] = jump[1].first;
    dp[3][0] = min(jump[1].second, jump[1].first + jump[2].first);

    for(int i = 4; i <= n; i++){
        dp[i][0] = min(jump[i-1].first + dp[i-1][0],jump[i-2].second+dp[i-2][0]);
        dp[i][1] = min(min(jump[i-1].first + dp[i-1][1],jump[i-2].second + dp[i-2][1]),k + dp[i-3][0]);
    }

    cout << min(dp[n][0],dp[n][1]) << "\n";
    return 0;
}