#include <iostream>

using namespace std;

#define MOD 1000000007

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long long int n;
    cin >> n;

    long long int sum = 0, cnt = 1;

    for(long long int i = 1; i <= n; i++){
        sum = (sum + ((i*i) % MOD*(i+1))%MOD) % MOD;
    }

    for(int i =2; i <=n; i++){
        cnt = (((cnt*i) % MOD) * i) % MOD;
    }

    cout << sum << " " << cnt << "\n";

    return 0;
}