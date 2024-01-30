#include <iostream>

using namespace std;
int dp[1000001];
int path[1000001];

int main(){
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        path[i] = i-1;

        if(i%2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            path[i] = i/2;
        }

        if(i%3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            path[i] = i/3;
        }
    }

    cout << dp[n] << "\n";
    int cur = n;
    while(true){
        cout << cur << ' ';
        if(cur == 1) break;
        cur = path[cur];
    }

    return 0;
}