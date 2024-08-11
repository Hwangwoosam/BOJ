#include <iostream>
#include <climits>

using namespace std;

int arr[1001][3];
int dp[1001][3];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int ans = INT_MAX;
    for(int st = 0; st <= 2; st++){
        for(int i =0; i <=2; i++){
            if(i== st) dp[1][i] = arr[1][i];
            else dp[1][i] = INT_MAX/2;
        }   
        for(int i = 2; i <= n; i++){
            dp[i][0] = arr[i][0] + min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = arr[i][1] + min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = arr[i][2] + min(dp[i-1][0],dp[i-1][1]);
        }

        for(int i = 0; i <=2; i++){
            if(i == st) continue;
            ans = min(ans,dp[n][i]);
        }
    }
    
    cout << ans << "\n";
    return 0;
}