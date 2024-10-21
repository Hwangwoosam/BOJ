#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

vector<int> weight; 
vector<int> path;
long long dp[1000002]; // 0: 1개씩,1: K개씩 이전꺼
bool check[1000002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,c;
    cin >> n >> k >> c;

    for(int i = 0; i < 1000001; i++) dp[i] = INT_MAX;
    
    for(int i = 1; i <= n; i++){
        int banana;
        cin >> banana;
        weight.push_back(banana);
    }
    //최소 시간
    dp[0] = 0;
    for(int i = 0; i < k-1; i++) dp[i+1] = dp[i] + weight[i];
    
    
    int lastIdx = 0;
    for(int i = k; i <= n; i++){
        if(dp[i-k] + c < dp[i-1] + weight[i-1]){
            check[i-k+1] = true;
            lastIdx = i-k+1;
        }

        dp[i] = min(dp[i-k] + c, dp[i-1] + weight[i-1]);
    }

    while(lastIdx > 0){
        if(check[lastIdx]){
            path.push_back(lastIdx);
            lastIdx -= k;
        }else{
            lastIdx --;
        }
    }

    reverse(path.begin(),path.end());

    cout << dp[n] << "\n";
    cout << path.size() << "\n";
    for(auto elem : path){
        cout << elem << " ";
    }
    cout << "\n";
    return 0;
}