#include <iostream>
#include <vector>

using namespace std;

string base[4] = {"","X","YZ","ZX"};
long long dp[101]; //x: 1 , y = 2 ,z = 3;
long long cnt[101][3];
long long ans = 0;

char findString(long long idx, int depth){
    if(depth <= 3){
        return base[depth][idx-1];
    }else if(dp[depth-3] >= idx){
        return findString(idx,depth-3);
    }else{
        return findString(idx-dp[depth-3], depth-2);
    }
}

int main(){
    
    int p,n;
    cin >> p >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    cnt[1][0] = 1;
    cnt[2][1] = 1;
    cnt[2][2] = 1;
    cnt[3][0] = 1;
    cnt[3][2] = 1;

    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-3] + dp[i-2];
        for(int j = 0; j < 3; j++) cnt[i][j] = cnt[i-3][j] + cnt[i-2][j];
    }

    if(p == 1){
        cout << dp[n] << "\n";
    }else if(p == 2){
        long long k;
        cin >> k;
        cout << findString(k,n) << "\n";
    
    }else if(p == 3){
        char c;
        cin >> c;
        cout << cnt[n][c-'X'] << "\n";
    }

    return 0;
}