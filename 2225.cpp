#include <iostream>
#include <algorithm>

#define MOD 1000000000

using namespace std;

int dp[201][201];

// dp[1] = 1; 1
// dp[2] = 2; 1+1,2
// dp[3] = 4; 1+1+1,2+1,1+2,3
// dp[4] = 5; 1+1+1+1,2+2,1+3,3+1,4
// dp[5] = 14;
// 5       ) 1*1
// 1+4,2+3 ) 2*2
// 1+1+3, 1+2+2 ) 2*3
// 1+1+1+2 ) 1*4
// 1+1+1+1+1 ) 1*1
int main(){
    int n,k;
    cin >> n >> k;

    for(int i = 0; i <= k; i++) dp[1][i] = i;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <=k; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}