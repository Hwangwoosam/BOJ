#include <iostream>

int dp[1025][1025];
int N,M;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N >> M;

    int num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> num;
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + num;
        }
    }


    for(int i = 0; i < M; i++){
        int x1,y1,x2,y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << "\n";
    }
    return 0;
}