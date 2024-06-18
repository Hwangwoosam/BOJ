#include <iostream>

using namespace std;

int n,answer = 0;
int map[1001][1001];
int dp[1001][1001];
int rdp[1002][1002];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + map[i][j];
        }
    }  

    for(int i = n; i > 0; i--){
        for(int j = n; j > 0; j--){
            rdp[i][j] = max(rdp[i+1][j],rdp[i][j+1]) + map[i][j];
        }
    }
    int col = 0, row = 0, maxVal = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(maxVal < rdp[i][j] + dp[i][j]){
                maxVal = rdp[i][j] + dp[i][j];
                row = i;
                col = j;
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "------------------\n";

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << rdp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    answer = dp[row][col] + rdp[row][col];

    cout << answer << "\n";
    return 0;
}