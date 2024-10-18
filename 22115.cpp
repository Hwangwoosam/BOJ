#include <iostream>
#include <vector>

using namespace std;

#define MAX 1e9

vector<int> caffeine;

int dp[100001];

int main(){
    int n,k;
    cin >> n >> k;

    caffeine.resize(n,0);
    for(int i = 0; i < n; i++) cin >> caffeine[i];
    
    for(int i = 1; i <= 100000; i++) dp[i] = MAX;

    for(int i = 0; i < n; i++){
        for(int j = k; j >= caffeine[i]; j--){
            cout << j << " " << caffeine[i] << "\n";
            if(j-caffeine[i] >= 0){
                dp[j] = min(dp[j],dp[j-caffeine[i]] + 1);
            }
        }
    }

    if(dp[k] == MAX){
        cout << "-1\n";
    }else{
        cout << dp[k] << "\n";
    }
    return 0;
}