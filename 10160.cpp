#include <iostream>

#define MOD 1000000009

using namespace std;

long long dp[1000001];

long long pow(long long k, long long n){
    long long res = 1;
    while(n--){
        res *= k;
        res %= MOD;
    }

    return res;
}

int main(){
    int n,k;
    cin >> n >> k;

    dp[0] = 1;
    for(int i = 1; i <= 5; i++) dp[i] = dp[i-1]*k;
    dp[5] = dp[5]-2;
    dp[6] = (dp[5]*k)%MOD - (2*k)%MOD;

    // dp[i-1]*k = 이전 dp[i-1]는 안전한 암호개수를 구한것에 문자 1개를 추가
    // 2*dp[i-5] = 특정 패턴 2개의 길이가 5이므로 dp[i-5]에서 구한 안전한 암호에 패턴 2개를 추가
    // dp[i-7] = 7부터 ABCBC ABABC 두개의 공통인 ABABCBC가 존재하여 2번 빼지므로 한번 더해준다
    
    for(int i = 7; i <= n; i++){
        dp[i] = ((dp[i-1]*k)%MOD -(2*dp[i-5])%MOD + dp[i-7])%MOD;
        if(dp[i] < 0) dp[i] += 1000000009;
    }
    cout << dp[n] << "\n";

    return 0;
}