#include <iostream>
#include <vector>

using namespace std;

int k,n;
int worktime[10001][101],dp[10001][101],mvtime[101];
int Inf = 2e9;

int main(){
    cin >> k >> n;

    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= k; i++){
            cin >> worktime[i][j];
            dp[i][j] = Inf;
        }
        if(j == n){
            break;
        }
        cin >> mvtime[j];
    }

    for (int j = 1; j <= n; j++){
        
        int v= Inf;
        //find minimum Value
        for(int i = 1; i <= k; i++){
            v = min(v,dp[i][j-1]);
        }
        
        for(int i = 1; i <= k; i++){
            dp[i][j] = min(v+mvtime[j-1]+worktime[i][j],dp[i][j-1]+worktime[i][j]);
        }   
    }
    int answer = Inf;
    for (int i = 1; i <= k; i++){
        answer = min(answer,dp[i][n]);
    }

    cout << answer << "\n";


    return 0;
}