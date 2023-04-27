#include <iostream>

int TC,N;


int dp[2][100001];
int arr[2][100001];

int main(){
    std::cin >> TC;

    for(int i = 0; i < TC; i++){
        std::cin >> N;
        
        
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < N; k++){
                std::cin >> arr[j][k];
            }
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];

        for(int k = 2; k < N; k++){
            dp[0][k] = arr[0][k] + std::max(dp[1][k-1],dp[1][k-2]);
            dp[1][k] = arr[1][k] + std::max(dp[0][k-1],dp[0][k-2]);
        }

        std::cout << std::max(dp[0][N-1],dp[1][N-1]) << "\n";
    }

    return 0;
}