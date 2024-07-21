#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];
vector<int> value;

int main(){
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        value.push_back(v);
    }
    dp[0] = 1;

    int start = value.front();
    for(int i = 0; i < n; i++){
        for(int j = value[i]; j <= k; j++){
            dp[j] += dp[j- value[i]];
        }
    }

    cout << dp[k] << "\n";
    return 0;
}