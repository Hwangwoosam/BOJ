#include <iostream>

using namespace std;

int rock[3001];
int dp[3001];
int n,answer = 0;

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> rock[i];
        dp[i] = 1;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(rock[j] < rock[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++){
        answer = max(answer,dp[i]);
    }
    cout << answer << "\n";
    return 0;
}