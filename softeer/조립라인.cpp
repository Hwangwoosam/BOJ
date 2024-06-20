#include <iostream>
#include <vector>

using namespace std;

int n;

// 0: a , 1: b
int worktime[2][1001];
int movetime[2][1001];
int dp[2][1001];

int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        int ai,bi,mab,mba;
        cin >> ai >> bi >> mab >> mba;
        worktime[0][i] = ai;
        worktime[1][i] = bi;
        movetime[0][i] = mab;
        movetime[1][i] = mba;
    }

    cin >> worktime[0][n] >> worktime[1][n];
    dp[0][1] = worktime[0][1];
    dp[1][1] = worktime[1][1];
   
    for(int i = 2; i <= n; i++){
        dp[0][i] = min(dp[0][i-1] , dp[1][i-1] + movetime[1][i-1]) + worktime[0][i];
        dp[1][i] = min(dp[1][i-1] , dp[0][i-1] + movetime[0][i-1]) + worktime[1][i];
    }

    int answer = min(dp[0][n] ,dp[1][n]);
    cout << answer << "\n";
    return 0;
}