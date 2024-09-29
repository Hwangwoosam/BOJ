#include <iostream>
#include <vector>

using namespace std;

int dp[5000];
vector<int> prettyNums;

bool isPretty(int num){
    int sum = 0;
    int numCpy = num;
    while(numCpy > 0){
        sum += numCpy%10;
        numCpy /= 10;
    }

    if(num % sum == 0) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,k;
    cin >> m >> k;

    for(int i = 1; i <= m; i++){
        if(isPretty(i)){
            prettyNums.push_back(i);
        }
    }

    int pSize = prettyNums.size();
    dp[0] = 1;

    for(int i = 1; i <= pSize; i++){
        for(int j = 1; j <= m; j++){
            if(j >= prettyNums[i-1]){
                dp[j] = (dp[j] + dp[j-prettyNums[i-1]])%k;
            }
        }
    }

    cout << dp[m] << "\n";

    return 0;
}