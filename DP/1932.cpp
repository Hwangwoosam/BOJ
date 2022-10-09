#include <iostream>

int N;

int DP[501][501];

int main(){
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < i+1; j++){
            int num;
            std::cin >> num;
            DP[i][j] = num;
        }    
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            DP[i-1][j] += std::max(DP[i][j],DP[i][j+1]);
        }
    }

    std::cout << DP[0][0] << "\n";
    return 0;
}