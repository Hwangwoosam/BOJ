#include <iostream>

using namespace std;
//        0 1 2 3 4 5 6
// k = 0  1 , 1
// k = 1  1 1 -  2
// k = 2  1 2 2 1 - 4 
// k = 3  1 3 5 6  5  3  1 - 7
// k = 4  1 4 9 15 20 22 20 15 9 4 1 - 11
// k = 5  1 5 13 28 48 70 90 105 105 90 70 48 28 13 5 1 - 16

// k ,n
long long int dp[25][300];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    dp[0][0] = 1;

    for(int i = 1; i <= 20; i++){
        int idx = 0;
        while(dp[i-1][idx] != 0){
            long long int now_coe = dp[i-1][idx];

            for(int j = 0; j <= i ;j++){
                long long int n_coe = idx + j;
                dp[i][n_coe] += now_coe;
            }

            idx++;
        }
    }

    for(int i = 0; i < t; i++){
        long long n,k;
        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }

    return 0;
}