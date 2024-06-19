#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100001];
int dp[100001];
int rdp[100001];
int preSum[100001];
int nextSum[100001];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
        rdp[i] = arr[i];
    }

    for(int i = 2; i <=n; i++){
        dp[i] = max(dp[i],dp[i-1] + arr[i]);
    }

    for(int i = n-1; i > 0; i--){
        rdp[i] = max(rdp[i],rdp[i+1] + arr[i]);
    }

    // cout << "---dp---\n";
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    // cout << "---rdp---\n";
    // for(int i = 1; i <= n; i++){
    //     cout << rdp[i] << " ";
    // }
    // cout << "\n";

    preSum[1] = dp[1];
    nextSum[n] = rdp[n];


    for(int i = n-1; i > 0; i--){
        nextSum[i] = max(nextSum[i+1],rdp[i]);
    }    

    int ans = INT_MIN;
    for(int i = 2; i <= n-1; i++){
        preSum[i] = max(preSum[i-1],dp[i]);
        ans = max(ans,preSum[i-1] + nextSum[i+1]);
    }

    cout << ans << "\n";

    return 0;
}