#include <iostream>
#include <vector>

using namespace std;

long long dp[20001];

int main(){
    long n,m,k;
    cin >> n >> m >> k;

    vector<long long> oranges(n+1);
    // K + s*(a-b)
    for(int i = 1; i <= n; i++){
        cin >> oranges[i];
        dp[i] = k*i;
    }

    for(int i = 0; i < n; i++){
        long long minVal = oranges[i+1], maxVal = oranges[i+1];

        for(int j = 1; j <= m && i+j <= n; j++){
            if(minVal > oranges[i+j]) minVal = oranges[i+j];
            if(maxVal < oranges[i+j]) maxVal = oranges[i+j];

            dp[i+j] = min(dp[i+j], dp[i] + k + j*(maxVal - minVal));
        }
    }

    cout << dp[n] << "\n";

    return 0;
}