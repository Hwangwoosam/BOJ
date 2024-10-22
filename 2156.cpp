#include <iostream>
#include <vector>

using namespace std;

vector<int> drinks;
int dp[10001]; 
//연속 포함 개수(0,1,2)
// dp[i] = i번쨰는 무조건 마신다.

int main(){
    int n;
    cin >> n;

    drinks.resize(n+1,0);
    for(int i = 1; i <= n; i++) cin >> drinks[i];

    dp[1] = drinks[1];
    dp[2] = dp[1]+drinks[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-3] + drinks[i-1] + drinks[i],dp[i-2] + drinks[i]);
        dp[i] = max(dp[i],dp[i-1]);
    }
    cout << dp[n] << "\n";


    return 0;
}