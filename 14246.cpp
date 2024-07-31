#include <iostream>

using namespace std;

long long dp[100001];

int main(){
    int n,k;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        dp[i] = dp[i-1] + tmp;
    }

    cin >> k;

    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        int j = 0;
        while(dp[i] - dp[j] > k){
            cnt ++;
            j++;
            if(i == j) break;
        }
    }

    cout << cnt << "\n";

    return 0;
}