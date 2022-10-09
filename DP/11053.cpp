#include <iostream>

int arr[1001];
int dp[1001];
int N;

int main(){
    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
    }

    int result = 1;

    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = i-1; j >= 1; j--){
            if(arr[i] > arr[j]){
                dp[i] = std::max(dp[i],dp[j] + 1);
            }
            result = std::max(result,dp[i]);
        }
    }

    std::cout << result << "\n";
    return 0;
}