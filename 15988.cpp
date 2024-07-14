#include <iostream>

#define MOD 1000000009

using namespace std;

long long dp[1000001];

int main(){
    int t;
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%MOD;
    }

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}