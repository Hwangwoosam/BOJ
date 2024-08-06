#include <iostream>
#include <cstring>

using namespace std;

int dp[21][21][21];
int order[21];
int t;

int getMove(int idx, int d1, int d2){
    if(idx == t+1) return 0;

    if(dp[idx][d1][d2] != -1) return dp[idx][d1][d2];

    int next = order[idx];
    dp[idx][d1][d2] = min(abs(d1-next) + getMove(idx+1,next,d2), abs(d2-next) +  getMove(idx+1,d1,next));
    return dp[idx][d1][d2];
}

int main(){
    int n;
    cin >> n;

    int d1,d2;
    cin >> d1 >> d2;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> order[i];
    }

    memset(dp,-1,sizeof(dp));
    
    cout << getMove(1,d1,d2) << "\n";
    return 0;
}