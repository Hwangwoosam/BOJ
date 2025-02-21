#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;


int d,p;
int dp[100001];
vector<pair<int,int>> pipe;

int main(){
    cin >> d >> p;

    for(int i = 0; i < p; i++){
        int l,c;
        cin >> l >> c;

        pipe.push_back({l,c});
    }

    sort(pipe.begin(),pipe.end());  
    dp[0] = INT_MAX;

    for(int i = 0; i < p; i++){
        for(int j = d; j >= pipe[i].first; j--){
            dp[j] = max(dp[j],min(dp[j-pipe[i].first],pipe[i].second));
        }
    }

    cout << dp[d] << "\n";

}