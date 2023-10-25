#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int dp[10001];
vector<int> coins;


int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for(int i = 1; i <= k ;i ++){
        dp[i] = 10001;
    }

    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= k; j++){
            dp[j] = min(dp[j],dp[j-coins[i]]+1);
        }
    }
    if(dp[k] == 10001){
        cout << "-1\n";
    }else{
        cout << dp[k] << "\n";
    }
    return 0;
}