#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> arr;
long long dp[101][101];
int n,k;

long findArr(int idx, int len){
    if(dp[idx][len] != -1) return dp[idx][len];

    long ret = 0;
    for(int i = idx+1; i < n; i++){
        if(arr[idx] < arr[i]) ret += findArr(i,len-1);
    }

    dp[idx][len] = ret;
    
    return dp[idx][len];
}

int main(){

    while(1){
        cin >> n >> k;

        memset(dp,-1,sizeof(dp));

        if(n == 0 && k == 0) break;

        arr.resize(n,0);

        for(int i = 0 ; i < n; i++) {
            cin >> arr[i];
            dp[i][1] = 1; // 수열 1개의 경우
        }

        long ans = 0;
        for(int i = 0; i < n; i++){
            ans += findArr(i,k);
        }

        cout << ans << "\n";
    }

    return 0;
}