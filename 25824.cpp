#include <iostream>

using namespace std;

int map[13][13];
int dp[13];

// 1,2 3,4 5,6 7,8 9,10 11,12

int main(){
    for(int i = 1; i <= 12; i++){
        for(int j = 1; j <= 12; j++){
            cin >> map[i][j];
        }
    }

    //2가 먼저 선택된 경우 2->1
    dp[1] = map[2][1]; 
    //1이 먼저 선택된 경우 1->2
    dp[2] = map[1][2]; 

    for(int i = 3; i <= 11; i +=2){
        // i+1가 먼저 선택된 경우 i+1-> i
        dp[i] = min(dp[i-2]+map[i-2][i+1]+map[i+1][i], dp[i-1] + map[i-1][i+1] + map[i+1][i]);
        // i가 먼저 선택된 경우 i -> i+1
        dp[i+1] = min(dp[i-2] + map[i-2][i]+ map[i][i+1],dp[i-1] + map[i-1][i] + map[i][i+1]);
    }

    cout << min(dp[11],dp[12]) << "\n";
    //

    return 0;
}