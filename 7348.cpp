#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int dp[201];

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++){
            int from,to;
            cin >> from >> to;

            if(from > to){
                int tmp = from;
                from = to;
                to = tmp;
            }

            dp[(from-1)/2]++;
            dp[(to-1)/2 + 1]--;
        }

        int maxVal = 0;
        for(int i = 0; i < 200; i++){
            dp[i] += dp[i-1];
            if(dp[i] > maxVal) maxVal = dp[i];
        }
        
        cout << maxVal*10 << "\n";
    }   

    return 0;
}