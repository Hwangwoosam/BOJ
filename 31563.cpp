#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n,q;
    cin >> n >> q;

    vector<long long> dp(n+1);

    for(int i = 1; i <= n; i++){
        cin >> dp[i];
        dp[i] += dp[i-1];
    }

    int idx = 0;

    for(int i = 0; i < q; i++){
        int cmd;
        cin >> cmd;

        if(cmd == 3){
            int a,b;
            cin >> a >> b;

            a = (a - 1 + idx) % n;
            b = (b - 1 + idx) % n;

            if( a <= b){
                cout << dp[b+1] - dp[a];
            }else{
                cout << (dp[n] - dp[a]) + (dp[b+1] - dp[0]);
            }
            cout << "\n";
        }else{
            int k;
            cin >> k;

            idx += ((cmd == 1) ? -k : k);
            idx = (idx + n) % n;
        }
    }
    return 0;
}